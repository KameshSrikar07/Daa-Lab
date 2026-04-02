#include <stdio.h>
#include <stdlib.h>

int board[20], n;

int place(int row, int col)
{
    int i;
    for(i=1;i<row;i++)
    {
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}

void queen(int row)
{
    int col,i;

    for(col=1;col<=n;col++)
    {
        if(place(row,col))
        {
            board[row]=col;

            if(row==n)
            {
                for(i=1;i<=n;i++)
                    printf("(%d,%d) ",i,board[i]);
                printf("\n");
            }
            else
                queen(row+1);
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d",&n);

    queen(1);

    return 0;
}