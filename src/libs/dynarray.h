#include<stdlib.h>

/**
 * A structured array that holds the arrays length with the array
 */
typedef struct dyn_array{
    int length;
    int * array;
} dyn_array;

dyn_array * initDynArray(int size);
void printDynArray(struct dyn_array *arr);