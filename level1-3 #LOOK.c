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
    return a;
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
    return a;
}
//定义max,min函数


//mainprintf("\n空载补齐");
int main()
{
    int i, j;
    int num = 0, p = 0, floor = 1, time = 0;
    int u = 0, d = 0;
    int maxup, maxdn, mindn, minup;
    //初始化数据

    printf("Number Of Passengers = ");
    scanf("%d", &num);
    int passenger[num][2];
    //乘客人数

    printf("在下方依次输入起始和结束楼层\n");
    for(i = 0; i < num; i++)
    {
        printf("StartLevel = ");
        scanf("%d",&passenger[i][0]);
        printf("Endlevel = ");
        scanf("%d",&passenger[i][1]);
    }
    //楼层数据导入passenger数组

    for(i = 0; i < num; i++)
    {
        if(passenger[i][0] < passenger[i][1])
        {
            u+=1;
        } 
        else
        {
            d+=1;
        }
    }
    int up[u][2], dn[d][2];
    //获取上下行个数

    int u0 = 0, d0 = 0;
    for(i = 0; i < num; i++)
    {

        if(passenger[i][0] < passenger[i][1])
        {
            up[u0][0] = passenger[i][0];
            up[u0][1] = passenger[i][1];
            u0 += 1;
           
        } 
        else
        {
            dn[d0][0] = passenger[i][0];
            dn[d0][1] = passenger[i][1];
            d0 += 1;
        }
    }
    //上行下行分组，u与d为数组长度

    printf("floor/time/passenger/passenger to be served\n");
    while(num > 0)//当还有乘客时
    {
        arrangeup(up, 1, u);
        arrangeup(dn, 0, d);

        maxup = max(up, u, 1);
        maxdn = max(dn, d, 0);

        arrangedn(dn, 1, d);
        arrangedn(up, 0, u);

        minup = min(up, u, 0);
        mindn = min(dn, d, 1);
        //每次对数组重新arrange

        printf("\n上行\n");
        if(maxup != 0)//拥有上行需求
        {
            for(; floor <= maxup; floor++)//上行至最远
            {
                if(p <= 4 && p >= 0)//不超载时
                {
                    for(i = 0; i < u; i++)//遍历up数组元素
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
                }                 
                else{}
                printf("%d %d %d %d\n",floor, time, p, num);
                time++;
            }
        }
        else{}
        floor--;
        time--;

        arrangeup(dn, 0, d);
        maxdn = max(dn, d, 0);

        printf("\n空载补齐");
        if(maxdn != 0)
        {
            if(maxup < maxdn)
            {
                for(;floor < maxdn; floor++)
                {
                    time++;
                }
            }
            else if (maxup > maxdn)
            {
                for(;floor > maxdn; floor--)
                {
                    time++;
                }
            }
            else
            {}
        }
        else{}
        //运行补齐

        printf("\n下行\n");
        if(mindn != 0)
        {
            for(; floor >= mindn; floor--)//下行至最远
            { 
                if(p <= 4 && p >= 0)//不超载时
                {
                    for(i = 0; i < d; i++)//遍历dn数组元素
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
                        else{}
                    }  
                }
                else{}
                printf("%d %d %d %d\n",floor, time, p, num);
                time++;
            }            
        }
        else{}
        floor++;
        time--;

        arrangedn(up, 0, u);
        minup = min(up, u, 0);

        printf("\n空载补齐");
        if(minup !=0 )
        {
            if(minup < mindn)
            {
                for(;floor > minup; floor--)
                {
                    time++;
                }
            }
            else if (minup > mindn)
            {
                for(;floor < minup; floor++)
                {
                    time++;
                }
            }
            else
            {}
        }
        else{}
        
    }
    printf("\nProcess Ended!\n");
    return 0;
}