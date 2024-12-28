#include <stdio.h>

// Compile command
// gcc worst_fit.c

void worst_fit_allocate(int *blocks, int *files, int *allocation, int nb,
                        int nf) {
    // Keep track of whether the block is allocated or not
    int block_allocated[nb];
    for (int i = 0; i < nb; ++i) block_allocated[i] = 0;

    for (int i = 0; i < nf; ++i) {  // loop through the files
        int max = 0;                // Keep track of larget memory block index
        for (int j = 0; j < nb; ++j) {  // loop through the blocks
            if (block_allocated[j]) continue;
            if (blocks[max] < blocks[j]) max = j;
        }
        // Found the largest block index
        if (blocks[max] >= files[i] && !block_allocated[max]) {
            // mark the block as allocated
            block_allocated[max] = 1;
            // represent the allocation
            allocation[i] = max;
        } else {
            // Block size is not enough, file is not allocated
            allocation[i] = -1;
        }
    }
}

int main() {
    printf("***Memory management scheme - Worst Fit***\n");

    int nb;
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    int nf;
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    int blocks[nb];
    printf("Enter the size of blocks:\n");
    for (int i = 0; i < nb; ++i) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    int files[nf];
    printf("Enter the size of files:\n");
    for (int i = 0; i < nf; ++i) {
        printf("File %d: ", i + 1);
        scanf("%d", &files[i]);
    }

    int allocation[nf];
    worst_fit_allocate(blocks, files, allocation, nb, nf);

    printf("File no\tFile size\tBlock no\tBlock size\tFragment\n");
    for (int i = 0; i < nf; ++i) {
        if (allocation[i] == -1)
            printf("%d\t%d\t\t-\t\t-\t\t-\n", (i + 1), files[i]);
        else
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", (i + 1), files[i],
                   (allocation[i] + 1), blocks[allocation[i]],
                   (blocks[allocation[i]] - files[i]));
        // Fragmentation is calculated as blocks[allocation[i]] - files[i]
    }
}
