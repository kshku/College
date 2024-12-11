#include <stdio.h>

// Compile command
// gcc first_fit.c

void first_fit_allocate(int *blocks, int *files, int *allocation, int nb,
                        int nf) {
    // Keep track of whether the block is allocated or not
    int block_allocated[nb];
    for (int i = 0; i < nb; ++i) block_allocated[i] = 0;

    for (int i = 0; i < nf; ++i) {      // loop through the files
        int index = 0;                  // index of first large enough block
        for (int j = 0; j < nb; ++j) {  // loop through the blocks
            if (block_allocated[j]) continue;
            // In first fit allocate to the first large enough memory block
            if (blocks[j] >= files[i]) {
                // assign index and break out of this loop
                index = j;
                break;
            }
        }
        // Found the first block index
        if (index > -1 && blocks[index] >= files[i]) {
            // mark the block as allocated
            block_allocated[index] = 1;
            // represent the allocation
            allocation[i] = index;
        } else {
            // Block size is not enough, file is not allocated
            allocation[i] = -1;
        }
    }
}

int main() {
    printf("***Memory management scheme - First Fit***\n");

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
    first_fit_allocate(blocks, files, allocation, nb, nf);

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
