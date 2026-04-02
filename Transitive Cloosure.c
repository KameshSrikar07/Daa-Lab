#include <stdio.h>

int main()
{
    int n,i,j,k;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);

    printf("Transitive Closure Matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }

    return 0;
}