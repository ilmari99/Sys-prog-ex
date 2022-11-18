#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void check_inputs(int argc, char *argv[]){
    if (argc == 1){
        fprintf(stderr, "No file specified.\n");
        exit(1);
    }
    else if (argc > 3)
    {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    else if (argv[1] == argv[2]){
        fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }
}

FILE* open_file(char* file_name, char* mode){
    FILE* fptr = fopen(file_name,mode);
    if (fptr == NULL){
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    return fptr;
}

signed long int find_line_start_from_current(FILE* fptr){
    /* Return the offset from the current position of fptr,
    to the start of a line.
    fptr should point to a newline character.
    This then finds the number of bytes to move, to get to the next character after previous line change.
    */
   char ch;
   ch = fgetc(fptr);
   fseek(fptr,-sizeof(char),SEEK_CUR);
   int ch_count = 1;
   while (ch != '\n' && ftell(fptr) > 0){
    // Goto previous character
    fseek(fptr,-sizeof(char),SEEK_CUR);
    //fprintf(stdout,"%c",ch);

    // Get next char without moving pointer
    ch = fgetc(fptr);
    fseek(fptr,-sizeof(char),SEEK_CUR);

    ch_count++;
   }

   // Return the filepointer to the starting position
   fseek(fptr,ch_count * sizeof(char),SEEK_CUR);
   // Return the offset from the initial position, up to the character before previous new line
   return -(ch_count) * sizeof(char);
}

void print_from_pos(FILE* fin, FILE* fout, long signed int start_offset){
    /* Given a file pointer, and start offset, prints characters starting from ftell(fptr) + start_offset*/
    long off_set = 0;
    char ch;
    fseek(fin,start_offset,SEEK_CUR);
    //printf("\n%li characters in line.\n",start_offset/sizeof(char));
    //printf("\n%li bytes.\n",start_offset);
    /*
    ch = fgetc(fin);
    fseek(fin,-sizeof(char),SEEK_CUR);
    printf("First character of line: %c\n",ch);
    */
    //fprintf(fout,"Starting loop\n");
    while (off_set < -start_offset){
	//fprintf(fout,"\nOffset: %li\n",off_set);
        //fseek(fin,off_set,SEEK_CUR);
        ch = fgetc(fin);
	if (ch == '\0' || ch == EOF){
		break;
	}
        if (off_set == 0 && ch != '\n'){
		fprintf(fout,"\n");
	}
        //fseek(fin,-sizeof(char),SEEK_CUR);
        fprintf(fout,"%c",ch);
	fflush(fout);
	//printf("%c",ch);
        off_set = off_set + sizeof(char);
        //printf("\n%li offset.\n",off_set);
    }
    //fseek(fin,-start_offset - sizeof(char),SEEK_CUR);
}

int main(int argc, char *argv[]){
    check_inputs(argc,argv);
    //fprintf(stdout,"Program started\n");
    FILE* in_fptr = open_file(argv[1],"r");
    // If no file specified, print to stdout
    FILE* out_fptr = stdout;
    if (argc == 3){
        out_fptr = open_file(argv[2],"w");
    }
    setbuf(out_fptr,NULL);
    //printf("Initial ftell: %d",ftell(in_fptr));
    // Seek initial end of file
    fseek(in_fptr,0,SEEK_END);
    int nchars = ftell(in_fptr)/sizeof(char);
    //printf("%li characters in the file\n\n",ftell(in_fptr)/sizeof(char));
    long signed int l_start_offset = 0;
    int written_chars = 0;
    while ( ftell(in_fptr) > 0 && written_chars < nchars ){
        //printf("Current pos in main: %li\n", ftell(in_fptr));
        // Find the offset from current position, that starts the new line
        l_start_offset = find_line_start_from_current(in_fptr);
	written_chars = written_chars - l_start_offset/sizeof(char);
        //fprintf(out_fptr,"L start offset: %li",l_start_offset);
        // Print from curr_pos - offset to curr_pos
        print_from_pos(in_fptr,out_fptr,l_start_offset);
	//printf("Written chars: %d",written_chars);
        // Seek a newline character, should be the character before current pos
        fseek(in_fptr,l_start_offset - sizeof(char),SEEK_CUR);

        //sleep(0.1);
    }
    fclose(in_fptr);
    fclose(out_fptr);
    return 0;
}
