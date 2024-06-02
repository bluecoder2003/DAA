#include <iostream>
using namespace std;

void Heapify(int *arr, int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);//cause we have to keep the largest at the end
        Heapify(arr, size, largest);
    }
}

void HeapSort(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--) //1st=array to heap conversion, 2nd=for nodes other than leaf nodes
    {
        Heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    cout << "Enter the size of the array :: " << endl;
    int size;
    cin >> size;
    int *arr = new int[size];
    cout << "Enter the elements of the array :: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    HeapSort(arr, size);

    cout << "The sorted array is :: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

//Time Complexity: O(n log n) for best, average, and worst cases.
//Space Complexity: O(1), as it is an in-place sorting algorithm.

//Once the max-heap is built, we repeatedly extract the maximum element (the root of the heap) and move it to the end of the array.
//After moving the root to the end of the array, we reduce the heap size by 1 and call Heapify on the new root.
//Since Heapify takes O(log n) time and we call it n times (once for each element), the time complexity for this step is O(n log n).