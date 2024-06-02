#include<iostream>
#include<fstream>
using namespace std;
#define MAX 20

int arr[MAX][MAX];//adjacency matrix to store graph
int n;//number of vertices in the array
int visit[MAX];
int Q[MAX];
int front=-1;
int rear=-1;

bool isEmpty(){
    return (rear==front);
}

void insert(int item){
    rear=rear+1;//makes space for an element to enter
    Q[rear]=item;
}

int del(){ //del==dequeue
    front=front+1;//used to remove the front pointer of the queue to the next element
    return Q[front];
}

void readGraph(){
    ifstream fp("bfs_dfs.txt");
    if(!fp){
        cout << "File open failed.\n";
        return;
    }
    fp >> n;
    cout << "Number of vertices... " << n << "\n";
    for(int i=0;i<n;i++){ //outer loop
        for(int j=0;j<n;j++){ //inner loop
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

void bfs(int v){   
    int u;//key variable representing the current variable that is being processed
    for(u=0;u<n;u++)//cause we have to traverse through all the vertices, not just v
        visit[u]=0;
    insert(v);//inserting the vertex in the queue
    visit[v]=1;
    while(!isEmpty()){ //while the queue is not empty
        u=del();//in each iteration,the vertex at the front of the queue is taken out and placed in u
        cout << char(u + 'A') << " -> ";//and printed
        for(int j=0;j<n;j++){//now for its neighbours
            if(arr[u][j]==1){//if there is an adjacent edge between u and j
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
    v = v - 'A';//converts the character input to integer index
    cout << "BFS: ";
    bfs(v);
    return 0;
}