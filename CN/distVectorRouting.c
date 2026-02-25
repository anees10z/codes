#include <stdio.h>

#define N 4
#define INF 9999

int main() {
    int i, j, k;

    // Direct cost matrix (graph)
    int cost[N][N] = {
        {0, 10, 3, INF},
        {INF, 0, 1, 2},
        {INF, 4, 0, 8},
        {INF, INF, INF, 0}
    };

    int dist[N][N];

    // Initialize distance matrix
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            dist[i][j] = cost[i][j];
        }
    }

    // Distance Vector update logic
    for(k = 0; k < N; k++) {
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print final routing table
    printf("Shortest distance matrix:\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
