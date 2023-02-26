#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

int grep_file(char *search, char *filename);

/*My own implementation of a simple unix grep command.*/

int main(int argc, char *argv[])
{
    // Check if no arguments are given
    if (argc == 1) {
        printf("my-grep: searchterm [file ...]\n");
        return 0;
    }
    int nfiles = argc - 2;
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
            strcpy(files[i], argv[i + 2]);
            //files[i] = argv[i + 2];
        }
    }
    char* curr_file_name;
    int found = 0;
    int fno = 0;
    int read_file_status;
    char* pattern = argv[1];
    if (strlen(pattern) > 255) {
        printf("my-grep: searchterm too long\n");
        return 1;
    }
    printf("Searching for '%s' in %d files: \n", pattern, nfiles);
    for(int i = 0; i < nfiles; i++){
        printf("%s ", files[i]);
    }
    printf("\n");
    while (fno < nfiles) {
        curr_file_name = files[fno];
        read_file_status = grep_file(pattern, curr_file_name);
        if (read_file_status == -1) {
            return 1;
        }
        else if (read_file_status > 0) {
            found = found + read_file_status;
        }
        fno++;
    }
    printf("Found %d matches\n", found);
}

int grep_file(char *search, char *filename)
{
    FILE *fp;
    // If stdin is used, use stdin
    if (strcmp(filename, "stdin") == 0) {
        fp = stdin;
    }
    else{
        fp = fopen(filename, "r");
    }
    if (fp == NULL) {
        printf("my-grep: cannot open file\n");
        return -1;
    }

    // Create variables for getline
    char *linebuf;
    size_t linebuf_size = 256;
    int line_size;
    int found = 0;

    linebuf = (char*)malloc(linebuf_size * sizeof(char));
    if (linebuf == NULL) {
        perror("my-grep: cannot allocate memory\n");
        return -1;
    }
    // Read line by line with getline
    while ((line_size = getline(&linebuf, &linebuf_size, fp)) != -1) {
        if (strstr(linebuf, search) != NULL) {
            printf("%s", linebuf);
            found++;
        }
    }
    free(linebuf);
    fclose(fp);
    return found;
}