#include <stdio.h>
#include <stdlib.h>

#define HTSIZE 10

int ht[HTSIZE] = {0};

void hash(int data) {
    int i = data % HTSIZE;
    while (ht[i] != 0) i = (i + 1) % HTSIZE;
    ht[i] = data;
}

int main() {
    int n;
    printf("Enter the number of employee records: ");
    scanf("%d", &n);
    int *keys = (int *)malloc(sizeof(int) * n);
    printf("Enter %d 4-digit keys: ", n);
    for (int i = 0; i < n; ++i) scanf("%d", &keys[i]);
    for (int i = 0; i < n; ++i) {
        if (i == HTSIZE) {
            printf("Hash table is full\n");
            break;
        }
        hash(keys[i]);
    }
    printf("Hash table contents:\n");
    for (int i = 0; i < HTSIZE; ++i) printf("HT[%d] = %d\n", i, ht[i]);
}
