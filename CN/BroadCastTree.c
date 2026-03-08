#include <stdio.h>

int main() {

    int n;
    int graph[20][20];
    int visited[20] = {0};
    int queue[20];

    int front = 0, rear = -1;
    int source;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d",&source);

    visited[source] = 1;
    queue[++rear] = source;

    printf("\nBroadcast Tree Edges:\n");

    while(front <= rear)
    {
        int node = queue[front++];

        for(int i=0;i<n;i++)
        {
            if(graph[node][i] == 1 && visited[i] == 0)
            {
                printf("%d -> %d\n", node, i);

                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    return 0;
}
