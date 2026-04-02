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

    dist[0]=0;

    for(i=1;i<n;i++)
        dist[i]=INF;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(cost[i][j]!=0 && dist[j] > dist[i] + cost[i][j])
                dist[j] = dist[i] + cost[i][j];

    printf("Minimum cost from source to each vertex:\n");

    for(i=0;i<n;i++)
        printf("Vertex %d : %d\n",i,dist[i]);

    return 0;
}