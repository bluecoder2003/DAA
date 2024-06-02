#include<iostream>
#include<fstream>
#define INF 999
using namespace std;

int w[100][100],n;

void readgraph()
{
    ifstream fp("graph2.txt");
    if(!fp)
    {
        cout<<"error";
        exit(1);
    }
    fp>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fp>>w[i][j];
        }
    }
    fp.close();
}

void showgraph()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
}

int parent[100];
int mstset[100];
int key[100];

int minkey()
{
    int min=INF;
    int minindex=-1;
    for(int i=0;i<n;i++)
    {
        if(mstset[i]==0 && key[i]<min)
        {
            min=key[i];
            minindex=i;
        }
    }
    return minindex;
}

void mstprim(int v)
{
    for(int i=0;i<n;i++)
    {
        key[i]=INF;
        mstset[i]=0;
        parent[i]=-1;
    }
    key[v]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=minkey();
        mstset[u]=1;
        for(v=0;v<n;v++)
        {
            if(w[u][v] && mstset[v]==0 && w[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=w[u][v];
            }
        }
    }
}

void print(int v)
{
    int cost=0;
    for(int i=0;i<n;i++)
    {
        cost+=key[i];
        if(i!=v)
        {
            cout<<parent[i]<<"---"<<i<<"with cost"<<key[i]<<endl;
        }
    }
    cout<<"the cost is "<<cost<<endl;
}

int main()
{
    readgraph();
    showgraph();
    mstprim(0);
    print(0);
    return 0;
}