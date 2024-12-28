#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char ssn[11], dept[11], des[11], name[25];
    int sal;
    long int ph;
    struct Node *prev;
    struct Node *next;
} Node;

Node *first = NULL;
Node *last = NULL;

Node *createNode(Node *prev, Node *next) {
    Node *node = (Node *)malloc(sizeof(Node));

    printf(
        "Enter employee ssn, name, department, designation, salary, phone "
        "number: ");
    scanf("%s%s%s%s%d%ld", node->ssn, node->name, node->dept, node->des,
          &node->sal, &node->ph);
    node->prev = prev;
    node->next = next;

    return node;
}

void inend() {
    if (!last) {
        // List is empty
        first = last = createNode(NULL, NULL);
    } else {
        // List has some nodes
        // Previous node should be last
        last->next = createNode(last, NULL);
        // last always should point to last node
        last = last->next;
    }
}

void inbeg() {
    if (!first) {
        // List is empty
        first = last = createNode(NULL, NULL);
    } else {
        // list has some nodes
        // Next node should be first
        first->prev = createNode(NULL, first);
        // first always should point to first node
        first = first->prev;
    }
}

void delend() {
    if (!last) {
        printf("List is empty\n");
    } else {
        printf("Deleted node with ssn: %s\n", last->ssn);
        // Refer the deleteEnd and deleteBegin functions from exp7.c
        if (first == last) {
            free(last);
            first = last = NULL;
        } else {
            last = last->prev;
            free(last->next);
            last->next = NULL;
        }
    }
}

void delbeg() {
    if (!first) {
        printf("List is empty\n");
    } else {
        // Refer the deleteEnd and deleteBegin fucntions from exp7.c
        printf("Deleting node with ssn: %s\n", first->ssn);
        if (first == last) {
            free(first);
            first = last = NULL;
        } else {
            first = first->next;
            free(first->prev);
            first->prev = NULL;
        }
    }
}

void display() {
    Node *temp = first;
    int count = 0;
    while (temp) {
        printf(
            "SSN: %s, Name: %s, Department: %s, Designation: %s, Salary: %d, "
            "PhNo: %ld\n",
            temp->ssn, temp->name, temp->dept, temp->des, temp->sal, temp->ph);
        ++count;
        temp = temp->next;
    }
    printf("Number of employees: %d\n", count);
}

int main() {
    printf("---MENU---\n");
    printf(
        "1.Create\n2.Display\n3.Insert Beginning\n4.Insert End\n5.Delete "
        "Beginning\n6.Delete End\n7.Exit\n");
    int choice;
    int n;
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of employees: ");
                scanf("%d", &n);
                for (int i = 0; i < n; ++i) inend();
                break;
            case 2:
                display();
                break;
            case 3:
                inbeg();
                break;
            case 4:
                inend();
                break;
            case 5:
                delbeg();
                break;
            case 6:
                delend();
                break;
            case 7:
                exit(0);
        }
    }
}
