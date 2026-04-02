#include <stdio.h>

int w[20], x[20], n, m;

void subset(int sum, int k, int r)
{
    int i;

    x[k] = 1;

    if(sum + w[k] == m)
    {
        printf("Subset: ");
        for(i=1;i<=k;i++)
            if(x[i]==1)
                printf("%d ",w[i]);
        printf("\n");
    }
    else if(sum + w[k] + w[k+1] <= m)
        subset(sum + w[k], k+1, r - w[k]);

    if((sum + r - w[k] >= m) && (sum + w[k+1] <= m))
    {
        x[k] = 0;
        subset(sum, k+1, r - w[k]);
    }
}

int main()
{
    int i, total = 0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        total += w[i];
    }

    printf("Enter required sum: ");
    scanf("%d",&m);

    subset(0,1,total);

    return 0;
}