#include <stido.h>

int temp,i,j
int * arrange(int up)
{
    for(i = 0; i < (u-1); i++)
    {
        for(j = u-1; j > i; j--)
        {
            if(up[j] > up[j-1])
            {
                temp = up[j];
                up[j] =  up[j-1];
                up[j-1] = temp;     
            }
        }
    }
    return up;
}

int main()
{
    

    
}
