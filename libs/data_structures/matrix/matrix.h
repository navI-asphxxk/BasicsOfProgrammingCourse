#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct matrixf {
    double **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
} matrixf;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

// размещает в динамической памяти массив из
// nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m);

// освобождает память, выделенную под хранение массива ms
// из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

// ввод матрицы m
void inputMatrix(matrix m);

// ввод массива из nMatrices матриц,
// хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// вывод матрицы m
void outputMatrix(matrix m);

// вывод массива из nMatrices матриц,
// хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

// обмен строк с порядковыми
// номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

// обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

// обмен значений двух переменных a, b
void swap(int *a, int *b);

// транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m);

// возвращает значение ’истина’, если
// матрица m является квадратной,
// ложь – в противном случае
bool isSquareMatrix(matrix m);

// возвращает значение ’истина’,
// если матрицы m1 и m2 равны,
// ложь – в противном случае
bool areTwoMatricesEqual(matrix m1, matrix m2);

// возвращает значение ’истина’, если матрица m
// является единичной,
// ложь – в противном случае
bool isEMatrix(matrix m);

// возвращает значение ’истина’, если
// матрица m является симметричной,
// ложь – в противном случае
bool isSymmetricMatrix(matrix m);

// возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

// возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

// возвращает матрицу, размера nRows на nCols,
// построенного из элементов массива a,
// размещенную в динамической памяти
matrix createMatrixFromArray(const int *a, int nRows,
                             int nCols);

// возвращает указатель на нулевую матрицу массива
// из nMatrices матриц, размещенных
//в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices,
                                      size_t nRows, size_t nCols);

// выполняет сортировку вставками строк
// матрицы m по неубыванию значения
// функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int*, int));

// выполняет сортировку вставками столбцов матрицы m
// по неубыванию значения функции criteria применяемой
// для столбцов
void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int*, int));

matrixf createMatrixFromArrayF(const double *a,
                               int nRows, int nCols);

matrixf *createArrayOfMatrixFromArrayF(const double *values,
                                       int nMatrices, int nRows, int nCols);

matrixf getMemMatrixF(int nRows, int nCols);

matrixf *getMemArrayOfMatricesF(int nMatrices,
                                int nRows, int nCols);

void outputMatrixF(matrixf m);

void freeMemMatrixF(matrix *m);

#endif
