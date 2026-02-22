#include <stdio.h>

// Function to return max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];  // DP table

    // Build table dp[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base case: no item or 0 capacity
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            // If weight of current item <= current capacity
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w]; // Skip item
        }
    }

    return dp[n][W]; // Final answer
}

int main() {
    int val[] = {12, 10, 20, 15};
    int wt[] = {2, 1, 3, 2};
    int W = 5; // Capacity
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));
    return 0;
}
