#ifndef SORTING_METHODS_H
#define SORTING_METHODS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct sorting_methods{
    void (*buble_sort) (int* vet, int tam);
    void (*buble_sort_improved) (int* vet, int tam);
    void (*selection_recursive) (int* vet, int tam);
    void (*selection_iterative) (int* vet, int tam);
    void (*insertion_sort) (int* vet, int tam);
    void (*shell_sort) (int* vet, int tam);
    void (*quick_sort) (int* vet, int tam);
    void (*merge_sort) (int* vet, int tam);
    void (*heap_sort) (int* vet, int tam);
    void (*counting_sort) (int* vet, int tam);
    void (*radix_sort) (int* vet, int tam);
}SortingMethods;

SortingMethods sortingMethods();

#endif