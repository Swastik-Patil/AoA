#include <stdio.h>
#include <stdbool.h>

void disp(int arr[], int size)
{
    for (int i = 0; i < size + 1; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    bool istrue = true;
    while (right != left)
    {
        if (istrue)
        {
            if (pivot < arr[right])
            {
                right--;
            }
            else
            {
                int temp = pivot;
                arr[left] = arr[right];
                arr[right] = pivot;
                istrue = false;
            }
        }
        else
        {
            if (pivot > arr[left])
            {
                left++;
            }
            else
            {
                int temp = pivot;
                arr[right] = arr[left];
                arr[left] = pivot;
                istrue = true;
            }
        }
    }
    return right;
}

void quicksort(int arr[], int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int left = 0;
    int right = (sizeof(arr) / sizeof(arr[0])) - 1;
    quicksort(arr, left, right);
    disp(arr, right);

    return 0;
}
