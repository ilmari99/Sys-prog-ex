#include <stdio.h>

/*My own implementation of a simple unix cat command.*/

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;

    if (argc == 1) {
        return 0;
    }
    int fno = 1;
    while (fno < argc) {
        fp = fopen(argv[fno], "r");
        if (fp == NULL) {
            printf("my-cat: cannot open file\n");
            return 1;
        }
        while ((c = getc(fp)) != EOF) {
            putchar(c);
        }
        fclose(fp);
        fno++;
    }
}
