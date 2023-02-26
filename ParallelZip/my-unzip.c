#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int unzip_file(char *filename);


int main(int argc, char *argv[])
{
    // Read the input file, which is a run-length encoded file, and print the result to stdout
    // We assume integers are the run lenghts and chars are the characters to be repeated

    if (argc == 1) {
        printf("my-unzip: file1 [file2 ...]\n");
        return 1;
    }
    int nfiles = argc - 1;
    char files[20][200];
    // If no files are specified, use stdin
    if (nfiles == 0) {
        printf("Using stdin.\n");
        strcpy(files[0], "stdin");
        nfiles = 1;
    }

    // If files are specified, use them
    else{
        for (int i = 0; i < nfiles; i++) {
            strcpy(files[i], argv[i + 1]);
            //files[i] = argv[i + 2];
        }
    }
    int exit_status;
    for (int i = 0; i < nfiles; i++){
        exit_status = unzip_file(files[i]);
        if (exit_status == 1){
            return exit_status;
        }
    }
}

int unzip_file(char* filepath){
    FILE *fp;
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening file %s", filepath);
        return 1;
    }
    int run_length;
    char curr_char;
    int reached_eof = -1;
    // Read 4 bytes at a time, which is the size of the run length
    while((fread(&run_length, 4, 1, fp)) != 0){
        reached_eof = fread(&curr_char, 1, 1, fp);
        // Print the character run_length times
        for (int i = 0; i < run_length; i++){
            printf("%c", curr_char);
        }//*/

        if (reached_eof == 0){
            break;
        }
    }
    fclose(fp);
    return 0;
}