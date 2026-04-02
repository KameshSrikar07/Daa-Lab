#include <stdio.h>
#include <limits.h>

int main() {
    int n,i,j,u,v,min;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int graph[n][n];
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d",&src);

    int dist[n], visited[n];

    for(i=0;i<n;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }

    dist[src]=0;

    for(i=0;i<n-1;i++){
        min=INT_MAX;
        u=-1;

        for(j=0;j<n;j++){
            if(!visited[j] && dist[j]<min){
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        for(v=0;v<n;v++){
            if(graph[u][v]!=0 && !visited[v] && dist[u]!=INT_MAX &&
               dist[u]+graph[u][v] < dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printf("Shortest distances from source:\n");
    for(i=0;i<n;i++)
        printf("Vertex %d : %d\n",i,dist[i]);

    return 0;
}