#include <stdio.h>
#define INF 999

int main()
{
    int n,i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int cost[n][n],dist[n];

    printf("Enter cost adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    for(i=0;i<n;i++)
        dist[i]=INF;

    dist[n-1]=0;

    for(i=n-2;i>=0;i--)
        for(j=0;j<n;j++)
            if(cost[i][j]!=0 && dist[i] > cost[i][j] + dist[j])
                dist[i] = cost[i][j] + dist[j];

    printf("Minimum cost from source to destination: %d\n",dist[0]);

    return 0;
}