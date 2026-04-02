#include <stdio.h>
#define INF 999

struct Edge{
    int u,v,w;
};

int main()
{
    int V,E,i,j;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&V,&E);

    struct Edge edge[E];

    printf("Enter edges (u v w):\n");
    for(i=0;i<E;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);

    int dist[V];

    for(i=0;i<V;i++)
        dist[i]=INF;

    int src;
    printf("Enter source vertex: ");
    scanf("%d",&src);

    dist[src]=0;

    for(i=1;i<V;i++)
        for(j=0;j<E;j++)
            if(dist[edge[j].u]!=INF && dist[edge[j].u]+edge[j].w < dist[edge[j].v])
                dist[edge[j].v] = dist[edge[j].u] + edge[j].w;

    printf("Shortest distances:\n");

    for(i=0;i<V;i++)
        printf("Vertex %d : %d\n",i,dist[i]);

    return 0;
}