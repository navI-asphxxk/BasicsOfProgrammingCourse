#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
    m->nCols = 0;
    m->nRows = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);

        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);

        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2]);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void transposeSquareMatrix(matrix m) {
    int coll = 1;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = coll; j < m.nCols; j++)
            swap(&m.values[i][j], &m.values[j][i]);
        coll++;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;

    return true;
}

bool isEMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if ((i == j && m.values[i][j] != 1) ||
                (i != j && m.values[i][j] != 0))
                return false;

    return true;
}

bool isSymmetricMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;

    return true;
}

position getMinValuePos(matrix m) {
    position pos = {0, 0};
    int minValue = m.values[0][0];
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                pos.rowIndex = i;
                pos.colIndex = j;
            }
        }
    }

    return (position) pos;
}

position getMaxValuePos(matrix m) {
    position pos = {0, 0};
    int maxValue = m.values[0][0];
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > maxValue) {
                maxValue = m.values[i][j];
                pos.rowIndex = i;
                pos.colIndex = j;
            }
        }
    }

    return (position) pos;
}

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices,
                                     size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int additionalArray[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        additionalArray[i] = criteria(m.values[i], m.nCols);
    for (size_t i = 1; i < m.nRows; i++) {
        int t = additionalArray[i];
        int j = i;
        while (j > 0 && additionalArray[j - 1] > t) {
            additionalArray[j] = additionalArray[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        additionalArray[j] = t;
    }
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int additionalArray1[m.nRows];
    int additionalArray2[m.nCols];
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            additionalArray1[j] = m.values[j][i];
        additionalArray2[i] = criteria(additionalArray1, m.nRows);
    }
    for (size_t i = 1; i < m.nRows; i++) {
        int t = additionalArray2[i];
        int j = i;
        while (j > 0 && additionalArray2[j - 1] > t) {
            additionalArray2[j] = additionalArray2[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        additionalArray2[j] = t;
    }
}

matrixf createMatrixFromArrayF(const double *a,
                               int nRows, int nCols) {
    matrixf m = getMemMatrixF(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrixf *createArrayOfMatrixFromArrayF(const double *values,
                                       int nMatrices, int nRows, int nCols) {
    matrixf *ms = getMemArrayOfMatricesF(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

matrixf getMemMatrixF(int nRows, int nCols) {
    double **values = (double **) malloc(sizeof(double *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (double *) malloc(sizeof(double) * nCols);

    return (matrixf) {values, nRows, nCols};
}

matrixf *getMemArrayOfMatricesF(int nMatrices,
                                int nRows, int nCols) {
    matrixf *ms = (matrixf *) malloc(sizeof(matrixf) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrixF(nRows, nCols);

    return ms;
}

void outputMatrixF(matrixf m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            printf("%lf ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}

void freeMemMatrixF(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
    m->nCols = 0;
    m->nRows = 0;
}