#include<iostream>
using namespace std;

struct Item
{
    int itemid;
    int profit;
    int weight;
    float p_w;
    float xi;
};

void swap(Item &a,Item &b)
{
    Item temp=a;
    a=b;
    b=temp;
}

int partition(Item I[],int lb,int ub)
{
    float pivot=I[lb].p_w;
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(I[start].p_w>=pivot)//cause we want it in descending order
        {
            start++;
        }
        while(I[end].p_w<pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(I[start],I[end]);
        }
    }
    swap(I[end],I[lb]);
    return end;
}

int quicksort(Item I[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(I,lb,ub);
        quicksort(I,lb,loc-1);
        quicksort(I,loc+1,ub);
    }
}

float knapsack(Item I[],int M,int n)
{
    quicksort(I,0,n-1);
    int U=M;
    float total=0;
    int i;
    for(i=0;i<n;i++)
    {
        I[i].xi=0.0;
    }
    for(i=0;i<n;i++)
    {
        if(I[i].weight>U)
            break;
        I[i].xi=1.0;
        U=U-I[i].weight;
        total+=I[i].xi*I[i].profit;
    }
    if(i<n)
    {
        I[i].xi=(float)U/I[i].weight;
        total+=I[i].xi*I[i].profit;
    }
    return total;

}

int main()
{
    int M,n;
    cout<<"enter capacity and total number of items";
    cin>>M>>n;
    Item *I=new Item[n];
    for(int i=0;i<n;i++)
    {
        I[i].itemid=i+1;
        cout<<"enter profit and weight of items"<<endl;
        cin>>I[i].profit;
        cin>>I[i].weight;
        I[i].p_w=(float)I[i].profit/I[i].weight;
    }
    float total;
    total=knapsack(I,M,n);
    cout<<"total profit is = "<<total<<endl;
    return 0;
}