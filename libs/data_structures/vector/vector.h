#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <assert.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение
// newCapacity элементов вектора v
// Если ОС не смогла выделить необходимый фрагмент памяти, то
// вывод соответствующего сообщения
// Если в качестве newCapacity указано значение 0, в v->data
// записывает NULL
// Если значение newCapacity стало меньше v->size, тогда значение v->size
// равняется newCapacity.
void reserve(vector *v, size_t newCapacity);

// удаляет элементы вектора v, без освобождения память
void clear(vector *v);

// освобождает память, выделенную под
// неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору v
void deleteVector(vector *v);

// возвращает значение True, если вектор пустой
// иначе - False
bool isEmpty(vector *v);

// возвращает значение True, если вектор полный
// иначе - False
bool isFull(vector *v);

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора v
// если вектор пуст - Вывод ошибки
void popBack(vector *v);

// возвращает указатель на
// index-ый элемент вектора v
int *atVector(vector *v, size_t index);

// возвращает указатель на последний элемент вектора v
int *back(vector *v);

// возвращает указатель на нулевой элемент вектора v
int *front(vector *v);

// возвращает значение True, если векторы v1 и v2 равны
bool vector_isEqual(vector *v1, vector *v2);

#endif
