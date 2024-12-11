#include <stdio.h>

#define BSIZE 50

int main() {
    int blocks[BSIZE] = {0};

    int allocated_blocks;
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &allocated_blocks);

    printf("Enter the block numbers already allocated: ");
    for (int i = 0; i < allocated_blocks; ++i) {
        int a;
        scanf("%d", &a);
        blocks[a] = 1;
    }

    int running = 1;
    while (running) {
        int start, length;
        printf("Enter starting block index and length: ");
        scanf("%d%d", &start, &length);

        if (blocks[start]) {
            printf("Starting block %d is already allocated\n", start);
            goto ask;
        }

        for (int i = start; i < (start + length); ++i) {
            if (blocks[i]) {
                printf("%d Block is already allocated\n", i);
                ++length;
            } else {
                blocks[i] = 1;
                printf("%d--->%d\n", i, blocks[i]);
            }
        }

    ask:
        printf("Do you want to enter more files(yes-1 / no-0): ");
        scanf("%d", &running);
    }
}
