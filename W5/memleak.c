#include <stdio.h>
#include <stdlib.h>
int main(){
    int sz_arr = 100;
    int* p_arr = malloc(sz_arr*sizeof(int));
    p_arr[100] = 1;
    for (int i=0; i<sz_arr ; i++){
        printf("%d",p_arr[i]);
    }
    printf("\n");
}

// No leaks found with gdb, I suppose it would be possible though

/* With valgrind: 
LEAK SUMMARY:
==24114==    definitely lost: 400 bytes in 1 blocks
==24114==    indirectly lost: 0 bytes in 0 blocks
==24114==      possibly lost: 0 bytes in 0 blocks
==24114==    still reachable: 0 bytes in 0 blocks
==24114==         suppressed: 0 bytes in 0 blocks
*/

/* The program isn't correct, since the array has 100 elements, hence the last element has index 99, but we are setting a value at index 100.
The value is set, but it is not safe and doesn't actually belong to the array.
*/
