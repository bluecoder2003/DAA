#include<iostream>
#include<fstream>
using namespace std;

int arr[20][20];
int n;
int visited[20];
int front=-1;
int rear=-1;
int Q[20];

void readgraph()
{
    ifstream fp("bfs_dfs.txt");
    if(!fp)
    {
        cout<<"error in file opening";
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

bool isempty()
{
    return (front==rear);
}

void insert(int item)
{
    rear=rear+1;
    Q[rear]=item;
}

int del()
{
    front = front +1;
    return Q[front];
}

void bfs(int v)
{
    int u;
    for(u=0;u<n;u++)//cause we have to traverse through all the vertices, not just v
    {
        visited[u]=0;
    }
    insert(v);
    visited[v]=1;
    while(!isempty())//while the queue is not empty
    {
        u=del();
        cout<<char(u+'A')<<"->";
        for(int j=0;j<n;j++)
        {
            if(arr[u][j]==1)
            {
                if(visited[j]==0)
                {
                    insert(j);
                    visited[j]=1;
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
    cout<<"enter vertex";
    cin>>v;
    v=v-'A';
    cout<<"BFS";
    bfs(v);
    return 0;
}