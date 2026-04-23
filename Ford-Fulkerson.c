#include <stdio.h>
#define MAX 10

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, i, j, s, t;
    int cap[MAX][MAX], flow = 0;
    int visited[MAX], parent[MAX];
    int queue[MAX], front, rear;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter capacity matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cap[i][j]);

    printf("Enter source and sink: ");
    scanf("%d %d", &s, &t);

    while(1)
    {
        for(i = 0; i < n; i++)
            visited[i] = 0;

        front = rear = 0;
        queue[rear++] = s;
        visited[s] = 1;
        parent[s] = -1;

        // BFS to find path
        while(front < rear)
        {
            int u = queue[front++];

            for(i = 0; i < n; i++)
            {
                if(!visited[i] && cap[u][i] > 0)
                {
                    queue[rear++] = i;
                    parent[i] = u;
                    visited[i] = 1;
                }
            }
        }

        if(!visited[t])
            break;

        int path_flow = 9999;

        for(i = t; i != s; i = parent[i])
        {
            int u = parent[i];
            path_flow = min(path_flow, cap[u][i]);
        }

        for(i = t; i != s; i = parent[i])
        {
            int u = parent[i];
            cap[u][i] -= path_flow;
            cap[i][u] += path_flow;
        }

        flow += path_flow;
    }

    printf("Maximum flow = %d\n", flow);

    return 0;
}
