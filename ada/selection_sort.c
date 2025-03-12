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
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[i] < arr[min]) min = j;
        swap(&arr[min], &arr[i]);
    }
}

int *gen_rand_arr(int n) {
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) arr[i] = rand();

    return arr;
}

int main(void) {
    // int input_sizes = {5000, 10000, 15000, 20000};
    int *arr;
    clock_t start, end;
    double time_taken;
    printf("Input size\tTime taken\n");
    for (int input_size = 5000; input_size <= 20000; input_size += 5000) {
        arr = gen_rand_arr(input_size);

        start = clock();
        selection_sort(arr, input_size);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%10d\t%lf\n", input_size, time_taken);

        free(arr);
    }
}
