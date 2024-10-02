#include <stdio.h>

int main(void)
{
   int x =10, y = 20, z = 30;
   int* p = &x ;  int* q = &y ; int* r = &z;
   printf("x = %d\t y = %d\t z = %d\n",x ,y, z);
   printf("*p = %d\t *q = %d\t *r = %d\n",*p ,*q, *r);
   printf("Swapping Pointers : \n");
   r = p;
   p = q;
   q = r;
   printf("x = %d\t y = %d\t z = %d\n",x ,y, z);
   printf("*p = %d\t *q = %d\t *r = %d\n",*p ,*q, *r);
    return 0;
}
