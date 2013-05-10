#include<stdlib.h>
#include<stdio.h>

#include "../libs/dynarray.h"
#include "../sort/insertionSort.h"

int main() {

    dyn_array * zeroToNine = initDynArray(10);

    int toBeSorted[] = {0,9,1,8,2,7,3,6,4,5};
    int afterSorted[] = {0,1,2,3,4,5,6,7,8,9};

    int i = 0;

    (*zeroToNine).array = &toBeSorted[0];

    insertionSort(zeroToNine);

    for (i = 0; i < 10; i++) {
        if (zeroToNine->array[i] != afterSorted[i]) {
            printf("%s\n", "Test Failed");
            return EXIT_FAILURE;
        }
    }

    printf("%s\n", "Test Succeded");
    return EXIT_SUCCESS;

}