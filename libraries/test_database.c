#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test_database.h"

int * create_test(){
    long int i;
    srandom(time(NULL));
    int * vector = (int*) malloc (SIZE_VECTOR_TEST * sizeof(int));
    for(i = 0; i < SIZE_VECTOR_TEST; i++){
        vector[i] = random() % MAX_RANGE;
    }
    return vector;
}


/**
 * method constructor
 *
 * @returns a new Test Dabase
 */
TestDatabase testDatabase(){
    TestDatabase new_test_db;
    new_test_db.create_test = &create_test;    
    return new_test_db;
}