#include <stdio.h>

void bubbleSort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 32, 4, 21, 212, 43, 54, 34};
    int length = sizeof(arr) / sizeof(int);
    bubbleSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}