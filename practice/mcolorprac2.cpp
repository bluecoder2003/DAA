#include<iostream>
#include<fstream>
using namespace std;

bool issafe(int**board,int V,int c,int v,int*colors)
{
    for(int i=0;i<V;i++)
    {
        if(board[v][i]!=0 && colors[i]==c)
        {
            return false;
        }
    }
    return true;
}

void printarray(int *colors, int V) {
  for (int i = 0; i < V; i++) {
    cout << colors[i] << " ";
  }
  cout << endl;
}

void mcoloring(int**board,int V,int m,int v,int *colors)
{
    if(v==V)
    {
        printarray(colors,V);
        return;
    }
    for(int c=1;c<=m;c++)
    if((issafe(board,V,c,v,colors)))
    {
        colors[v]=c;
        mcoloring(board,V,m,v+1,colors);
        colors[v]=0;
    }
}

int main()
{
    int V,m;
    ifstream fp("color2.txt");
    if(!fp)
    {
        cout<<"error int file opening";
        return 1;
    }
    fp>>V>>m;
    int**board=new int*[V];
    for(int i=0;i<V;i++)
    {
        board[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            fp>>board[i][j];
        }
    }
    int*colors=new int[V]{0};
    mcoloring(board,V,m,0,colors);
    return 0;
}