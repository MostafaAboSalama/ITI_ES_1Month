#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10];
    int n, index =-1;
    for(int i=0; i<10; i++)
    {
        printf("Please Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Please Enter Number to search: ");
    scanf("%d", &n);
    for(int i=0; i<10; i++)
    {
        if(arr[i]==n)
        {
            index = i;
            break;
        }
    }
    if(index!=-1)
        printf("The number is at position %d\n", index+1);
    else
        printf("Not Exist");
    return 0;
}
