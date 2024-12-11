#include <stdio.h>
#include <stdlib.h>

// Compile command
// gcc producer_consumer.c

int mutex = 1, full = 0, empty = 5, x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    ++x;
    printf("Producer produces item %d\n", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumed item %d\n", x);
    --x;
    ++mutex;
}

int main() {
    int ch;

    printf("1.Press 1 for producer\n");
    printf("2.Press 2 for consumer\n");
    printf("3.Press 3 for exit\n");

// Code must be executed by a single thread at a time
#pragma omp critical

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (mutex && empty)
                    producer();
                else
                    printf("Buffer is full\n");
                break;
            case 2:
                if (mutex && full)
                    consumer();
                else
                    printf("Buffer is empty\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
}
