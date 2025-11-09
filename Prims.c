#include <stdio.h>

void prims(int n, int cost[10][10]) {
    int visited[10] = {0};
    int i, j, u, v, ne = 1, minCost = 0, min;

    visited[0] = 1; // start from first vertex

    printf("\nEdges in MST:\n");
    while (ne < n) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("Edge %d: (%d -> %d) cost = %d\n", ne, u, v, min);
        minCost += min;
        visited[v] = 1;
        ne++;
    }
    printf("\nMinimum cost = %d\n", minCost);
}

int main() {
    int n = 3;
    int cost[10][10] = {
        {0, 5, 10},
        {5, 0, 5},
        {10, 5, 0}
    };

    // replace 0 with infinity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    prims(n, cost);
    return 0;
}
