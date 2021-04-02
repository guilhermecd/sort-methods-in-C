#include <time.h>
#include <stdlib.h>
#include "libraries/sorting_methods.h"
#include "libraries/test_database.h"

void print_vector(int* vector, int size){
    int i;
    printf("\n");
    for(i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main(){
    TestDatabase testDB = testDatabase();
    SortingMethods sortMethods = sortingMethods();
    int* v = testDB.create_test();
    print_vector(v, 5);
    sortMethods.quick_sort(v, 5);
    print_vector(v, 5);
    free(v);
    return 0;
}