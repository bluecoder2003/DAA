#include<iostream>
using namespace std;

void heapify(int* arr,int size,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<size && arr[largest]<arr[left])
    {
        largest=left;
    }
    if(right<size && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)//if largest was equal to i,then heap condition would have been satisfied
    {
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }
}

void heapsort(int* arr,int size)
{
    for(int i=size/2-1;i>=0;i--)
    {
        heapify(arr,size,i);
    }
    for(int i=size-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);//sending the maximum element to the last
        heapify(arr,i,0);
    }
}

int main()
{
    int size;
    cout<<"enter size of array";
    cin>>size;
    cout<<endl;
    int *arr=new int[size];
    cout<<"enter elements";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    heapsort(arr,size);
    cout<<"sorted array";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}