#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef, x, y, z;
    struct Node *next;
} Node;

Node *createNode(int coef, int x, int y, int z, Node *next) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->coef = coef;
    node->x = x;
    node->y = y;
    node->z = z;

    if (next)
        node->next = next;
    else
        node->next = node;

    return node;
}

void insertTerm(Node *p, int coef, int x, int y, int z) {
    Node *temp = p;
    while (temp->next != p) temp = temp->next;
    temp->next = createNode(coef, x, y, z, p);
}

void display(Node *p) {
    if (p->next == p) {
        printf("Polynomial is empty\n");
        return;
    }
    Node *temp = p->next;
    do {
        printf("%d(x^%d)(y^%d)(z^%d)", temp->coef, temp->x, temp->y, temp->z);
        temp = temp->next;
        if (temp != p) printf(" + ");
    } while (temp != p);
    printf("\n");
}

int evaluate(Node *p, int x, int y, int z) {
    if (p->next == p) {
        printf("Polynomial is empty\n");
        return 0;
    }

    Node *temp = p->next;
    int ans = 0;
    do {
        ans += temp->coef * pow(x, temp->x) * pow(y, temp->y) * pow(z, temp->z);
        temp = temp->next;
    } while (temp != p);

    return ans;
}

bool equalExponents(Node *n1, Node *n2) {
    return (n1->x == n2->x) && (n1->y == n2->y) && (n1->z == n2->z);
}

Node *addPolynomials(Node *p1, Node *p2) {
    // Create the sum polynomial
    Node *psum = createNode(0, 0, 0, 0, NULL);

    Node *temp1 = p1->next;
    Node *temp2 = p2->next;

    // Insert all the p1 terms
    do {
        insertTerm(psum, temp1->coef, temp1->x, temp1->y, temp1->z);
        temp1 = temp1->next;
    } while (temp1 != p1);

    // Insert all the p2 terms, but need to check whether the term with same
    // exponent already exists
    do {
        temp1 = psum->next;
        bool added = false;
        do {
            if (equalExponents(temp1, temp2)) {
                added = true;
                temp1->coef += temp2->coef;
                break;
            }
            temp1 = temp1->next;
        } while (temp1 != psum);
        if (!added) insertTerm(psum, temp2->coef, temp2->x, temp2->y, temp2->z);
        temp2 = temp2->next;
    } while (temp2 != p2);

    return psum;
}

int main() {
    Node *p1 = createNode(0, 0, 0, 0, NULL);
    Node *p2 = createNode(0, 0, 0, 0, NULL);
    int p1_values[][4] = {
        {6, 2, 2, 1}, {-4, 0, 1, 5}, {3, 3, 1, 1}, {2, 1, 5, 1}, {-2, 1, 1, 3}};
    int p2_values[][4] = {{1, 1, 1, 3}, {4, 3, 1, 1}};

    int p1_len = sizeof(p1_values) / sizeof(p1_values[0]);
    int p2_len = sizeof(p2_values) / sizeof(p2_values[0]);

    for (int i = 0; i < p1_len; ++i)
        insertTerm(p1, p1_values[i][0], p1_values[i][1], p1_values[i][2],
                   p1_values[i][3]);
    printf("P1(x, y, z) = ");
    display(p1);

    for (int i = 0; i < p2_len; ++i)
        insertTerm(p2, p2_values[i][0], p2_values[i][1], p2_values[i][2],
                   p2_values[i][3]);
    printf("P2(x, y, z) = ");
    display(p2);

    Node *psum = addPolynomials(p1, p2);
    printf("Psum(x, y, z) = ");
    display(psum);

    int x, y, z;
    printf("Enter values for x, y, and z for evaluation of Psum(x, y, z): ");
    scanf("%d%d%d", &x, &y, &z);

    printf("Psum(%d, %d, %d) = %d\n", x, y, z, evaluate(psum, x, y, z));
}
