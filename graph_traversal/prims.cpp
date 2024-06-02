#include<iostream>
#include<fstream>
#define INF 999
using namespace std;

int w[100][100],n;//w=to store weight of edges,n=number of vertices
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
int parent[100];//stores the parent node of each node
int mstSet[100];//keeps track of nodes in the mst
int key[100];//used to pick minimum weight edge

int minkey(){ //
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

void mstPrims(int v){
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
            if(w[u][v] && mstSet[v]==0 && w[u][v]<key[v]){
                parent[v]=u;
                key[v]=w[u][v];
            }
        }
    }
}
void print(int v){
    int cost=0;
    for(int i=0;i<n;i++){
        cost+=key[i];
        if(i!=v)
           cout << parent[i] << "---" << i << " with cost= " << key[i] << "\n";
    }
    cout << "The cost is: " << cost << endl;
}

int main(){
    readGraph();
    showGraph();
    mstPrims(0);
    print(0);
    return 0;
}



/*
key[0] = 0
First Iteration:

Find vertex with minimum key value not in mstSet:
minkey() returns 0 (key[0] = 0)
Include vertex 0 in mstSet:
mstSet = [1, 0, 0, 0, 0]
Update keys and parents for adjacent vertices of 0:
For vertex 1: w[0][1] = 5, update key[1] = 5, parent[1] = 0
For vertex 2: w[0][2] = 6, update key[2] = 6, parent[2] = 0
Updated arrays:
key = [0, 5, 6, INF, INF]
parent = [-1, 0, 0, -1, -1]
Second Iteration:

Find vertex with minimum key value not in mstSet:
minkey() returns 1 (key[1] = 5)
Include vertex 1 in mstSet:
mstSet = [1, 1, 0, 0, 0]
Update keys and parents for adjacent vertices of 1:
For vertex 3: w[1][3] = 4, update key[3] = 4, parent[3] = 1
Updated arrays:
key = [0, 5, 6, 4, INF]
parent = [-1, 0, 0, 1, -1]
Third Iteration:

Find vertex with minimum key value not in mstSet:
minkey() returns 3 (key[3] = 4)
Include vertex 3 in mstSet:
mstSet = [1, 1, 0, 1, 0]
Update keys and parents for adjacent vertices of 3:
For vertex 2: w[3][2] = 2, update key[2] = 2, parent[2] = 3
For vertex 4: w[3][4] = 3, update key[4] = 3, parent[4] = 3
Updated arrays:
key = [0, 5, 2, 4, 3]
parent = [-1, 0, 3, 1, 3]
Fourth Iteration:

Find vertex with minimum key value not in mstSet:
minkey() returns 2 (key[2] = 2)
Include vertex 2 in mstSet:
mstSet = [1, 1, 1, 1, 0]
Fifth Iteration:

Find vertex with minimum key value not in mstSet:
minkey() returns 4 (key[4] = 3)
Include vertex 4 in mstSet:
mstSet = [1, 1, 1, 1, 1]
Constructing the MST:

The parent array now represents the MST:
parent = [-1, 0, 3, 1, 3]
The edges and their weights in the MST are:
0 -- 1 (5)
3 -- 2 (2)
1 -- 3 (4)
3 -- 4 (3)
Calculating Total Cost:

Sum of the weights of the edges in the MST:
5 + 2 + 4 + 3 = 14 */