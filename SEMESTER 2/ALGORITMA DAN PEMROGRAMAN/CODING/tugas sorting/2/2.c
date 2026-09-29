#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int n)
{
    printf("\n\nData setelah di urutkan:\n");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = {3, 100, 100, 2, 55, 2, 1, 3, 7, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nData sebelum di urutkan:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}