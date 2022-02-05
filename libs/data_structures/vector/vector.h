#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <assert.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение
// newCapacity элементов вектора v
void reserve(vector *v, size_t newCapacity);

// удаляет элементы вектора v, но не освобождает память
void clear(vector *v);

// освобождает память, выделенную под
// неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору v
void deleteVector(vector *v)

//


#endif
