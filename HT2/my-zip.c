#include <stdio.h>


int main(int argc, char *argv[])
{
    // Do Run-legth encoding for the input file and print the result to stdout

    if (argc != 2) {
        printf("Usage: my-zip <file>\n");
        return 1;
    }
    char* input_file_name = argv[1];

    FILE *fp;
    fp = fopen(input_file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s", input_file_name);
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
    return 0;
}