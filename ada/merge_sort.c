#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *a, int low, int mid, int high) {
    int *ac = (int *)malloc((high + 1) * sizeof(int));
    int i = low, j = mid + 1;
    int idx = low;

    while (i < mid + 1 && j < high + 1)
        ac[idx++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i < mid + 1) ac[idx++] = a[i++];
    while (j < high + 1) ac[idx++] = a[j++];

    for (i = low; i < high + 1; ++i) a[i] = ac[i];

    free(ac);
}

void merge_sort(int *a, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int *gen_rand_arr(int n) {
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) arr[i] = rand();

    return arr;
}

int main(void) {
    clock_t start, end;
    printf("Input size\tTime taken\n");
    for (int input_size = 5000; input_size <= 20000; input_size += 5000) {
        int *arr = gen_rand_arr(input_size);

        start = clock();
        merge_sort(arr, 0, input_size - 1);
        end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%10d\t%lf\n", input_size, time_taken);

        free(arr);
    }

    // Testing whether it is sorting correctly
    int arr[] = {10, 5, 3, 1, 4, 2, 6, 8, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, size - 1);

    printf("After sorting: ");
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
}
