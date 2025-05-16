#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort_based_on_pbw(float p[], float w[], float n) {
    // profit by weight
    float pbw[10] = {0};
    // Time to calculate profit/weight
    for (int i = 0; i < n; ++i) pbw[i] = p[i] / w[i];

    // Now sort in 'descending' based on pbw (any sorting algoritm)
    // Bubble sort kind of thing is used here which acts similar to selection
    // sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pbw[i] < pbw[j]) {
                // swap profit
                swap(&p[i], &p[j]);
                // swap weight
                swap(&w[i], &w[j]);
                // swap profit / weight
                swap(&pbw[i], &pbw[j]);
            }
        }
    }

    // We sorted the weight and profit!
}

int main(void) {
    int n, m;
    float p[10], w[10];
    printf("Enter the number of products and max weight(n, m): ");
    scanf("%d %d", &n, &m);
    printf("Enter the weight of products: ");
    for (int i = 0; i < n; ++i) scanf("%f", &w[i]);
    printf("Enter the profit of products: ");
    for (int i = 0; i < n; ++i) scanf("%f", &p[i]);

    sort_based_on_pbw(p, w, n);

    float profit = 0;
    // Time to calculate maximum profit

    // Add all the items that fit completely in the bag. We already sorted the
    // products based on profit per weight
    int i = 0;
    while (w[i] < m && i < n) {
        m -= w[i];
        profit += p[i];
        ++i;
    }
    // If we have space, take fraction of next item.
    if (m && i < n) {
        float x = m / w[i];
        profit += p[i] * x;
        m = 0;
    }

    // or if this is easy to understand
    // for (int i = 0; i < n; ++i) {
    //     if (m <= 0) break;
    //     float x = w[i] < m ? 1.0f : m / w[i];
    //     profit += p[i] * x;
    //     m -= w[i];
    // }

    printf("Total profit: %f\n", profit);
}
