#include <stdio.h>
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void swap(int* x, int* y);

int main(void)
{
    int arr[] = {1,5,6,0,100,5,78,99};
    bubbleSort(arr, 8);
    printf("Bubble Sort : \n");
    for(int i=0; i<8; i++)
        printf("%d\t",arr[i]);
    selectionSort(arr, 8);
    printf("\nSelection Sort : \n");
    for(int i=0; i<8; i++)
        printf("%d\t",arr[i]);
    return 0;
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}