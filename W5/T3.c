#include <stdio.h>
#include <stdlib.h>

int part1(){
    int sz_arr = 100;
    int* p_arr = malloc(sz_arr*sizeof(int));
    p_arr[50] = 1;
    for (int i=0; i<=sz_arr ; i++){
        printf("%d",p_arr[i]);
    }
    printf("\n");
    free(p_arr);
    printf("50th after freeing: %d\n",p_arr[50]);
    printf("After freeing the program runs, and the values remain, but the values are marked as 'free'\nValgrind: All heap blocks were freed -- no leaks are possible\n");
    // The program runs, and the values remain, but the values are marked as 'free'
    // Valgrind: All heap blocks were freed -- no leaks are possible

    printf("Now running 'free(&p_arr[50]);' is not possible, as the pointer type is incompatible (this address is in heap memory?)\nOutput would be:\nfree(): invalid pointer\nAborted (core dumped)\n");
    //free(&p_arr[50]); // This is not possible, as the pointer type is incompatible (this address is in heap memory?)
    printf("\n");
    return 0;
}

int* init_vector(int vals[],int sz_arr){
    //int sz_arr = (int) sizeof(vals)/sizeof(int);
    int* p_vec = malloc(sz_arr * sizeof(int));
    for (int i=0 ; i<sz_arr;i++){
        p_vec[i] = vals[i];
    }
    return p_vec;
}

void append_element(int* vector, int vec_sz, int el){
    vector = realloc(vector,(vec_sz+1)*sizeof(int));
    vector[vec_sz] = el;
}

void disp_vector(int* vec,int sz){
    for (int i=0; i<sz; i++){
        printf("%d",vec[i]);
    }
    printf("\n");
}

int part2(){
    printf("Creating a vector with malloc, and appending values to it with realloc.\n");
    int arr[] = {1,2,3,4};
    int* vec = init_vector(arr,4);
    int sz_arr = 4;
    printf("After initialization: ");
    disp_vector(vec,sz_arr);
    append_element(vec,sz_arr,9);
    sz_arr++;
    printf("Added 9: ");
    disp_vector(vec,sz_arr);
    append_element(vec,sz_arr,9);
    sz_arr++;
    printf("Added 9: ");
    disp_vector(vec,sz_arr);
    append_element(vec,sz_arr,9);
    sz_arr++;
    printf("Added 9: ");
    disp_vector(vec,sz_arr);
    free(vec);
    printf("This implementation is not really useful, as it is slow to realloc each time a value is added.\n");
    printf("Instead, most C implementations of dynamic arrays / vectors double the capacity of the vector with realloc, when capacity is exceeded.\n");
    printf("Linked lists and dynamic arrays serve different purposes, to summarize:\n");
    printf("Linked lists provide O(1) insertion and deletion, due to the linked structure, but O(n) when referencing, due to traversing the list.\n");
    printf("Vectors on the other hand provide O(1) referencing, due to contiguous blocks of memory, but O(n) insertion and deletion, due to copying and allocating memory.\n");
    return 0;
}


int main(){
    printf("Part 1: \n");
    part1();
    printf("Part 2: \n");
    part2();

}