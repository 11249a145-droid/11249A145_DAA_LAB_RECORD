#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, min, u, v, x, y;
    int cost[10][10], visited[10] = {0};
    int total_cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    printf("Edges in MST:\n");

    for(i = 0; i < n - 1; i++)
    {
        min = INT_MAX;

        for(u = 0; u < n; u++)
        {
            if(visited[u])
            {
                for(v = 0; v < n; v++)
                {
                    if(!visited[v] && cost[u][v] != 0 && cost[u][v] < min)
                    {
                        min = cost[u][v];
                        x = u;
                        y = v;
                    }
                }
            }
        }

        printf("%d -> %d : cost = %d\n", x, y, min);

        total_cost += min;

        visited[y] = 1;
    }

    printf("Total MST cost = %d\n", total_cost);

    return 0;
}
