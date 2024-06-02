#include<iostream>
#include<fstream>
#define INF 999
using namespace std;

int w[100][100],n;
void readGraph(){
    ifstream file("graph2.txt");
    if(!file){
        cout<<"Error";
        exit(1);
    }
    file >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            file >> w[i][j];
        }
    }
    file.close();
}
void showGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
}
int parent[100];
int mstSet[100];
int key[100];
int minkey(){
    int min=INF;
    int minIndex=-1;
    for(int i=0;i<n;i++){
        if(mstSet[i]==0 && key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void djikshitra(int v){
    for(int i=0;i<n;i++){
        key[i]=INF;
        mstSet[i]=0;
        parent[i]=-1;
    }
    key[v]=0;
    
    for(int i=0;i<n-1;i++){
        int u=minkey();
        mstSet[u]=1;
        for(v=0;v<n;v++){
            if(w[u][v]!=INF && mstSet[v]==0 && key[u]+w[u][v]<key[v]){
                parent[v]=u;
                key[v]=w[u][v]+key[u];
            }
        }
    }
}
void printPath(int s,int d,int *parent){
    if(s==-1)
    return;
    if(s==d){
        cout<<s<<" ";
        return;
    }
    printPath(parent[s],d,parent);
    cout<<"--> "<<s;
}

void print(int v){
    for(int i=0;i<n;i++){
        printPath(i,0,parent);
        cout<<" : "<<key[i]<<endl;
    }
}

int main(){
    readGraph();
    showGraph();
    djikshitra(0);
    print(0);
    return 0;
}