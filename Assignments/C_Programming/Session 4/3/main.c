#include <stdio.h>

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

int main(void)
{
    double (*arr_fun_ptr[4])(double , double ) = {add, sub, mul, div};
    double n1, n2;
    int choice;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &n1, &n2);
    printf("Select operation:\n");
    printf("0: Add\n");
    printf("1: Subtract\n");
    printf("2: Multiply\n");
    printf("3: Divide\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("result = %0.2lf\n", arr_fun_ptr[choice](n1, n2));
    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double mul(double x, double y)
{
    return x * y;
}

double div(double x, double y)
{
    return x / y;
}