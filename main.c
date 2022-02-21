#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/array/array.h"

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

// getMemMatrix

void test_getMemMatrix_zeroRowsAndCols() {
    matrix m = getMemMatrix(0, 0);
    assert(m.nRows == 0 && m.nCols == 0 && m.values != NULL);
    freeMemMatrix(&m);
}

void test_getMemMatrix_rowsAndCols() {
    matrix m = getMemMatrix(3, 2);
    assert(m.nRows == 3 && m.nCols == 2 && m.values != NULL);
    freeMemMatrix(&m);
}

void test_getMemMatrix() {
    test_getMemMatrix_zeroRowsAndCols();
    test_getMemMatrix_rowsAndCols();
}

// getMemArrayOfMatrices

void test_getMemArrayOfMatrices_zeroRowsAndCols() {
    matrix *ms = getMemArrayOfMatrices(3, 0, 0);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 3);
}

void test_getMemArrayOfMatrices_rowsAndCols() {
    matrix *ms = getMemArrayOfMatrices(3, 2, 1);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 2 && ms[i].nCols == 1 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 3);
}

void test_getMemArrayOfMatrices() {
    test_getMemArrayOfMatrices_zeroRowsAndCols();
    test_getMemArrayOfMatrices_rowsAndCols();
}

// swapRows
void test_swapRows_oneRow() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 3},
                                      1, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {1, 2, 3},
                                      1, 3);
    swapRows(m1, 0, 0);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRows_twoRows() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 3,
                                               3, 2, 1},
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {3, 2, 1,
                                               1, 2, 3},
                                      2, 3);
    swapRows(m1, 0, 1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRows_manyRows() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {7, 8, 9,
                                               4, 5, 6,
                                               1, 2, 3},
                                      3, 3);
    swapRows(m1, 0, 2);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRows() {
    test_swapRows_oneRow();
    test_swapRows_twoRows();
    test_swapRows_manyRows();
}

// swapColumns

void test_swapColumns_oneColumn() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1,
                                               2,
                                               3},
                                      3, 1);
    matrix m2 = createMatrixFromArray((int[])
                                              {1,
                                               2,
                                               3},
                                      3, 1);
    swapColumns(m1, 0, 0);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns_twoColumns() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 4,
                                               2, 5,
                                               3, 6},
                                      3, 2);
    matrix m2 = createMatrixFromArray((int[])
                                              {4, 1,
                                               5, 2,
                                               6, 3},
                                      3, 2);
    swapColumns(m1, 0, 1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns_manyColumns() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 4, 7,
                                               2, 5, 8,
                                               3, 6, 9},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {7, 4, 1,
                                               8, 5, 2,
                                               9, 6, 3},
                                      3, 3);
    swapColumns(m1, 0, 2);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns() {
    test_swapColumns_oneColumn();
    test_swapColumns_twoColumns();
    test_swapColumns_manyColumns();
}

// insertionSortRowsMatrixByRowCriteria

void test_insertionSortRowsMatrixByRowCriteria_oneRow() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 3},
                                      1, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {1, 2, 3},
                                      1, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortRowsMatrixByRowCriteria_twoRows() {
    matrix m1 = createMatrixFromArray((int[])
                                              {3, 3, 3,
                                               2, 2, 2},
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {2, 2, 2,
                                               3, 3, 3},
                                      2, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortRowsMatrixByRowCriteria_manyRows() {
    matrix m1 = createMatrixFromArray((int[])
                                              {5, 1, 1,
                                               2, 2, 2,
                                               2, 2, 2},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {2, 2, 2,
                                               2, 2, 2,
                                               5, 1, 1},
                                      3, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_oneRow();
    test_insertionSortRowsMatrixByRowCriteria_twoRows();
    test_insertionSortRowsMatrixByRowCriteria_manyRows();
}

// insertionSortColsMatrixByColCriteria

void test_insertionSortColsMatrixByColCriteria_oneCol() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1,
                                               2,
                                               3},
                                      3, 1);
    matrix m2 = createMatrixFromArray((int[])
                                              {1,
                                               2,
                                               3},
                                      3, 1);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortColsMatrixByColCriteria_twoCols() {
    matrix m1 = createMatrixFromArray((int[])
                                              {3, 2,
                                               3, 2,
                                               3, 2},
                                      3, 2);
    matrix m2 = createMatrixFromArray((int[])
                                              {2, 3,
                                               2, 3,
                                               2, 3},
                                      3, 2);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortColsMatrixByColCriteria_manyCols() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 2,
                                               1, 2, 2,
                                               1, 2, 2},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {2, 2, 1,
                                               2, 2, 1,
                                               2, 2, 1},
                                      3, 3);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_oneCol();
    test_insertionSortColsMatrixByColCriteria_twoCols();
    test_insertionSortColsMatrixByColCriteria_manyCols();
}

