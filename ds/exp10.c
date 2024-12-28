#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right, *left;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node *insertBST(Node *node, int data) {
    if (!node) return createNode(data);

    if (data < node->data)
        node->left = insertBST(node->left, data);
    else
        node->right = insertBST(node->right, data);

    return node;
}

void preorder(Node *node) {
    if (node) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node *node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(Node *node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void search(Node *node, int data) {
    if (!node) {
        printf("%d is not found in the tree\n", data);
        return;
    }
    if (data < node->data)
        search(node->left, data);
    else if (data > node->data)
        search(node->right, data);
    else
        printf("Element %d is found\n", node->data);
}

int main() {
    int choice, data, n;
    Node *root = NULL;
    printf("---MENU---\n");
    printf(
        "1.BST "
        "insertion\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n");
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("How many values: ");
                scanf("%d", &n);
                printf("Enter the values to insert: ");
                for (int i = 0; i < n; ++i) {
                    scanf("%d", &data);
                    root = insertBST(root, data);
                }
                break;
            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                search(root, data);
                break;
            case 6:
                exit(0);
        }
    }
}
