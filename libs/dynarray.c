#include<stdlib.h>
#include<stdio.h>

/**
 * A structured array that holds the arrays length with the array
 */
typedef struct dyn_array{
    int length;
    int * array;
} dyn_array;

/**
 * Creates a custom aray of a specific size
 * @param  size The size of the array
 * @return      a dynamically initialized array
 */
dyn_array * initDynArray(int size) {
    struct dyn_array *p = (struct dyn_array *) malloc(sizeof(struct dyn_array));

    p->length = size;
    (*p).array = (int*) malloc(size*sizeof(int));

    return p;
}

/**
 * Prints out each integer in the array
 * @param arr the dynamic array
 */
void printDynArray(struct dyn_array *arr) {
    int i = 0;
    for (i = 0; i < arr->length; i++) {
        printf("%i\n", arr->array[i]);
    }
}