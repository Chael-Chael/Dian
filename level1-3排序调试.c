#include <stdio.h>
int temp,i,j;
int arrange(int up[][2],int n)
{
    for(i = 0; i < 5; i++)
    {
        for(j = 4; j > i; j--)
        {
            if(up[j][n] > up[j-1][n])
            {
                temp = up[j][n];
                up[j][n] = up[j-1][n];
                up[j-1][n] = temp;     
            }
        }
    }
    return 0;
}

int main()
{
    int up[5][2]={{1,4},{5,6},{7,3},{3,1},{2,0}};
    int b;
    arrange(up,0);
    for(i=0;i<5;i++)
    {
        printf("Element[%d]=%d\n",i,up[i][0]);
    }
    


    return 0;
}
