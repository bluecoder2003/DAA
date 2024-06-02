#include<iostream>
#include<fstream>

using namespace std;

int n,graph[10][10],D[10][10],p[10][10]; 
//n=number of vertices, graph[10][10]=represents the weight of the edge from vertex i to vertex j,D[10][10]=stores shortest path distance btw vertices,p[10][10]=reconstruct shortest path

void readGraph(){
    int i,j;
    ifstream fp("floyd.txt");
    if(!fp){
        cout << "Error";
        exit(1);
    }
    fp >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            fp >> graph[i][j];
        }
    }
    fp.close();
}

void printGraph(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

void initialize(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            D[i][j]=graph[i][j];//sets it to the weight between i and j
            if(graph[i][j]==0 || graph[i][j]==999){
                p[i][j]=-1;
            }
            else{
                p[i][j]=i;
            }
        }
    }
}

void floydWarshall(){
    int i,j,k;
    initialize();
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
}

void printDMatrix(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }
}

void printPMatrix(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
}

void shortestPath(int i,int j){
    if(i==j){
        cout << i << "  ";
    }
    else if(p[i][j]==-1){
        cout << "no path";
    }
    else{
        shortestPath(i,p[i][j]);
        cout << j << "  ";
    }
}

void printShortestPath(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << "Shortest Path from " << i << " to " << j << ": " << D[i][j] << "\n";
            shortestPath(i,j);
            cout << "\n";
        }
        cout << "\n";
    }
}

int main(){
    readGraph();
    printGraph();
    floydWarshall();
    cout << "\nDistance Matrix:\n";
    printDMatrix();
    cout << "\nParent Matrix:\n";
    printPMatrix();
    cout << "\n";
    printShortestPath();
    return 0;
}