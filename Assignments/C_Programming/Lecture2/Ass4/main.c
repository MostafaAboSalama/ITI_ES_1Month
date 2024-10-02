#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double n, len;
    printf("Enter number of sides : ");
    scanf("%lf",&n);
    printf("Enter length of sides : ");
    scanf("%lf",&len);
    printf("Area = %0.2lf",n*(len*5)/(4*tan(M_PI/n)));
    return 0;
}
