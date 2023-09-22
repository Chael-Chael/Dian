#include <stdio.h>
#include <stdlib.h>
//尝试用LOOK算法解决问题
int temp,i,j,x,y;
int arrangeup(int up[][2], int x, int y)
{
    for(i = 0; i < y; i++)
    {
        for(j = y-1; j > i; j--)
        {
            if(up[j][x] > up[j-1][x])
            {
                temp = up[j][x];
                up[j][x] = up[j-1][x];
                up[j-1][x] = temp;     
            }
        }
    }
    return 0;
}
int arrangedn(int up[][2], int x, int y)
{
    for(i = 0; i < y; i++)
    {
        for(j = y-1; j > i; j--)
        {
            if(up[j][x] < up[j-1][x])
            {
                temp = up[j][x];
                up[j][x] = up[j-1][x];
                up[j-1][x] = temp;     
            }
        }
    }
    return 0;
}
//定义排序函数，冒泡排序

int max(int up[][2], int y, int x)
{
    int a;
    for(i = 0; i < y; i++)
    {
        if(up[i][x] != 0)
        {
            a = up[i][x];
            break;
        }
        else
        {
            a = 0;
        }
    } 
}

int min(int up[][2], int y, int x)
{
    int a;
    for(i = 0; i < y; i++)
    {
        if(up[i][x] != 0)
        {
            a = up[i][x];
            break;
        }
        else
        {
            a = 0;
        }
    } 
}
//定义max,min函数

int main
{
    int d = 1, maxdn, mindn;
    int dn[1][2] = {{0, 0}};
    arrangedn(dn, 0, d);
    arrangedn(dn, 1, d);

    maxdn = max(dn, d, 0);

    



}