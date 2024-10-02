#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Please Enter number x : ");
    scanf("%d",&x);
    printf("Please Enter number y : ");
    scanf("%d",&y);
    printf("x + y = %d\r\nx - y = %d\r\nx & y = %d\r\nx | y = %d\r\nx ^ y = %d\r\n", x+y, x-y, x&y, x|y, x^y);

    return 0;
}
