#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    if (top == MAX) {
        printf("Stack overflow\n");
        return;
    }

    printf("Enter the element: ");
    // Increment before taking input. So ++top
    scanf("%d", &stack[++top]);
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }

    // Decrement after poping element. So top--
    printf("Popped element is: %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("The stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    // Print elements from top to bottom
    for (int i = top; i > -1; --i) printf("%d ", stack[i]);
    printf("\n");
}

void isPalindrome() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    // Check the last element and first element
    // Then last but one, second and so on
    for (int i = 0; i < (top / 2) + 1; ++i) {
        if (stack[i] != stack[top - i]) {
            // Not same so not palindrom
            printf("Stack is not palindrom\n");
            return;
        }
    }
    printf("Stack is palindrom\n");
}

int main() {
    int choice;
    printf("---MENU---\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Check for palindrom\n5.Exit\n");

    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                isPalindrome();
                break;
            case 5:
                exit(0);
        }
    }
}
