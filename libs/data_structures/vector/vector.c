#include "vector.h"
#include <stdio.h>
#include <malloc.h>


vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
    } else if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        v->size--;
}