// isSquareMatrix

void test_isSquareMatrix_squareM() {
    matrix m = createMatrixFromArray((int[])
                                             {1, 2, 2,
                                              3, 1, 2,
                                              3, 2, 1},
                                     3, 3);
    assert(isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix_notSquareM() {
    matrix m = createMatrixFromArray((int[])
                                             {1, 2, 1,
                                              2, 1, 2},
                                     2, 3);
    assert(!isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_squareM();
    test_isSquareMatrix_notSquareM();
}

// areTwoMatricesEqual

void test_areTwoMatricesEqual_equal() {
    matrix m1 = createMatrixFromArray((int[])
                                              {3, 2, 1,
                                               3, 2, 1,
                                               3, 2, 1},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {3, 2, 1,
                                               3, 2, 1,
                                               3, 2, 1},
                                      3, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_notEqual1() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 2,
                                               1, 2, 2,
                                               1, 2, 2},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {2, 2, 1,
                                               2, 2, 1,
                                               2, 2, 1},
                                      3, 3);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_notEqual2() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 2,
                                               1, 2, 2,
                                               1, 2, 2},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {2, 2, 1,
                                               2, 2, 1},
                                      2, 3);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual_equal();
    test_areTwoMatricesEqual_notEqual1();
    test_areTwoMatricesEqual_notEqual2();
}

// isEMatrix

void test_isEMatrix_identity() {
    matrix m = createMatrixFromArray((int[])
                                             {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1},
                                     3, 3);
    assert(isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_notIdentity() {
    matrix m = createMatrixFromArray((int[])
                                             {1, 0, 1,
                                              0, 1, 0,
                                              1, 0, 1},
                                     3, 3);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix() {
    test_isEMatrix_identity();
    test_isEMatrix_notIdentity();
}

// isSymmetricMatrix

void test_isSymmetricMatrix_symmetric() {
    matrix m = createMatrixFromArray((int[])
                                             {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1},
                                     3, 3);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix_notSymmetric() {
    matrix m = createMatrixFromArray((int[])
                                             {5, 4, 3,
                                              0, 5, 0,
                                              5, 4, 5},
                                     3, 3);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_symmetric();
    test_isSymmetricMatrix_notSymmetric();
}

// transposeSquareMatrix

void test_transposeSquareMatrix_oneRowAndCol() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1},
                                      1, 1);
    matrix m2 = createMatrixFromArray((int[])
                                              {1},
                                      1, 1);
    transposeSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeSquareMatrix_manyRowsAndCols() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 3,
                                               1, 2, 3,
                                               1, 2, 3},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {1, 1, 1,
                                               2, 2, 2,
                                               3, 3, 3},
                                      3, 3);
    transposeSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeSquareMatrix_twoTransposes() {
    matrix m1 = createMatrixFromArray((int[])
                                              {1, 2, 3,
                                               1, 2, 3,
                                               1, 2, 3},
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[])
                                              {1, 2, 3,
                                               1, 2, 3,
                                               1, 2, 3},
                                      3, 3);
    transposeSquareMatrix(m1);
    transposeSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_oneRowAndCol();
    test_transposeSquareMatrix_manyRowsAndCols();
    test_transposeSquareMatrix_twoTransposes();
}

// getMinValuePos

