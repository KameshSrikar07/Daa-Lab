#include <stdio.h>
#define INF 999

int n;
int graph[20][20];
int visited[20];

int tsp(int city, int count, int cost, int ans)
{
    int i;

    if(count == n && graph[city][0] != 0)
    {
        if(ans > cost + graph[city][0])
            ans = cost + graph[city][0];
        return ans;
    }

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0 && graph[city][i] != 0)
        {
            visited[i] = 1;
            ans = tsp(i, count + 1, cost + graph[city][i], ans);
            visited[i] = 0;
        }
    }

    return ans;
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    int result = tsp(0, 1, 0, INF);

    printf("Minimum travelling cost = %d\n", result);

    return 0;
}