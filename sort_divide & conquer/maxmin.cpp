#include<iostream>
using namespace std;
int counter=0;
void max_min(int arr[],int i,int j,int &max,int &min){
  if(i==j){
    max=min=arr[i];
  }
  else if(i+1==j){ //when there are 2 elements
    if(arr[i]>arr[j]){
      max=arr[i];
      min=arr[j];
    }
    else{
      max=arr[j];
      min=arr[i];
    }
    counter=counter+1;//cause we are counting the number of comparisons
  }
  else{
    int mid=(i+j)/2;
    int max1,min1;//for storing the maximum and minimum for the right subarray
    max_min(arr,i,mid,max,min);//first subarray
    max_min(arr,mid+1,j,max1,min1);//second subarray
    if(max<max1)
      max=max1;
    if(min>min1)
      min=min1;
    counter=counter+2;
  }
}
int main(){
  int size;
  cout<<"Enter Size of Array:";
  cin>>size;
  cout<<endl;

  int *a=new int[size];
  cout<<"Enter elements:";
  for(int i=0;i<size;i++)
    cin>>a[i];
  cout<<endl;
  int max=a[0];
  int min=a[0];//these 2 lines initialize the value of max and min to the first index of array a
  max_min(a,0,size-1,max,min);
  cout<<"Maximum Element:"<<max<<endl;
  cout<<"Minimum Element:"<<min<<endl;
  cout<<"Number of Comparisons:"<<counter<<endl;
  return 0;
}