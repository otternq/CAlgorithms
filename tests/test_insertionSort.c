#include<stdlib.h>
#include<stdio.h>

#include "../src/libs/dynarray.h"
#include "../src/sort/insertionSort.h"

#include "CUnit/Basic.h"

void testInsertionSortWork() {

    dyn_array * zeroToNine = initDynArray(10);

    int toBeSorted[] = {0,9,1,8,2,7,3,6,4,5};
    int afterSorted[] = {0,1,2,3,4,5,6,7,8,9};

    int i = 0;

    (*zeroToNine).array = &toBeSorted[0];

    //sort the array
    insertionSort(zeroToNine);

    for (i = 0; i < 10; i++) {
        CU_ASSERT(zeroToNine->array[i] == afterSorted[i]);
    }

    printf("%s\n", "Test Succeded");

}

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}


/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test that insertion sort is working", testInsertionSortWork)) )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}