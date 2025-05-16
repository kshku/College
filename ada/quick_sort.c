#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    // Lomuto partitioning

    // Using last element as the pivot element

    // Here when we find element <= pivot, we move it to the left side of the
    // array.
    // i is the next index where we are supposed to place element <= pivot.
    int i = low;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= arr[high]) {
            swap(&arr[i], &arr[j]);
            ++i;
        }
    }

    // i is the next index where we are supposed to place the element <=
    // pivot. Move the pivot element here.
    swap(&arr[i], &arr[high]);

    // Now all the elements left side i is <= pivot and right side are > pivot
    return i;
}

void quick_sort(int *arr, int low, int high) {
    if (low >= high) return;

    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
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
        quick_sort(arr, 0, input_size - 1);
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

    quick_sort(arr, 0, size - 1);

    printf("After sorting: ");
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
}
