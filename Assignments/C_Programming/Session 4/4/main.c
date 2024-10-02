#include <stdio.h>
void swap(int* x, int* y);

int main(void)
{
    int x =10, y = 20;
    printf("Before : x = %d\t y= %d\n",x ,y);
    swap(&x, &y);
    printf("After : x = %d\t y= %d\n",x ,y);
    return 0;
}
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}