void test_getMinValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[])
                                             {1},
                                     1, 1);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMinValuePos_manyElements1() {
    matrix m = createMatrixFromArray((int[])
                                             {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMinValuePos_manyElements2() {
    matrix m = createMatrixFromArray((int[])
                                             {2, 2, 3,
                                              5, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 2 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMinValuePos() {
    test_getMinValuePos_oneElement();
    test_getMinValuePos_manyElements1();
    test_getMinValuePos_manyElements2();
}

// getMaxValuePos

void test_getMaxValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[])
                                             {5},
                                     1, 1);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMaxValuePos_manyElements1() {
    matrix m = createMatrixFromArray((int[])
                                             {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 2);
    freeMemMatrix(&m);
}

void test_getMaxValuePos_manyElements2() {
    matrix m = createMatrixFromArray((int[])
                                             {2, 2, 3,
                                              5, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 1 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_oneElement();
    test_getMaxValuePos_manyElements1();
    test_getMaxValuePos_manyElements2();
}

// createMatrixFromArray

void test_createMatrixFromArray_zeroRowsAndCols() {
    matrix m = createMatrixFromArray((int[])
                                             {},
                                     0, 0);
    assert(m.nRows == 0 && m.nCols == 0);
    freeMemMatrix(&m);
}

void test_createMatrixFromArray_manyRowsAndCols() {
    matrix m = createMatrixFromArray((int[])
                                             {2, 2, 3,
                                              5, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    assert(m.nRows == 3 && m.nCols == 3);
    freeMemMatrix(&m);
}

void test_createMatrixFromArray() {
    test_createMatrixFromArray_zeroRowsAndCols();
    test_createMatrixFromArray_manyRowsAndCols();

}

// createArrayOfMatrixFromArray
void test_createArrayOfMatrixFromArray_zeroRowsAndCols() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {},
                                              3, 0, 0);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0);
    freeMemMatrices(ms, 3);
}

void test_createArrayOfMatrixFromArray_manyRowsAndCols() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {},
                                              3, 2, 2);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 2 && ms[i].nCols == 2);
    freeMemMatrices(ms, 3);
}

void test_createArrayOfMatrixFromArray() {
    test_createArrayOfMatrixFromArray_zeroRowsAndCols();
    test_createArrayOfMatrixFromArray_manyRowsAndCols();
}

void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_isSquareMatrix();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    //test_insertionSortColsMatrixByColCriteria();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_createMatrixFromArray();
    test_createArrayOfMatrixFromArray();
}



// TASKS

// меняет местами строки, в которых находятся
// максимальный и минимальный элементы матрицы m
void swapRowsWithMinAndMaxElements(matrix m) {
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.colIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

// упорядочивает строки матрицы m по
// неубыванию наибольших элементов строк
void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

// Упорядочивает столбцы матрицы по неубыванию
// минимальных элементов столбцов
void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

// умножает матрицу m1, m2
matrix mulMatrices(matrix m1, matrix m2) {
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "cant mul ");
        exit(1);
    }
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            int element = 0;
            int curIndex = 0;
            for (int k = 0; k < m1.nCols; k++, curIndex++)
                element += m1.values[curIndex][k] * m2.values[k][curIndex];
            m.values[i][j] = element;
        }
    }
    return (matrix) m;
}

// заменяет матрицу m на ее квадрат, если матрица симметрична
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

// возвращает True, если массив а размера n
// уникальный, иначе - False
bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}

// Если среди сумм элементов строк матрицы m нет равных,
// то транспонировать матрицу
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long arrayOfSums[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        arrayOfSums[i] = getSum(m.values[i], m.nCols);
    if (isUnique(arrayOfSums, m.nRows))
        transposeSquareMatrix(m);
}

// возвращает true, если матрицы m1 и m2
// взаимообратные, иначе - false
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m = mulMatrices(m1, m2);
    return isEMatrix(m);
}

int max(int a, int b) {
    return a > b ? a : b;
}

// возвращает сумму максимальных элементов
// всех псевдодиагоналей данной матрицы
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.nRows + m.nCols - 1;
    int maxesOfPseudodiagonals[n];

    for (size_t i = 0; i < n; i++)
        maxesOfPseudodiagonals[i] = 0;

    int indexPdDiagonalElement;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (j != i) {
                indexPdDiagonalElement = j - i + m.nRows - 1;
                maxesOfPseudodiagonals[indexPdDiagonalElement] =
                        max(maxesOfPseudodiagonals[indexPdDiagonalElement], m.values[i][j]);
            }

    return getSum_(maxesOfPseudodiagonals, n);
}

int getMinInArea(matrix m) {
    position posMax = getMaxValuePos(m);
    int min = m.values[posMax.rowIndex][posMax.colIndex];
    int right = posMax.colIndex;
    int left = posMax.colIndex;
    int possibleMin;
    for (int i = posMax.rowIndex - 1; i >= 0; i--) {
        if (right != m.nCols - 1)
            right++;

        if (left != 0)
            left--;

        possibleMin = getMin(&m.values[i][left], right - left);
        if (possibleMin < min)
            min = possibleMin;
    }

    return min;
}


