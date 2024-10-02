#include <stdio.h>
int Fibonacci(int n);
int main(void)
{
    printf("%d\n",Fibonacci(10));
    return 0;
}

int Fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}