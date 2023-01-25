#include <stdio.h>
#include <string.h>

/*My own implementation of a simple unix grep command.*/

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1) {
        return 0;
    }
    char *search = argv[1];
    char *linebuf = NULL;
    size_t linebuf_size = 0;
    ssize_t line_size;
    int found = 0;
    int fno = 2;
    while (fno < argc - 1) {
        fp = fopen(argv[fno], "r");
        if (fp == NULL) {
            printf("my-grep: cannot open file\n");
            return 1;
        }
        // Read each line of the file and print it if it contains the search string.
        // The search string is the 1st argument.
        // Lines can be arbitrarily long.

        while ((line_size = getline(&linebuf, &linebuf_size, fp)) != -1) {
            if (strstr(linebuf, search) != NULL) {
                printf("%s", linebuf);
                found++;
            }
            printf("%s", linebuf);
        }
    }
}