#include <stdio.h>

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int main()
{
    int n,W,i,j;

    printf("Enter number of items: ");
    scanf("%d",&n);

    int wt[n+1], val[n+1];

    printf("Enter weights:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&wt[i]);

    printf("Enter values:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&val[i]);

    printf("Enter capacity: ");
    scanf("%d",&W);

    int dp[n+1][W+1];

    for(i=0;i<=n;i++)
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i]<=j)
                dp[i][j]=max(val[i]+dp[i-1][j-wt[i]], dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }

    printf("Maximum value = %d\n",dp[n][W]);

    return 0;
}