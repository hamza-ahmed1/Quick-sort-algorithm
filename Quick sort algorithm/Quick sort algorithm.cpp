#include <iostream>
using namespace std;

int Partition(int arr[], int start, int end)
{
    int Pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j)
    {
        while (arr[i] <= Pivot && i <= end - 1)
        {
            i++;
        }
        while (arr[j] > Pivot && j >= start + 1)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;

    return j;
}

void QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partition = Partition(arr, start, end);
        QuickSort(arr, start, partition - 1); // Adjust the end index here
        QuickSort(arr, partition + 1, end);
    }
}

int main()
{
    int arr[5] = { 3, 2, 1, 4, 5 };
    QuickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}
