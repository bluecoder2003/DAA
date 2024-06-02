#include<iostream>
#define MAX 20
using namespace std;

struct Item{
    int ItemId;
    int profit;
    int weight;
    float p_w;//profit/weight ratio
    float xi;//fractional part
};

void swap(Item &a, Item &b){
    Item temp=a;
    a=b;
    b=temp;
}

int partition(Item I[], int lb, int ub){
    int start=lb,end=ub;
    float pivot=I[lb].p_w;
    while(start<end){
        while(I[start].p_w>=pivot){
            start++;
        }
        while(I[end].p_w<pivot){
            end--;
        }
        if(start<end){
            swap(I[start],I[end]);
        }
    }
    swap(I[lb],I[end]);
    return end;
}

void quickSort_pi_wi(Item I[], int lb, int ub){
    if(lb<ub){
        int loc=partition(I, lb, ub);
        quickSort_pi_wi(I, lb, loc-1);
        quickSort_pi_wi(I, loc+1, ub);
    }
}

float knapSack(Item I[], int M, int n){ //n=number of items, M=weight
    quickSort_pi_wi(I, 0, n-1);
    float total=0;//track of total profit
    int U=M;//track of remaining capacity of knapsack
    for(int i=0;i<n;i++){
        I[i].xi=0.0;
    }
    int i;
    for(i=0;i<n;i++){
        if(I[i].weight>U)
            break;
        I[i].xi=1.0;
        U-=I[i].weight;
        total+=I[i].xi*I[i].profit;
    }
    if(i<n){ //checks to consider there are items to consider after the main loop
        I[i].xi=(float)U/I[i].weight;
        total+=I[i].xi*I[i].profit;
    }
    return total;
}

int main(){
    int M;
    int n;
    cout << "Enter the total capacity: ";
    cin >> M;
    cout << "Enter the number of item: ";
    cin >> n;
    Item* I = new Item[n];
    for(int i=0;i<n;i++){
        I[i].ItemId=i+1;//for setting item id, for eg, if we have 3 items,I[0].ItemId=0+1,I[1].ItemId=1+1
        cout << "Enter the profit and weight of Item " << I[i].ItemId << ": ";
        cin >> I[i].profit;
        cin >> I[i].weight;
        I[i].p_w=(float)I[i].profit/I[i].weight;
    }
    float total;
    total = knapSack(I,M,n);
    cout << "Sorted List: \n";
    cout << "Item no. Profit Weight pi/wi Fr.taken\n";
    cout << "------- ------ ------ ----- --------\n";
    for(int i=0;i<n;i++){
        cout << "Item " << I[i].ItemId << ": " << I[i].profit << " " << I[i].weight << " " << I[i].p_w << " " << I[i].xi;
        if(I[i].xi==1.0) cout << " <-- Completely taken."<<endl;
    }
    cout << "Total profit in work: " << total << "\n";
    return 0;
}