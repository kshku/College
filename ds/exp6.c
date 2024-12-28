#include <stdlib.h>

#include "stdio.h"

#define MAX 5

char cq[MAX];
int front = -1, rear = -1;

void enque() {
    if (front == (rear + 1) % MAX) {
        printf("Queue is full\n");
        return;
    }

    rear = (rear + 1) % MAX;
    printf("Enter the character: ");
    scanf("\n%c", &cq[rear]);
    if (front == -1) ++front;
}

void deque() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted character is: %c\n", cq[front]);
    front = (front + 1) % MAX;
    if (front == (rear + 1) % MAX) front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queued characters are: ");
    for (int i = front; i != rear; i = (i + 1) % MAX) printf("%c ", cq[i]);
    printf("%c\n", cq[rear]);
}

int main() {
    printf("---MENU---\n");
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}
