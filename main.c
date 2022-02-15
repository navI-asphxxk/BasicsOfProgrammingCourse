#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int main() {
    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);

    insertionSortColsMatrixByColCriteria(m, getSum);

    outputMatrix(m);

    return 0;
}