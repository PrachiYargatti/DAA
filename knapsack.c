#include <stdio.h>

int max(int a, int b) {
   if (a > b) {
    return a;
} else {
    return b;
}
}

int knapsack(int maxWeight, int weights[], int values[], int n) {
    int dp[n + 1][maxWeight + 1];
    int i,w;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][maxWeight];
}

int main() {
    int n, i, maxWeight;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];
    
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &maxWeight);
    
    printf("Enter the values of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }
    
    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }


    int result = knapsack(maxWeight, weights, values, n);
    printf("Maximum value in knapsack: %d\n", result);

    return 0;
}
