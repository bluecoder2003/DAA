#include<iostream>
using namespace std;

bool issafe(int** arr,int x,int y,int n)
{
    for(int row=0;row<x;row++)
    {
        if(arr[row][y]==1)
        {
            return false;
        }
    }

    int row=x;
    int col=y;
    while(row>=0 && col>=0)
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }

    row=x;
    col=y;
    while(row>=0 && col<n)
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

int solutions=0;
bool nqueen(int** arr,int x,int n)
{
    if(x==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==1)
                {
                    cout<<"Q"<<" ";
                }
                else
                {
                    cout<<"."<<" ";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
        return false;
    }
    
    bool res=false;
    for(int col=0;col<n;col++)
    {
        arr[x][col]=1;
        res=nqueen(arr,x+1,n)||res;
        arr[x][col]=0;
    }
    return res;
}

int main() {
   int n;
   cout<<"enter number of queen";
   cin>>n;
   int** arr =new int*[n];
   for(int i=0;i<n;i++)
   {
    arr[i] = new int[n]();
   }
   nqueen(arr,0,n);
   cout<<solutions;
   return 0;
}