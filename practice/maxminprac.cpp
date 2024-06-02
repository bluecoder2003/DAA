#include<iostream>
using namespace std;
int counter=0;
void max_min(int arr[],int i,int j,int &max,int &min)
{
    if(i==j)
    {
        max=min=arr[i];
    }
    else if(i+1==j)
    {
        if(arr[i]>arr[j])
        {
            max=arr[i];
            min=arr[j];
        }
        else
        {
            max=arr[j];
            min=arr[i];
        }
        counter=counter+1;
    }
    else
    {
        int mid=(i+j)/2;
        int max1,min1;
        max_min(arr,i,mid,max,min);
        max_min(arr,mid+1,j,max1,min1);
        if(max<max1)
        {
            max=max1;
        }
        if(min>min1)
        {
            min=min1;
        }
        counter=counter+2;
    }
}
int main()
{
    int size;
    cout<<"enter size of array";
    cin>>size;
    int* a=new int[size];
    cout<<"enter elements";
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int max=a[0];
    int min=a[0];
    max_min(a,0,size-1,max,min);
    cout<<"max element"<<max<<endl;
    cout<<"min element"<<min<<endl;
    cout<<"number of comparisons"<<counter<<endl;
    return 0;
}