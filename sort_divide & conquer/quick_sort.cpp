#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(true) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if(i <= j) {
            swap(&arr[i], &arr[j]);
        } else {
            swap(&arr[low], &arr[j]);
            return j;
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        cout<<"pivot is "<<arr[pi]<<endl;
        cout << "Array after partitioning: ";
        for(int i = low; i <= high; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1 );
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


//time complexity of quick sort, best=nlogn , avg=nlogn , worst=n^2
//space complexity of quick sort, best=logn , worst=n

/*How does Quicksort achieve sorting? Describe the high-level approach.
QuickSort is a divide-and-conquer algorithm for sorting an array. Here's a high-level description of how it works:

Choose a pivot: The algorithm starts by choosing a pivot element from the array. The choice of pivot can be the first element, the last element, the middle element, or even a random element. Different choices of the pivot can lead to different performance characteristics.

Partition the array: The array is partitioned into two subarrays around the pivot. All elements less than or equal to the pivot are moved to its left, and all elements greater than the pivot are moved to its right. After this step, the pivot is in its final sorted position.

Recursively sort the subarrays: The algorithm then recursively applies the same process to the subarray of elements to the left of the pivot and the subarray of elements to the right of the pivot.*/

/*What is the worst-case time complexity of Quicksort? When does it occur?
The worst-case time complexity of QuickSort is O(n^2). This occurs when the smallest or largest element is always chosen as the pivot.*/

