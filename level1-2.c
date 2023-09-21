#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int A,B,C;
    int p,time; /*初始化电梯内人数*/
    p = 0;
    time = 0;

    //文件读写
    FILE *fp;
    fp = fopen("D:\\Dian\\elevator.txt", "r");
    if (fp == NULL) 
    {
        perror ("error opening file");
        exit(0);
    }
    else
    {
        fscanf(fp, "%d", &A);
        fscanf(fp, "%d", &B);
        fscanf(fp, "%d", &C);
    }
    printf("%d %d %d\n",C,time,p);
    p++;

    if(A<C)
    {
        while(A<C)
        {
            time++;
            C--;
        }   
    }
    else if(A>C)
    {
        while(A>C)
        {
            time++;
            C++;
        }
        
    }
    else if(A==C)
    {
        
    }
    printf("%d %d %d\n",C,time,p);

    if(A<B)
    {
        while(A<B)
        {
            time++;
            A++;
        }
    }
    else if(A>B)
    {
        while(A>B)
        {
            time++;
            A--;
        }
    }
    p--;
    printf("%d %d %d\n",A,time,p);
    fclose(fp);
    return 0;
}
