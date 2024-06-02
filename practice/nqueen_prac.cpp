#include<iostream>
using namespace std;

bool issafe(int** board,int r,int c,int n)
{
    for(int i=0;i<r;i++)
    {
        if(board[i][c]==1)
        {
            return false;
        }
    }

    int x=r;
    int y=c;
    while(x>=0 &&y>=0)
    {
        if(board[x][c]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    int x=r;
    int y=c;
    while(x>=0 &&y<n)
    {
        if(board[x][c]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

void printarray(int** board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1)
            {
                cout<<"Q";
            }
            else
            {
                cout<<"-";
            }
        }
        cout<<endl;
    }
}

void nqueen(int **board,int r,int n)
{
    if(r==n)
    {
        printarray(board,n);
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(issafe(board,r,i,n))
        {
            board[r][i]=1;
            nqueen(board,r+1,n);
            board[r][i]=0;
        }
    }
}

int main()
{
    int n;
    cout<<"enter the number of queens";
    cin>>n;
    int** board=new int*[n];
    for(int i=0;i<n;i++)
    {
        board[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            board[i][j]=0;
        }
    }
    nqueen(board,0,n);
    return 0;
}