#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        // select the smallest element
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min]) min = j;

        // Swap the smallest element to here
        swap(&arr[min], &arr[i]);
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
        selection_sort(arr, input_size);
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

    selection_sort(arr, size);

    printf("After sorting: ");
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
}
