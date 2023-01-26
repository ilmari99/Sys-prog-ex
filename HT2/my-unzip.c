#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Read the input file, which is a run-length encoded file, and print the result to stdout
    // We assume integers are the run lenghts and chars are the characters to be repeated

    if (argc != 2) {
        printf("Usage: my-unzip <file>\n");
        return 1;
    }
    char* input_file_name = argv[1];

    FILE *fp;
    fp = fopen(input_file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s", input_file_name);
        return 1;
    }
    int run_length;
    char curr_char;
    int reached_eof = -1;
    // Read 4 bytes at a time, which is the size of the run length
    while((fread(&run_length, 4, 1, fp)) != 0){
        //printf("Read: %s\n", as_str);
        reached_eof = fread(&curr_char, 1, 1, fp);
        //printf("Read chunk: %d%c\n", run_length, curr_char);
        //fwrite(&curr_char, 1, 1, stdout);
        // Print the character run_length times
        for (int i = 0; i < run_length; i++){
            printf("%c", curr_char);
        }//*/

        if (reached_eof == 0){
            break;
        }
    }
}