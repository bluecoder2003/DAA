#include<iostream>
#include<fstream>

using namespace std;

void initialize(int* x, int n){
    for(int i = 1; i <= n; i++){
        x[i] = 0;
    }
}

void printResult(int* x, int n){
    for(int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << "\n";
}

void nextValue(int** graph, int* x, int n, int m, int k){
    do{
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0){
            return;
        }
        int j;
        for(j = 1; j <= n; j++){
            if(graph[k][j] == 1 && x[j] == x[k]){
                break;
            }
        }
        if(j == n + 1){
            return;
        }
    }
    while(true);
}

void mcoloring(int** graph, int n, int k, int* x, int m){
    do{
        nextValue(graph, x, n, m, k);
        if(x[k] == 0){
            return;
        }
        if(k == n){
            printResult(x, n);
        }
        else{
            mcoloring(graph, n, k + 1, x, m);
        }
    }
    while(true);
}

int main(){
    int** graph = new int*[20];
    for(int i = 0; i < 20; i++){
        graph[i] = new int[20];
    }
    int* x = new int[100];
    int n, m;
    ifstream file("color.txt");
    if(!file){
        cout << "Error";
        exit(1);
    }
    file >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            file >> graph[i][j];
        }
    }
    file.close();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nEnter the no of colors:";
    cin >> m;
    initialize(x, n);
    mcoloring(graph, n, 1, x, m);
    delete[] x;
    for(int i = 0; i < 20; i++){
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}