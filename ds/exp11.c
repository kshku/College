#include <stdio.h>
#include <stdlib.h>

int a[20][20], reached[20], n, i, j, count = 0;

void dfs(int v) {
    reached[v] = 1;
    for (i = 1; i <= n; ++i) {
        if (a[v][i] && !reached[i]) {
            printf("%d ---> %d\n", v, i);
            ++count;
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) reached[i] = 0;
    printf("Enter the graph data in matrix from:\n");
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    printf("DFS connectivity check from node 1\n");
    dfs(1);
    if (count == n - 1)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected\n");
}
