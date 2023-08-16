#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;
    
    // Number of items input
    printf("Number of items: ");
    scanf("%d", &n);
    
    int val[n];
    int wt[n];
    
    // Item values input
    printf("Item values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    // Item weights input
    printf("Item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    // Knapsack weight capacity input
    printf("Knapsack weight capacity: ");
    scanf("%d", &W);

    printf("Answer: Maximum value: %d\n", knapsack(W, wt, val, n));
    return 0;
}
