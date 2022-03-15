#ifndef MAIN_C_SORTS_H
#define MAIN_C_SORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../../algorithms/algorithm.h"

void generateRandomArray(int *a, size_t size);

void generateOrderedArray(int *a, size_t size);

void generateOrderedBackwards(int *a, size_t size);

void generateRandomArray(int *a, size_t size);

void generateOrderedArray(int *a, size_t size);

void generateOrderedBackwards(int *a, size_t size);

void bubbleSort(int *a, size_t size);

void selectionSort(int *a, size_t size);

void insertionSort(int *a, size_t size);

void combSort(int *a, const size_t size);

void shellSort(int *a, size_t size);

int digit(int n, int k, int N, int M);

void _radixSort(int *l, int *r, int N);

void radixSort(int *a, size_t n);

void merge(const int *a, const size_t n,
           const int *b, const size_t m, int *c);

void mergeSort_(int *source, size_t l, size_t r, int *buffer);

void mergeSort(int *a, size_t n);

void qsort_(int *array, size_t n);

#endif
