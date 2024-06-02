#include<iostream>
using namespace std;

void BFS(int a[10][10],int n,int source){
  int visited[10],queue[10],f=0,r=-1;
  for(int i=0;i<n;i++)
    visited[i]=0;
  visited[source]=1;
  queue[++r]=source;
  while(f<=r){
    int u=queue[f++];
    cout<<(char)(u+65)<<" ";
    for(int v=0;v<n;v++){
      if(a[u][v]==1 && visited[v]==0){
        visited[v]=1;
        queue[++r]=v;
      }
    }
  }
}
void DFS(int a[10][10],int n,int source){
  static int visited[10];
  cout<<(char)(source+65)<<" ";
  visited[source]=1;
  for(int v=0;v<n;v++){
    if(a[source][v]==1 && visited[v]==0)
      DFS(a,n,v);
  }
}

int main(){
  int n;
  cout<<"Enter the number of vertices: ";
  cin>>n;
  int a[10][10];
  cout<<"Enter the adjacency matrix: "<<endl;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  int source;
  cout<<"Enter the source vertex: ";
  cin>>source;
  cout<<"BFS traversal: ";
  BFS(a,n,source);
  cout<<endl<<"DFS traversal: ";
  DFS(a,n,source);
  return 0;
}