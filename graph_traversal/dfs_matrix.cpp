#include<iostream>
#include<fstream>
using namespace std;
#define MAX 20

int arr[MAX][MAX];
int n;
int visit[MAX];
int S[MAX];
int top=-1;

bool isEmpty(){
    return (top==-1);
}

void insert(int item){
    S[++top]=item;
}

int del(){
    return S[top--];
}

void readGraph(){
    ifstream fp("bfs_dfs.txt");
    if(!fp){
        cout << "File open failed.\n";
        return;
    }
    fp >> n;
    cout << "Number of vertices..." << n << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fp >> arr[i][j];
        }
    }
    fp.close();
}

void showGraph(){
    cout << "The Adjacency Matrix is: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int v){
    int u;
    for(u=0;u<n;u++)
        visit[u]=0;
    insert(v);
    visit[v]=1;
    while(!isEmpty()){
        u=del();
        cout << char(u + 'A') << " -> ";
        for(int j=0;j<n;j++){
            if(arr[u][j]==1){
                if(visit[j]==0){
                    insert(j);
                    visit[j]=1;
                }
            }
        }
    }
    cout << "DONE\n";
}

int main(){
    readGraph();
    showGraph();
    char v;
    cout << "\nEnter start vertex--> ";
    cin >> v;
    v=v-'A';
    cout << "DFS: ";
    dfs(v);
    return 0;
}