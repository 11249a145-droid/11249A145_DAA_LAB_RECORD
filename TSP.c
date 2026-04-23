#include <stdio.h>
#include <limits.h>

int n, cost[10][10], visited[10];

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int tsp(int city, int count)
{
    int i, min_cost = INT_MAX, temp;

    // Base condition: if all cities visited, return cost to start city
    if(count == n && cost[city][0] > 0)
        return cost[city][0];

    visited[city] = 1;

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && cost[city][i] > 0)
        {
            temp = cost[city][i] + tsp(i, count + 1);
            min_cost = min(min_cost, temp);
        }
    }

    visited[city] = 0;

    return min_cost;
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;   // initialize visited array

        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    }

    printf("Minimum tour cost: %d\n", tsp(0, 1));

    return 0;
}
