#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char usn[11], name[25], programme[20];
    int sem;
    long int phno;
    struct Node *next;
} Node;

Node *first = NULL;
Node *last = NULL;

Node *createNode() {
    Node *node = (Node *)malloc(sizeof(Node));
    printf("Enter the USN, name, programme, sem, and phno of student: ");
    scanf("%s%s%s%d%ld", node->usn, node->name, node->programme, &node->sem,
          &node->phno);
    node->next = NULL;
    return node;
}

void display() {
    Node *temp = first;
    int count = 0;
    while (temp) {
        printf("USN: %s, Name: %s, Programme: %s, Sem: %d, PhNo: %ld\n",
               temp->usn, temp->name, temp->programme, temp->sem, temp->phno);
        ++count;
        temp = temp->next;
    }
    printf("Number of students: %d\n", count);
}

void insertEnd() {
    if (!last) {
        // List is empty
        first = last = createNode();
    } else {
        // Not empty
        last->next = createNode();
        // last should always point to last node
        last = last->next;
    }
}

void deleteEnd() {
    if (!last) {
        printf("List is empty\n");
    } else {
        printf("Deleting the student with usn '%s'\n", last->usn);
        // Here two cases
        // 1 node => last = first
        // more than one node
        if (last == first) {
            // Since only one node delete it and first = last =
            // NULL
            free(last);  // or free(first);
            first = last = NULL;
        } else {
            // Get last but one node
            Node *temp = first;
            while (temp->next != last) temp = temp->next;
            // last = last but one
            last = temp;
            // Delete last one
            free(last->next);
            // Make sure last->next is null
            last->next = NULL;
            // NOTE: Now last is pointing to the last element
        }
    }
}

void insertBegin() {
    if (!first) {
        // Empty
        first = last = createNode();
    } else {
        // Not empty
        Node *temp = first;
        // Create the first node
        first = createNode();
        // Next of first should be previously first node
        first->next = temp;
    }
}

void deleteBegin() {
    if (!first) {
        printf("Queue is empty\n");
    } else {
        printf("Deleting student with usn: %s\n", first->usn);
        // Again two cases
        if (first == last) {
            free(first);
            first = last = NULL;
        } else {
            Node *temp = first;
            first = first->next;
            free(temp);
        }
    }
}

void stackDemo() {
    printf("---Stack Demo---\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    int choice;
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertBegin();
                break;
            case 2:
                deleteBegin();
                break;
            case 3:
                display(first);
                break;
            case 4:
                return;
        }
    }
}

int main() {
    printf("---MENU---\n");
    printf(
        "1.Create\n2.Display\n3.Insert End\n4.Delete End\n5.Stack "
        "Demo\n6.Exit\n");
    int choice;
    int n;
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &n);
                for (int i = 0; i < n; ++i) insertEnd();
                break;
            case 2:
                display();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                stackDemo();
                break;
            case 6:
                exit(0);
        }
    }
}
