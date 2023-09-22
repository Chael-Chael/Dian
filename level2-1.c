#include <stdio.h>
#include <stdlib.h>
//FCFS + LOOK 作为初学者尽力了
int temp,i,j,x,y;
int arrangeup(int up[][3], int x, int y)//从大到小
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
int arrangedn(int up[][3], int x, int y)//从小到大
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

int max(int up[][3], int y, int x)
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

int min(int up[][3], int y, int x)
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
    int num = 0, p = 0, floor, time = 0, move = 0;
    int u = 0, d = 0;
    int maxup, maxdn, mindn, minup;
    //初始化数据

    printf("elevatorfloor = ");
    scanf("%d", &floor);
    printf("Number Of Passengers = ");
    scanf("%d", &num);
    int passenger[num][3];
    //乘客人数

    printf("在下方依次输入起始楼层，结束楼层和间隔时间\n");
    for(i = 0; i < num; i++)
    {
        printf("Passenger %d :");
        scanf("%d %d %d",&passenger[i][0], &passenger[i][1], &passenger[i][2]);
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
    int up[u][3], dn[d][3];
    //获取上下行个数

    int u0 = 0, d0 = 0;
    for(i = 0; i < num; i++)
    {

        if(passenger[i][0] < passenger[i][1])
        {
            up[u0][0] = passenger[i][0];
            up[u0][1] = passenger[i][1];
            up[u0][2] = passenger[i][2];
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

    arrangedn(dn, 0, d);
    arrangeup(up, 0, u);
    mindn = min(dn, d, 0);
    maxup = max(up, u, 0);
    //最大和最小出发


    arrangedn(up, u, 3);
    arrangedn(dn, d, 3);//arrange according to time

    //move = 0, 向下;move = 1, 向上
    



    printf("floor/time/passenger/passenger to be served\n");
    while(num > 0)//当还有乘客时
    {
        

        if(maxup != 0)//拥有上行需求
        {
            printf("\n上行\n");
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

        if(maxdn != 0)
        {
            if(maxup < maxdn)
            {
                for(;floor < maxdn; floor++)
                {
                    printf("\n空载补齐\n");
                    printf("%d %d %d %d\n",floor - 1, time + 1, p, num);
                    time++;
                }
            }
            else if (maxup > maxdn)
            {
                for(;floor > maxdn; floor--)
                {
                    printf("\n空载补齐\n");
                    printf("%d %d %d %d\n",floor - 1, time + 1, p, num);
                    time++;
                }
            }
            else
            {}
        }
        else{}
        //运行补齐

        if(mindn != 0)
        {
            printf("\n下行\n");
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


        if(minup !=0 )
        {
            if(minup < mindn)
            {
                for(;floor > minup; floor--)
                {
                    printf("\n空载补齐\n");
                    printf("%d %d %d %d\n",floor - 1, time + 1, p, num);
                    time++;
                }
            }
            else if (minup > mindn)
            {
                for(;floor < minup; floor++)
                {
                    printf("\n空载补齐\n");
                    printf("%d %d %d %d\n",floor - 1, time + 1, p, num);
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