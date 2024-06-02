#include<iostream>
using namespace std;
int counter=0;

void maxmin(int* a,int i,int j,int &max,int &min)
{
    if(i==j)
    {
        max=min=a[i];
    }
    else if (i+1==j)
    {
        if(a[i]>a[j])
        {
            max=a[i];
            min=a[j];
        }
        else
        {
            max=a[j];
            min=a[i];
        }
        counter=counter+1;
    }
    else
    {
        int mid=(i+j)/2;
        int max1,min1;
        maxmin(a,i,mid,max,min);
        maxmin(a,mid+1,j,max1,min1);
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
    cout<<"enter number of elements";
    cin>>size;
    cout<<endl;
    int* arr=new int[size];
    cout<<"enter elements";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int max=arr[0];
    int min=arr[0];
    maxmin(arr,0,size-1,max,min);
    cout<<"max element"<<max;
    cout<<"min element"<<min;
    cout<<"number of comparisons"<<counter;
}