#ifndef TEST_DATABASE_H
#define TEST_DATABASE_H

#define SIZE_VECTOR_TEST 1000000
#define MAX_RANGE 1000

typedef struct test_database {
    int * (*create_test) ();
}TestDatabase;

TestDatabase testDatabase();
#endif