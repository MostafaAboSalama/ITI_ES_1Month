#include <stdio.h>

struct Complex
{
    double real;
    double imag;
};

struct Complex add(struct Complex c1, struct Complex c2);
struct Complex subtract(struct Complex c1, struct Complex c2);
struct Complex multiply(struct Complex c1, struct Complex c2);
struct Complex divide(struct Complex c1, struct Complex c2);
void displayComplex(struct Complex c);

int main()
{
    struct Complex c1 = {3.0, 2.0};
    struct Complex c2 = {1.0, 7.0};
    struct Complex result;
    result = add(c1, c2);
    printf("Addition: ");
    displayComplex(result);
    result = subtract(c1, c2);
    printf("Subtraction: ");
    displayComplex(result);
    result = multiply(c1, c2);
    printf("Multiplication: ");
    displayComplex(result);
    result = divide(c1, c2);
    printf("Division: ");
    displayComplex(result);

    return 0;
}

struct Complex add(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex subtract(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

struct Complex multiply(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

struct Complex divide(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    double denominator = c2.real * c2.real + c2.imag * c2.imag;
    result.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
    result.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    return result;
}

void displayComplex(struct Complex c)
{
    printf("%.2lf + %.2lfi\n", c.real, c.imag);
}
