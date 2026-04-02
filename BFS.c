#include <stdio.h>

int graph[20][20], visited[20], queue[20], n;

int main()
{
    int i,j,start,front=0,rear=0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    for(i=0;i<n;i++)
        visited[i]=0;

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    printf("BFS Traversal: ");

    queue[rear++]=start;
    visited[start]=1;

    while(front<rear)
    {
        int v=queue[front++];
        printf("%d ",v);

        for(i=0;i<n;i++)
        {
            if(graph[v][i]==1 && visited[i]==0)
            {
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }

    return 0;
}