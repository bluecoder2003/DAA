#include<iostream>
using namespace std;
void merge(int arr[],int p,int q,int r)
{
        int n1=q-p+1; //sizes of 2 subarrays
        int n2=r-q;
        int L[n1],R[n2];
        for(int i=0;i<n1;i++)
            L[i]=arr[p+i];
        for(int j=0;j<n2;j++)
            R[j]=arr[q+1+j];
        
        int i=0;
        int j=0;
        int k=p; //for starting from here

        while(i<n1 && j<n2) //merge temporary arrays back to the permanent array
        {
            if(L[i]<=R[j])
            {
                arr[k]=L[i];
                i++;
            }
            else
            {
                arr[k]=R[j];
                j++;
            }
            k++;
        }

        while(i<n1)
        {
            arr[k]=L[i];
            i++;
            k++;
        }

        while(j<n2)
        {
            arr[k]=R[j];
            j++;
            k++;
        }
}
void mergesort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=p+(r-p)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        cout<<"first subarray ";
        for(int i=p;i<=q;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        cout<<"second subarray ";
        for(int i=q+1;i<=r;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        merge(arr,p,q,r);
        cout<<"subarray after merge ";
        for(int i=p;i<=r;i++)
        {
            cout<<arr[i];
        }

    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    delete[] arr;
    return 0;
}

//time complexity of merge sort, best=nlogn , avg=nlogn , worst=nlogn
//space complexity of merge sort, O(n)