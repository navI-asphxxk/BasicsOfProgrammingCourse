#include "libs/algorithms/array/array.h"
#include "libs/algorithms/algorithm.h"
#include "libs/time_measuring/sorts/sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE(a) sizeof (a) /sizeof(a[0])


#define TIME_TEST(testCode, time) { \
 clock_t start_time = clock () ; \
 testCode \
 clock_t end_time = clock () ;\
 clock_t sort_time = end_time - start_time ; \
 time = ( double ) sort_time / CLOCKS_PER_SEC ; \
 }


// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64]; // имя сортировки,
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64]; // имя генератора,
    // используемое при выводе
} GeneratingFunc;


typedef struct SortFuncNComps {
    unsigned long long (*sort )(int *a, size_t n);

    char name[64];

    long long nComps;
} SortFuncNComps;

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;
// генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);
    // замер времени
    double time;
    TIME_TEST
    ({
         sortFunc(innerBuffer, size);
     }, time);

    // результаты замера
    printf("Status:");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time : %.3fs.\n", time);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void checkNComps(unsigned long long (*sortFunc )(int *, size_t),
                 void (*generateFunc )(int *, size_t),
                 size_t size, char *experimentName) {
    static size_t runCounter = 1;
// генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);
    // получение количества операций
    unsigned long long nComps = sortFunc(innerBuffer, size);

    // результаты
    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! NComps : %.3lld.\n", nComps);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3lld\n", size, nComps);
        fclose(f);
    } else {
        printf("Wrong!\n");

        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}


void timeExperiment() {
    SortFunc sorts[] = {
            {bubbleSort,    "bubbleSort"},
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            {combSort,      "combSort"},
            {shellSort, "shellSort"},
            {radixSort, "radixSort"},
            {mergeSort, "mergeSort"},
            {qsort_, "qsort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

long long getBubbleSortNComps(int *a, const size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++)
        for (int j = i; ++nComps && j < n; j++)
            if (++nComps && a[i] > a[j])
                swap(&a[i], &a[j], sizeof(int));

    return nComps;
}

long long getSelectionSortNComps(int *a, const size_t n) {
    long long nComps = 0;
    int min;
    for (size_t i = 0; ++nComps && i < n - 1; i++) {
        min = i;
        for (size_t j = i + 1; ++nComps && j < n; j++) {
            if (++nComps && a[j] < a[min])
                min = j;
        }
        swap(&a[i], &a[min], sizeof(int));
    }

    return nComps;
}

long long getInsertionSortNComps(int *a, const size_t size) {
    long long nComps = 0;
    for (size_t i = 1; ++nComps && i < size; i++) {
        int t = a[i];
        int j = i;
        while ((nComps += 2) && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
}

long long getCombSortNComps(int *a, const size_t n) {
    long long nComps = 0;
    size_t step = n;
    int swapped = 1;
    while (++nComps && step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < n; i++, j++)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
    }

    return nComps;
}

long long getShellSortNComps(int *a, const size_t n) {
    long long nComps = 0;
    int i, j, step, tmp;
    for (step = n / 2; ++nComps && step > 0; step /= 2)
        for (i = step; ++nComps && i < n; i++) {
            tmp = a[i];
            for (j = i; ++nComps && j >= step; j -= step) {
                if (++nComps && tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    j = step - 1;
            }
            a[j] = tmp;
        }

    return nComps;
}

long long _getRadixSortNComps(int *l, int *r, int N) {
    long long nComps = 0;
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; ++nComps && i < k; i++) {
        for (int j = 0; ++nComps && j < M; j++)
            c[j] = 0;

        for (int *j = l; ++nComps && j < r; j++)
            c[digit(*j, i, N, M)]++;

        for (int j = 1; ++nComps && j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; ++nComps && j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; ++nComps && j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);

    return nComps;
}

long long getRadixSortNComps(int *a, const size_t n) {
    return _getRadixSortNComps(a, a + n, 8);
}

long long getMergeNComps_(const int *a, const int n,
                          const int *b, const int m, int *c) {
    long long nComps = 0;
    int i = 0, j = 0;
    while ((nComps += 2) && i < n || j < m) {
        if ((nComps += 3) && j == m || i < n && a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }

    return nComps;
}

long long getMergeSortNComps_(int *source, int l, int r, int *buffer) {
    long long nComps = 0;
    int n = r - l;
    if (++nComps && n <= 1)
        return nComps;

    int m = (l + r) / 2;
    nComps += getMergeSortNComps_(source, l, m, buffer);
    nComps += getMergeSortNComps_(source, m, r, buffer);

    nComps += getMergeNComps_(source + l, m - l, source + m, r - m, buffer);
    memcpy(source + l, buffer, sizeof(int) * n);

    return nComps;
}

long long getMergeSortNComps(int *a, const size_t n) {
    int *buffer = (int *) malloc(sizeof(int) * n);
    long long nComps = getMergeSortNComps_(a, 0, n, buffer);
    free(buffer);

    return nComps;
}

long long getQsortNComps(int *array, const size_t n) {
    long long nComps = 0;
    int i = 0;
    int j = n - 1;
    int mid = array[n / 2];

    do {
        while (++nComps && array[i] < mid) {
            i++;
        }
        while (++nComps && array[j] > mid) {
            j--;
        }
        if (++nComps && i <= j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (++nComps && i <= j);
    if (++nComps && j > 0) {
        nComps += getQsortNComps(array, j + 1);
    }
    if (++nComps && i < n) {
        nComps += getQsortNComps(&array[i], n - i);
    }

    return nComps;
}

void NCompsExperiment() {
    // описание функций сортировки
    SortFuncNComps sorts[] = {
            {getBubbleSortNComps,    "getBubbleSortNComps"},
            {getSelectionSortNComps, "getSelectionSortNComps"},
            {getInsertionSortNComps, "getInsertionSortNComps"},
            {getCombSortNComps, "getCombSortNComps"},
            {getShellSortNComps,     "getShellSortNComps"},
            {getRadixSortNComps,     "getRadixSortNComps"},
            {getMergeSortNComps,     "getMergeSortNComps"},
            {getQsortNComps,     "getQsortNComps"}
    };

    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

// описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      " random "},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     " ordered "},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

// запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
// генерация имени файла
                static char filename[128];
                sprintf(filename,
                        "%s_%s_nComps ",
                        sorts[i].name, generatingFuncs[j].name);
                checkNComps(sorts[i]
                                    .sort,
                            generatingFuncs[j].generate,
                            size, filename);
            }
        }
        printf("\n");
    }
}

int main() {
    NCompsExperiment();

    return 0;
}