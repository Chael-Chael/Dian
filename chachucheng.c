#include <stdio.h>

int main()
{
    int int1, int2, cha, cheng;
    float chu;
    printf("Enter First Integer:");
    scanf("%d", &int1);
    printf("Enter Second Integer:");
    scanf("%d", &int2);

    cha = int1 - int2;
    cheng =  int1 * int2;
    chu = int1 / int2;

    printf("差 = %d/乘 = %d/除 = %f",cha, cheng, chu);

    return 0;

}