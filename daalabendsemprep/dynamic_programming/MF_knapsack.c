#include <stdio.h>
#include <string.h>

#define MAX 100

int F[MAX][MAX]; // Memoization table

int Weights[MAX];
int Values[MAX];

// Utility function to get max of two numbers
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// Memory function for 0/1 Knapsack
int MFKnapsack(int i, int j) {
    if (F[i][j] < 0) {
        int value;
        if (j < Weights[i]) {
            value = MFKnapsack(i - 1, j);
        } else {
            value = max(MFKnapsack(i - 1, j),
                        Values[i] + MFKnapsack(i - 1, j - Weights[i]));
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int main() {
    int n = 3;
    int W = 50;

    // 1-based indexing
    // for 0 based indexing pass n-1 in the function
    Values[1] = 60; Weights[1] = 10;
    Values[2] = 100; Weights[2] = 20;
    Values[3] = 120; Weights[3] = 30;

    // Initialize table: F[i][0] = 0 and F[0][j] = 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                F[i][j] = 0;
            else
                F[i][j] = -1;
        }
    }

    int maxValue = MFKnapsack(n, W);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
