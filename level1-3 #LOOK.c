#include <stdio.h>
#include <stdlib.h>
//尝试用LOOK算法解决问题
int temp,i,j,x,y;
int arrange(int up[][2], int x, int y)
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
//定义排序函数，冒泡排序


int main()
{
    int i, j, num, p, capacity = 4, move = 1, floor, time, u, d;
    //初始化数据

    printf("Number Of Passengers =\n");
    scanf("%d",&num);
    int passenger[num][2];
    int up[1000], dn[1000];
    //乘客人数

    printf("在下方依次输入起始和结束楼层");
    for(i = 0; i < num; i++);
        printf("StartLevel = \n");
        scanf("%d",&passenger[i][0]);
        printf("Endlevel = \n");
        scanf("%d",&passenger[i][1]);
    //楼层数据导入数组
    //move = 1 up, move = 0 down

    for(i = 0; i < n; i++)
    {
        if(passenger[i][0] < passenger[i][1])
        {
            passenger[i][0] = up[u][0];
            passenger[i][1] = up[u][1];
            u+=1;
            
        } 
        else
        {
            passenger[i][0] = dn[d][0];
            passenger[i][1] = dn[d][1];
            d+=1;
        }

    }
    //上行下行分组，u-1与d-1为数组长度

    arrange(up,0);
    arrange(up,1);
    arrange(dn,0);
    arrange(dn,1);
    //使用排序函数从大到小排序

    //定义删除数组元素函数

    for(, num > 0,)//当还有乘客时
    {
        for(, floor < 10, floor++)
        {
            for(i = 0, i < (u-1), i++)//遍历up数组元素
            {
                if(up[i][0] == floor || up[i][1] == floor)
                {
                    if(p <= 4)//当不超载时
                    {
                        if(up[i][0] != floor && up[i][1] == floor)
                        {
                            p-=1
                            num-=1
                        }
                        else if(up[i][0] == floor && up[i][1] != floor)
                        {
                            p+=1
                        }
                        else
                        {
                            num-=1
                        }
                        printf("",floor,"",time,"",p,"",num)
                    }
                }
                else
                {

                }
            }
                
        }
    }
       
        //int lengthup = sizeof(up)/sizeof(up[0]);
       
       for(i = 0, i < lengthdn, i++)
    }
    



}