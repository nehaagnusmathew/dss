#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    int cost[MAX][MAX], dist[MAX][MAX];
    int n, i, j, k;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter cost matrix (enter 999 for no direct path):\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];   // Initialize routing table
        }
    }

    // Distance Vector Routing using Bellman-Ford logic
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nFinal Routing Tables:\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRouter %d:\n", i);
        for(j = 0; j < n; j++)
        {
            printf("To %d -> Cost = %d\n", j, dist[i][j]);
        }
    }

    return 0;
}
