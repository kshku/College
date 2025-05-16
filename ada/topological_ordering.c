#include <stdio.h>

void print_topological_ordering(int a[10][10], int n) {
    // Source removal method

    // If we observe the adjacency matrix, the number of 1's in the row gives
    // number of outgoing edges from the node. For example
    // [0, 1, 1]
    // [1, 0, 0]
    // [0, 0, 0]
    // Here 2 have two outgoing edges and 1 incoming edge. (Check by drawing
    // graph)

    // Let's calculate in-degree (number of 1's in column)
    int in[10];

    for (int col = 0; col < n; ++col) {
        in[col] = 0;
        for (int row = 0; row < n; ++row) in[col] += a[row][col];
    }

    // If in-degree is 0, print that node and delete it.
    // Deleting means decrementing the in-degree of nodes that can be visited by
    // the removed node.
    // NOTE: Taking nodes as 1, 2, 3, ...

    // Let's have a variable to keep track of how many nodes we already printed
    // If count == n we are done.
    int count = 0;

    for (int i = 0; count != n; i = (i + 1) % n) {
        if (in[i] == 0) {
            printf("%d ", i + 1);
            ++count;
            // Decrement the in-degree
            for (int j = 0; j < n; ++j) {
                // In column we get the outgoing edges.
                // If we have outgoing edge from this node, decrement the
                // in-degree of it.
                if (a[i][j]) --in[j];
            }
        }
    }
}

int main(void) {
    int n, a[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);

    printf("Topological ordering: ");
    print_topological_ordering(a, n);
    printf("\n");
}
