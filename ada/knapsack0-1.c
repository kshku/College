#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int dynamic_knapsack(int i, int j, int p[], int w[]) {
    // Just in the way we do it manually (dynamic one)

    // value 0th row and column is always 0
    if (i == 0 || j == 0) return 0;

    // According to formula
    if (w[i] > j)  // k[i, j] = k[i - 1, j]
        return dynamic_knapsack(i - 1, j, p, w);

    // else k[i, j] = max(k[i - 1, j], k[i - 1, j - w[i]] + p[i])
    return max(dynamic_knapsack(i - 1, j, p, w),
               dynamic_knapsack(i - 1, j - w[i], p, w) + p[i]);
}

int main(void) {
    int n, m, w[10], p[10];
    printf("Enter number of products and max weight(n, m): ");
    scanf("%d%d", &n, &m);
    printf("Enter the weight of products: ");
    // Take index starting from 1
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    printf("Enter the profit of products: ");
    // Take index starting from 1
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    // k[n, m] = max profit
    printf("Maximum profit for 0/1 knapsack: %d\n",
           dynamic_knapsack(n, m, p, w));
}
