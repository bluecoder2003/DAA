#include<iostream>
using namespace std;

void merge(int *arr,int p,int q,int r)
{
  int n1=q-p+1;
  int n2=r-q;
  int L[n1],R[n2];
  for(int i=0;i<n1;i++)
  {
    L[i]=arr[p+i];
  }
  for(int j=0;j<n2;j++)
  {
    R[j]=arr[q+1+j];
  }
  int i=0;
  int j=0;
  int k=p;
  while(i<n1 && j<n2)
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

void mergesort(int *arr,int p,int r)
{
  if(p<r)
  {
    int q=p+(r-p)/2;
    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    cout<<"first subarray"<<endl;
    for(int i=p;i<=q;i++)
    {
      cout<<arr[i]<<endl;
    }
    cout<<"second subarray"<<endl;
    for(int i=q+1;i<=r;i++)
    {
      cout<<arr[i]<<endl;
    }
    merge(arr,p,q,r);
    cout<<"merged array"<<endl;
    for(int i=p;i<=r;i++)
    {
      cout<<arr[i]<<endl;
    }
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
  mergesort(arr,0,n-1);
  cout<<"sorted array is";
  for(int i=0;i<n;i++)
  {
    cout<<arr[i];
  }
  return 0;
}