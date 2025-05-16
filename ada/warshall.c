#include <stdio.h>

void warshall(int matrix[10][10], int n) {
    // We need to repeat n number of times
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            // In kth iteration, we keep kth row and kth column as it is
            if (i == k) continue;
            for (int j = 0; j < n; ++j) {
                // In kth iteration, we keep kth row and kth column as it is
                if (j == k) continue;
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    }
}

int main(void) {
    int n, matrix[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the matrix:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &matrix[i][j]);

    warshall(matrix, n);

    printf("After applying warshall's algorithm:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
