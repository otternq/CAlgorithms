#include<stdlib.h>

void insertionSort(struct dyn_array *arr) {
    int j;
    int i;
    int key;

    for (j = 1; j < arr->length; j++) {

        key = arr->array[j];

        i = j - 1;

        while (i > 0 && arr->array[i] > key) {
            arr->array[i + 1] = arr->array[i];
            i = i - 1;
        }

        arr->array[i + 1] = key;
    }
}