#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>

void* zip_segment(void* arg);
int zip_file(char* filename, int num_threads, int num_segments);

typedef struct {
    char* filename;
    char* tmpfile;
    int start;
    int end;
} ThreadArgs;

// Define the structure for the queue
typedef struct {
    ThreadArgs* elements;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

pthread_mutex_t queue_mutex;
Queue* job_queue = NULL;

// Function to create a new queue
Queue* create_queue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->elements = (ThreadArgs*) malloc(capacity * sizeof(ThreadArgs));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to add an element to the queue
void add_to_queue(Queue* queue, ThreadArgs element) {
    if (queue->size == queue->capacity) {
        printf("Queue is full. Unable to add element.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = element;
    queue->size++;
}

// Function to remove and return the front element from the queue
ThreadArgs pop_from_queue(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty. Unable to remove element.\n");
        ThreadArgs null_element = {NULL, NULL, 0, 0};
        return null_element;
    }
    ThreadArgs popped_element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return popped_element;
}

void free_queue(Queue* queue) {
    free(queue->elements);
    free(queue);
}


void* zip_segment(void* arg) {
    /* A function, that takes in a ThreadArgs struct and writes the RLE of the text in it to the ThreadArgs tmpfile. */
    ThreadArgs* args = (ThreadArgs*) arg;
    char* filename = args->filename;
    char* tmpfile = args->tmpfile;
    int start = args->start;
    int end = args->end;
    
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s", filename);
        return NULL;
    }

    FILE* fpout = fopen(tmpfile, "w");
    if (fpout == NULL) {
        printf("Error opening file %s", tmpfile);
        return NULL;
    }
    
    fseek(fp, start, SEEK_SET);

    char curr_char;
    int count = 0;
    char rle_char;

    while (ftell(fp) < end && (curr_char = fgetc(fp)) != EOF) {
        if (count == 0) {
            rle_char = curr_char;
            count++;
        } else if (rle_char == curr_char) {
            count++;
        } else {
            fwrite(&count, 4, 1, fpout);
            fwrite(&rle_char, 1, 1, fpout);
            rle_char = curr_char;
            count = 1;
        }
    }

    if (count > 0) {
        fwrite(&count, 4, 1, fpout);
        fwrite(&rle_char, 1, 1, fpout);
    }

    fclose(fp);
    fclose(fpout);
    //printf("Finished thread %s\n", tmpfile);
    return NULL;
}

void* worker() {
    /* This function is the target of a thread. It picks a ThreadArgs from a queue until there are no more jobs. */
    while (1) {
        // Lock the mutex
        pthread_mutex_lock(&queue_mutex);
        // If there are no jobs, unlock the mutex and exit
        if (job_queue->size == 0) {
            pthread_mutex_unlock(&queue_mutex);
            return NULL;
        }
        // Pop the first job from the queue
        ThreadArgs job = pop_from_queue(job_queue);
        
        //printf("Doing job %s on thread %d\n", job.tmpfile, (int) pthread_self());
        // Unlock the mutex
        pthread_mutex_unlock(&queue_mutex);
        // Run the job
        zip_segment(&job);

    }
}

int zip_file(char* filename, int num_threads, int num_segments) {
    /* Takes in a file, number fo threads to use for RLE and total number of segments.
    num_threads are created and each thread is assigned a segment until all segments are assigned.
    The results are written to temporary files, which are then merged into the final output.
    */
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s", filename);
        return 1;
    }

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fclose(fp);

    // Divide the file into segments
    int segment_size = file_size / num_segments;
    // Create the queue
    job_queue = create_queue(num_segments);

    // Create the arguments for each thread
    char tmpfiles[num_segments][100];
    mkdir("./tmp-pzip", 0777);
    for (int i = 0; i < num_segments; i++) {
        ThreadArgs thread_args;
        thread_args.filename = filename;
        thread_args.start = i * segment_size;
        // The end is either at (i + 1) * segment_size or the end of the file if it's the last segment
        thread_args.end = (i == num_segments - 1) ? file_size : (i + 1) * segment_size;
        sprintf(tmpfiles[i], "./tmp-pzip/tmpfile%d", i);
        thread_args.tmpfile = tmpfiles[i];
        add_to_queue(job_queue, thread_args);
    }

    // Allocate the threads
    pthread_t* threads = (pthread_t*) malloc(num_threads * sizeof(pthread_t));

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
        pthread_detach(threads[i]);
    }

    // Merge the temporary files in order
    int file_index = 0;
    while(file_index < num_segments){
        if (access(tmpfiles[file_index], F_OK) == -1) {
            usleep(10000);
            continue;
        }
        //printf("Merging file %s\n", tmpfiles[file_index]);
        FILE* fpin = fopen(tmpfiles[file_index], "r");
        if (fpin == NULL) {
            printf("Error opening file %s", tmpfiles[file_index]);
            return 1;
        }
        int count;
        char rle_char;
        while (fread(&count, 4, 1, fpin) > 0) {
            fread(&rle_char, 1, 1, fpin);
            fwrite(&count, 4, 1, stdout);
            fwrite(&rle_char, 1, 1, stdout);
        }
        fclose(fpin);
        remove(tmpfiles[file_index]);
        file_index++;
        
    }

    /* Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }*/


    free_queue(job_queue);
    free(threads);
    //fclose(fp);
    remove("./tmp-pzip");
    return 0;
}

int main(int argc, char *argv[])
{
    /* Main function accepts two optional variables and any number of files to zip with RLE*/
    // Do Run-length encoding for the input file and print the result to stdout
    if (argc == 1) {
        printf("pzip: -t N -s M file1 [file2 ...]\n");
        return 1;
    }
    int num_threads = -1;
    int num_segments = -1;
    // If the first argument is -t, get the number of threads
    if (strcmp(argv[1], "-t") == 0) {
        num_threads = atoi(argv[2]);
    }
    // If the second argument is -s, get the number of segments
    if (strcmp(argv[3], "-s") == 0) {
        num_segments = atoi(argv[4]);
    }
    // Check if number of threads and segments were given, and adjust the number of files accordingly
    int reduce_from_nfiles = 0;
    if (num_threads != -1){
        reduce_from_nfiles = 2;
    }
    if (num_segments != -1){
        reduce_from_nfiles = 4;
    }

    int nfiles = argc - 1 - reduce_from_nfiles;
    // If the number of threads or segments is not specified, use the default values
    if (num_threads == -1) {
        num_threads = get_nprocs();
    }
    if (num_segments == -1) {
        num_segments = num_threads;
    }
    //printf("Using %d threads and %d segments\n", num_threads, num_segments);
    char files[20][200];
    // If no files are specified, use stdin
    if (nfiles == 0) {
        strcpy(files[0], "stdin");
        nfiles = 1;
    }

    // If files are specified, use them
    else{
        for (int i = 0; i < nfiles; i++) {
            strcpy(files[i], argv[i + 1 + reduce_from_nfiles]);
            //files[i] = argv[i + 2];
        }
    }
    pthread_mutex_init(&queue_mutex, NULL);
    int exit_status;
    for (int i = 0; i < nfiles; i++){
        exit_status = zip_file(files[i],num_threads,num_segments);
        if (exit_status == 1){
            return exit_status;
        }
    }
    pthread_mutex_destroy(&queue_mutex);
}