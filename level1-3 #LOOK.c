#include <stdio.h>
#include <stdlib.h>
//尝试用LOOK算法解决问题
int main()
{
    int i, num, p, capacity = 4, move = 1, floor, time, u, d;
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

    int temp
    int * arrange()
    {
        
    }

    for(i = 0; i < (u-1); i++)
    {
        for(j = u-1; j > i; j--)
        {
            if(up[j][] > up[j-1][])
            {
                temp1 = up[j];
                up[j] =  up[j-1];
                up[j-1] = temp1;     
            }
        }
    }
    for(i = 0; i < (d-1); i++)
    {
        for(j = d-1; j > i; j--)
        {
            if(dn[j] > dn[j-1])
            {
                temp2 = dn[j];
                dn[j] = dn[j-1];
                dn[j-1] = temp2;
            } 
        }
    }
    //上行下行冒泡排序，从大到小
    /*排序调试*/

    //int lengthup = sizeof(up)/sizeof(up[0]);
    //int lengthdn = sizeof(dn)/sizeof(dn[0]);

    for(i = 0; i < n; i++)
    {
        if(/* condition */)
        {
            /* code */
        }
        
    }
    //排序
//定义删除数组元素函数

    for(, num > 0,)//当还有乘客时
    { 
        for(i = 0, i < (u-1), i++)
        {
            floor++
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
                else
                {

                }
            }
        }
        //int lengthup = sizeof(up)/sizeof(up[0]);
       
       for(i = 0, i < lengthdn, i++)
    }
    



}