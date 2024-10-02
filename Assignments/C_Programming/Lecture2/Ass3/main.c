#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5];
    int max = arr[0];
    for(int i=0; i<5; i++)
    {
        printf("Please Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=1; i<5; i++)
    {
        if(arr[i]>arr[i-1])
        {
            max = arr[i];
        }
    }
    printf("Max = %d",max);
    return 0;
}
