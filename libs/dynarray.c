#include<stdlib.h>
#include<stdio.h>

typedef struct dyn_array{
    int length;
    int * array;
} dyn_array;

dyn_array * initDynArray(int size) {
    struct dyn_array *p = (struct dyn_array *) malloc(sizeof(struct dyn_array));

    p->length = size;
    (*p).array = (int*) malloc(size*sizeof(int));

    return p;
}

void printDynArray(struct dyn_array *arr) {
    int i = 0;
    for (i = 0; i < arr->length; i++) {
        printf("%i\n", arr->array[i]);
    }
}