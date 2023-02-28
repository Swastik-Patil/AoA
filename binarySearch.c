#include <stdio.h>

int BinarySearch(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }

    if (arr[mid] > x)
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
    return BinarySearch(arr, low, high, x);
}

int main()
{
    int arr[] = {3, 9, 10, 27, 38, 43, 82};
    int x = 43;

    int low = 0;
    int high = (sizeof(arr) / sizeof(arr[0])) - 1;

    int res = BinarySearch(arr, low, high, x);

    if (res == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element %d found at position %d", x, res);
    }

    return 0;
}