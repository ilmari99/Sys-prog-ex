#include <stdio.h>
#include <string.h>

int zip_file(char *filename);

int main(int argc, char *argv[])
{
    // Do Run-length encoding for the input file and print the result to stdout

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
        exit_status = zip_file(files[i]);
        if (exit_status == 1){
            return exit_status;
        }
    }
}

int zip_file(char* filename){
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s", filename);
        return 1;
    }
    char curr_char;
    int count = 0;
    char rle_char;
    /*printf("Size of int: %ld\n", sizeof(int));
    printf("Size of char: %ld\n", sizeof(char));
    printf("curr_char: %c\n", curr_char);
    printf("rle_char: %c\n", rle_char);*/
    //fseek(fp, 0, SEEK_SET);
    while((curr_char = fgetc(fp)) != EOF){
        // If the rle_char is not set, set it to the current char
        if (count == 0){
            rle_char = curr_char;
            count++;
        }
        // If the current char is the same as the rle_char, increase the count
        else if (rle_char == curr_char){
            count++;
        }
        // If the current char is different from the rle_char, print the rle_char and count
        else{
            fwrite(&count, 4, 1, stdout);
            fwrite(&rle_char, 1, 1, stdout);
            //printf("%d%c", count, rle_char);
            rle_char = curr_char;
            count = 1;
        }
    }
    // Print the last rle_char and count
    fwrite(&count, 4, 1, stdout);
    fwrite(&rle_char, 1, 1, stdout);
    //fwrite(as_str, 5, 1, stdout);
    fclose(fp);
    return 0;
}