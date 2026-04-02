#include <stdio.h>
#define INF 999

int main()
{
    int n,i,j,k;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int dist[n][n];

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&dist[i][j]);

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest path matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",dist[i][j]);
        printf("\n");
    }

    return 0;
}