double getDistance(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += pow(a[i], 2);

    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)) {
    float additionalArray[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        additionalArray[i] = criteria(m.values[i], m.nCols);
    for (size_t i = 1; i < m.nRows; i++) {
        float t = additionalArray[i];
        int j = i;
        while (j > 0 && additionalArray[j - 1] > t) {
            additionalArray[j] = additionalArray[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        additionalArray[j] = t;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int countUnique = 1;

    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            countUnique++;

    return countUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long additionalArray[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        int sumOfRow = 0;
        for (int j = 0; j < m.nCols; j++)
            sumOfRow += m.values[i][j];
        additionalArray[i] = sumOfRow;
    }

    return countNUnique(additionalArray, m.nRows);
}

int getNSpecialElement(matrix m) {
    int nSpecialElement = 0;
    for (int i = 0; i < m.nCols; i++) {
        long long sumOfCol = 0;
        long long maxOfCol = m.values[0][i];

        for (int j = 0; j < m.nRows; j++) {
            sumOfCol += m.values[i][j];
            if (maxOfCol < m.values[i][j])
                maxOfCol = m.values[i][j];
        }

        if (maxOfCol > sumOfCol - maxOfCol)
            nSpecialElement++;
    }

    return nSpecialElement;
}

void swapPenultimateRow(matrix m) {
    if (m.nRows <= 1) {
        fprintf(stderr, "few rows\n");
        exit(3);
    }

    position posMin = getMinValuePos(m);
    int firsRowElement = m.values[m.nRows - 2][posMin.colIndex];
    for (size_t i = 0; i < m.nRows; i++)
        m.values[m.nRows - 2][i] = m.values[i][posMin.colIndex];

    m.values[m.nRows - 2][m.nCols - 2] = firsRowElement;
}


bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int countMatrices = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            countMatrices++;

    return countMatrices;
}


int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            count++;

    return count;
}

int countZeroRows(matrix m) {
    int countZeroRows = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            countZeroRows++;

    return countZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int countZeroRowsMatrix[nMatrix];
    int maxZeroRows = 0;
    for (size_t i = 0; i < nMatrix; i++) {
        int zeroRows = countZeroRows(ms[i]);
        countZeroRowsMatrix[i] = zeroRows;
        if (zeroRows > maxZeroRows)
            maxZeroRows = zeroRows;
    }

    for (size_t i = 0; i < nMatrix; i++)
        if (countZeroRowsMatrix[i] == maxZeroRows)
            outputMatrix(ms[i]);
}

double getAbsoluteMax(matrixf m) {
    double maxRate = fabs(m.values[0][0]);
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            double possibleMaxRate = fabs(m.values[i][j]);
            if (possibleMaxRate > maxRate)
                maxRate = possibleMaxRate;
        }
    }

    return maxRate;
}

void printMatrixWithMaxRate(matrixf *ms, int nMatrix) {
    double minRate = getAbsoluteMax(ms[0]);
    double maxRatesMatrix[nMatrix];
    maxRatesMatrix[0] = minRate;
    for (size_t i = 1; i < nMatrix; i++) {
        double maxRate = getAbsoluteMax(ms[i]);
        maxRatesMatrix[i] = maxRate;
        if (maxRate < minRate)
            minRate = maxRate;
    }

    for (size_t i = 0; i < nMatrix; i++) {
        if (fabs(maxRatesMatrix[i] - minRate) < DBL_EPSILON)
            outputMatrixF(ms[i]);
    }
}


void test_findSumOfMaxesOfPseudoDiagonal_oneElement() {
    matrix m = createMatrixFromArray((int[]) {
                                             1
                                     },
                                     1, 1);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 0);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3
                                     },
                                     1, 3);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 5);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m = createMatrixFromArray((int[]) {
                                             1,
                                             2,
                                             3
                                     },
                                     3, 1);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 5);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_manyRowsAndCols() {
    matrix m = createMatrixFromArray((int[]) {
                                             3, 2, 5, 4,
                                             1, 3, 6, 3,
                                             3, 2, 1, 2
                                     },
                                     3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_oneElement();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_manyRowsAndCols();
}

int main() {
    /*matrix m = getMemMatrix(3, 3);

    inputMatrix(m);

    insertionSortColsMatrixByColCriteria(m, getSum);

    outputMatrix(m);*/

    test();
    test_findSumOfMaxesOfPseudoDiagonal();

    return 0;
}