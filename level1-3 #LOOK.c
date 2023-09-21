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

int max(int up[][2])
{
    if(up[0][0] >= up[0][1])
    {
        return up[0][0];
    }
    else
    {
        return up[0][1];
    }
    return 0;
}
int min(int up[][2])
{
    if(up[0][0] <= up[0][1])
    {
        return up[0][0];
    }
    else
    {
        return up[0][1];
    }
    return 0;
}
//定义max,min函数


//main
int main()
{
    int i, j, num = 0, p = 0, capacity = 4, move = 1, floor = 0, time = 0, u = 0, d = 0;
    //初始化数据

    printf("Number Of Passengers = ");
    scanf("%d", &num);
    int passenger[num][2];
    int up[num][2], dn[num][2];
    //乘客人数

    printf("在下方依次输入起始和结束楼层\n");
    for(i = 0; i < num; i++)
    {
        printf("StartLevel = ");
        scanf("%d",&passenger[i][0]);
        printf("Endlevel = ");
        scanf("%d",&passenger[i][1]);
    }
    //楼层数据导入数组

    for(i = 0; i < num; i++)
    {
        if(passenger[i][0] < passenger[i][1])
        {
            up[u][0] = passenger[i][0];
            up[u][1] = passenger[i][1];
            u+=1;
            
        } 
        else
        {
            dn[d][0] = passenger[i][0];
            dn[d][1] = passenger[i][1];
            d+=1;
        }

    }
    //上行下行分组，u与d为数组长度

    while(num > 0)//当还有乘客时
    {
        arrangeup(up, 0, u);
        arrangeup(up, 1, u);
        arrangedn(dn, 0, d);
        arrangedn(dn, 1, d);//每次对数组重新arrange
        for(; floor++ <= max(up); )//上行至最远
        {   
            time++;
            if(p <= 4 && p >= 0)//不超载时
            {
                for(i = 0; i < u; i++)//遍历up数组元素
                {
                    if(p <= 4 && p >= 0)
                    {
                        if(up[i][0] == floor || up[i][1] == floor)
                        {
                            if(up[i][0] != floor && up[i][1] == floor)
                            {
                                if(p > 0)
                                {
                                    p-=1;
                                    num-=1;
                                    up[i][1] = 0;
                                }
                                else{}    
                                    
                            }
                            else if(up[i][0] == floor && up[i][1] != floor)
                            {
                                if(p < 4)
                                {
                                    p+=1;
                                    up[i][0] = 0;
                                }
                                else{}
                            }
                            else
                            {
                                num-=1;
                                up[i][0] = 0;
                                up[i][1] = 0;
                            }
                        }
                        else{}
                    }
                    else
                    {}//不超载时遍历  
                 
                }  
                
            }
            else
            {}
            printf("%d %d %d\n",floor, time, p);
        }

        for(; floor-- >= min(dn); )//下行至最远
        { 
            time++;
            if(p <= 4 && p >= 0)//不超载时
            {
                for(i = 0; i < d; i++)//遍历dn数组元素
                {
                    if(p <= 4 && p >= 0)
                    {
                        if(dn[i][0] == floor || dn[i][1] == floor)
                        {
                            if(dn[i][0] != floor && dn[i][1] == floor)
                            {
                                if(p > 0)
                                {
                                    p-=1;
                                    num-=1;
                                    dn[i][1] = 0;
                                }
                                else{}    
                                    
                            }
                            else if(dn[i][0] == floor && dn[i][1] != floor)
                            {
                                if(p < 4)
                                {
                                    p+=1;
                                    dn[i][0] = 0;
                                }
                                else{}
                            }
                            else
                            {
                                num-=1;
                                dn[i][0] = 0;
                                dn[i][1] = 0;
                            }
                            
                        }
                        else
                        {

                        }
                    }
                    else
                    {}//不超载时遍历 
                
                }  


            }
            else
            {

            }
            printf("%d %d %d\n",floor, time, p);
        }

        if(num>0)
        {
            arrangedn(up, 0, u);
            arrangedn(up, 1, u);
            arrangedn(dn, 0, d);
            arrangedn(dn, 1, d);
            if(min(up) > min(dn))
            {
                for( ; floor < min(up); floor++)
                {
                    time++;
                }
            }
            else
            {
                for( ; floor > min(up); floor--)
                {
                    time++;
                }
            }
            printf("%d %d %d\n",floor, time, p);
        }
        else{}
        //电梯初始位置回归
    }

    printf("\nProcess Ended\n");
    return 0;
}