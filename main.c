#include <stdio.h>
#include "libs/data_structures/vector/vectorVoid.h"

int main() {
    //vectorVoid v = {malloc(2 * sizeof(int)), 1, 2, sizeof(int)};
    size_t n;
    scanf("%zu", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);

        setVectorValueV(&v, i, &x);
        v.size++;
    }
    for (int i = 0; i < v.size; i++) {
        float x;
        getVectorValueV(&v, i, &x);

        printf("%f ", x);
    }

    return 0;
}