#include <stdio.h>
#include <stdlib.h>


int getC1(int sp[][3], int num, int p[4][2], int floor, int time)
{
  int i, j, a, b, c, d, e, f, C1 = 0;
  for(i = 0; i < num; i++)
  {
    if(sp[i][0] >= floor + 1 && sp[i][2] <= time)
    {
        a+=1;
    }

    if(sp[i][0] != 0 && sp[i][0] <= floor - 1 && sp[i][2] <= time)
    {
        b+=1;
    }

    if(sp[i][0] == floor && sp[i][1] != 0 && sp[i][1] <= floor - 1 && sp[i][2] <= time)
    {
        c+=1;
    }

    if(sp[i][1] >= floor +1 && sp[i][2] <= time)
    {
        f+=1;
    }
    
  }

  for(j = 0; j < 4; j++ )
  {
    if(p[j][1] >= floor + 1)
    {
        d+=1;
    }

    if(p[j][1] <= floor -1 && p[j][1] != 0)
    {
        e+=1;
    }
  }

  C1 = -a + b + c - d + e - f;
  return C1;
}

int getC2(int sp[][3], int num, int p[4][2], int floor, int time)
{
  int i, j, a, b, c, d, e, f, C2 = 0;
  for(i = 0; i < num; i++)
  {
    if(sp[i][0] >= floor + 1 && sp[i][2] <= time)
    {
        b+=1;
    }

    if(sp[i][0] != 0 && sp[i][0] <= floor - 1 && sp[i][2] <= time)
    {
        a+=1;
    }

    if(sp[i][0] == floor && sp[i][1] >= floor + 1 && sp[i][2] <= time)
    {
        c+=1;
    }

    if(sp[i][1] <= floor - 1 && sp[i][1] != 0 && sp[i][2] <= time)
    {
        f+=1;
    }
    
  }

  for(j = 0; j < 4; j++ )
  {
    if(p[j][1] >= floor + 1)
    {
        e+=1;
    }

    if(p[j][1] <= floor -1 && p[j][1] != 0)
    {
        d+=1;
    }
  }

  C2 = -a + b + c - d + e - f;
  return C2;
}

int main()
{
    int i = 0, j = 0, n = 0;
    int num = 0, p = 0, move = 0;
    int floor, time = 0;

    printf("elevatorfloor = ");
    scanf("%d", &floor);
    printf("Number Of Passengers = ");
    scanf("%d", &num);
    int sp[num][3];
    int passenger[4][2];
    n = num;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 2; j++)
        {
            passenger[i][j] = 0;
        }
    }

    printf("在下方依次输入起始楼层，结束楼层和间隔时间，以空格间隔\n");
    for(i = 0; i < num; i++)
    {
        printf("Passenger %d :", i + 1);
        scanf("%d %d %d",&sp[i][0], &sp[i][1], &sp[i][2]);
    }
    //输入

    int total = 0;
    for(i = num - 1 ; i > -1;i-- )
    {
        for(j = 0; j < i; j++ )
        {
            total = total + sp[j][2];
        }
        sp[i][2] = total + sp[i][2];
        total = 0;
    }
    //间隔时间转化为总时间

    printf("floor/time/passenger/passenger to be served\n");
    int u = 0, temp = 0;

    for(; time < sp[0][2]; time++)
    {}
    //电梯原地等待

    while(num > 0)
    {
        if(floor == (int)floor)//到整数层
        {
            //先下后上
            for(j = 0; j < 4; j++ )
            {
                if(passenger[j][1] == floor)//有人下
                {
                    if(p > 0)
                    {
                        p-=1;
                        num-=1;
                        passenger[u][0] = 0;
                        passenger[u][1] = 0;
                        u -= 1;//传递出电梯

                    }
                }
            }

            for(i = 0; i < num; i++)
            {
                if(sp[i][0] == floor && sp[i][2] <= time)//有人上&&人到了
                {
                    if(p < 4)//不超载
                    {
                        p+=1;
                        passenger[u][0] = sp[i][0];
                        passenger[u][1] = sp[i][1];
                        u += 1;//传递到电梯
                        sp[i][0] = 0;
                        sp[i][1] = 0;//清空

                    }
                }
            }

            
            printf("%d %d %d %d\n",floor, time, p, num);
            //计算代价函数，决定下一方向
            int x, y;
            x = getC1(sp, n, passenger, floor, time);
            y = getC2(sp, n, passenger, floor, time);
            if(x > y)
            {
                move = 0;
            }
            else
            {
                move = 1;
            }
            printf("%d %d", x, y);
        }
        else{}
        /*else
        {
            if(move == 0)
            {
                for(j = 0; j < 4; j++)
                {
                    if(passenger[j][1] == floor - 0.5)
                    {}
                    else
                    {
                        if(p != 4)
                        {
                            if(getC1(sp, num, passenger, floor, time) > getC2(sp, num, passenger, floor, time))
                            {
                                move = 0;
                                temp = 1;
                            }
                            else
                            {
                                move = 0;
                            }
                        }
                        else
                        {
                            temp = 1;
                        }
                    }
                }   
            }
            else
            {
                for(j = 0; j < 4; j++)
                {
                    if(passenger[j][1] == floor + 0.5)
                    {}
                    else
                    {
                        if(p != 4)
                        {
                            if(getC1(sp, num, passenger, floor, time) > getC2(sp, num, passenger, floor, time))
                            {
                                move = 0;
                            }
                            else
                            {
                                move = 1;
                                temp = 1;//下一层不停靠
                            }//代价函数判断
                        }
                        else
                        {
                            temp = 1;
                        }
                    }
                }
            }
            
        }*/
        
        //方向执行器
        /*if(floor == 1.5 && move == 0)
        {
            floor = 1;
            time += 0.5;
            move = 1;

        }
        else if(floor == 9.5 && move == 1 )
        {
            floor = 10;
            time += 0.5;
            move = 0;
        }
        else*/ 
        if(floor == 10)
        {
            move = 0;
            floor -= 1;
            time += 1;

        }
        else if(floor == 1)
        {
            move = 1;
            floor += 1;
            time += 1;
        }
        //终点停靠器

        if(floor > 1 && floor < 10)
        {
            if(temp == 0)
            {
                if(move == 0)
                {
                    floor -= 1;
                    time += 1;
                }
                else
                {
                    floor += 1;
                    time += 1;
                }
            }
            else
            {
                if(move == 0)
                {
                    floor -= 1;
                    time += 1;
                }
                else
                {
                    floor += 1;
                    time += 1;
                }
            }
            
        }
        else{}
        temp = 0;//清空temp
    }
    printf("\nProcess Ended!\n");
    return 0;
}