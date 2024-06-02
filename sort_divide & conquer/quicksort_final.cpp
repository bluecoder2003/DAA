#include<iostream>
using namespace std;
void swap(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int partition(int *a,int lb,int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<=end){
        while(pivot>=a[start]){
            start++;
        }
        while(pivot<a[end])
        {
            end--;

        }
        if(start<end){
            swap(a[start],a[end]);
        }
    }
    swap(a[end],a[lb]);
    return end;

}
void quicksort(int *a,int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        cout<<"pivot is "<<a[loc]<<endl;
        cout << "Array after partitioning: ";
        for(int i = lb; i <= ub; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
int main(){
    int n;
    cout<<"enter the size of the array: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements: ";
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}