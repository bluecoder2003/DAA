#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int partition(int* arr,int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[end],arr[lb]);
    return end;
}

void quicksort(int* arr,int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(arr,lb,ub);
        cout<<"pivot is"<<arr[loc]<<endl;
        cout<<"array after partitioning";
        for(int i=lb;i<=ub;i++)
        {
            cout<<arr[i]<<" ";
        }
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int main()
{
    int n;
    cout<<"enter number of elements";
    cin>>n;
    int* arr=new int[n];
    cout<<"enter elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"sorted array";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;
}