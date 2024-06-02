#include<iostream>
#include<fstream>
using namespace std;

int n;
int arr[20][20];
int visit[20];
int S[20];
int top=-1;

bool isempty()
{
    return (top==-1);
}

void insert(int item)
{
    S[++top]=item;
}

int del()
{
    return S[top--];
}

void readgraph()
{
    ifstream fp("bfs_dfs.txt");
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
            fp>>arr[i][j];
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
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(int v)
{
    int u;
    for(u=0;u<n;u++)
    {
        visit[u]=0;
    }
    insert(v);
    visit[v]=1;
    while(!isempty())
    {
        u=del();
        cout<<char(u+'A')<<"-->"<<" ";
        for(int j=0;j<n;j++)
        {
            if(arr[u][j]==1)
            {
                if(visit[j]==0)
                {
                    insert(j);
                    visit[j]=1;
                }
            }
        }
    }
}

int main()
{
    readgraph();
    showgraph();
    char v;
    cout<<"enter starting vertex";
    cin>>v;
    v=v-'A'; 
    dfs(v);
    cout<<"DFS is";
    return 0;
}