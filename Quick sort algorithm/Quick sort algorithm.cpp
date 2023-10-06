#include <iostream>
using namespace std;

//Pivot will be first element:
int Partition(int arr[], int start, int end)
{
    int Pivot = arr[start];
    int i = start;
    int j = end;

    //loop will run untill i and j crossed
    while (i < j)
    {
        // mov i pointer rightword if ALL IS WELL
        while (arr[i] <= Pivot && i <= end - 1)
        {
            i++;
        }
        // mov j pointer leftward if ALL IS WELL
        while (arr[j] > Pivot && j >= start + 1)
        {
            j--;
        }
        //we have two elements that need to swap with each other but their pointers did't crossed:
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //Pointers have been crossed then shuffle Pivot value with jth index
    int temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;
    //return index from which we replaced Pivot
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
