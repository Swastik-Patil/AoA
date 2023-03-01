#include <stdio.h>
int max, min;

void findMinMax(int arr[], int low, int high)
{
    int min1, max1;
    if (low == high)
    {
        max = min = arr[0];
    }
    else if (low + 1 == high)
    {
        if (arr[low] < arr[high])
        {
            max = arr[high];
            min = arr[low];
        }
        else
        {
            max = arr[low];
            min = arr[high];
        }
    }
    else
    {
        int mid = low + (high - low) / 2;
        findMinMax(arr, low, mid);
        max1 = max;
        min1 = min;

        findMinMax(arr, mid + 1, high);

        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}

void main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    max = arr[0];
    min = arr[0];
    findMinMax(arr, 0, size);

    printf("Minimum Number is %d and Maximum number is %d ", max, min);
}