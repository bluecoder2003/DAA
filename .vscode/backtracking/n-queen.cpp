#include<iostream>
using namespace std;
bool issafe(int** arr,int x,int y,int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false; //if the queen is already place or not
        }

    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;//check for left upper corner
    }


    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;//check for right upper corner
    }
    return true;
}
int totalSolutions = 0;

bool nQueen(int** arr, int x, int n) {
    if(x == n) { // All queens are placed
        totalSolutions++;
        // Print the board
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == 1) {
                    cout << 'Q' << " ";
                } else {
                    cout << '.' << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        return false; // return false to find all solutions
    } //base case


    bool res = false;
    for(int col = 0; col < n; col++) {
        if(issafe(arr, x, col, n)) {// To check if placing a queen at position (x, col) on the board is safe
            arr[x][col] = 1;
            // To place a queen at position (x, col)
            res = nQueen(arr, x + 1, n) || res;
            // If placing queen in this position doesn't lead to a solution, then remove queen from this position (backtracking)
            arr[x][col] = 0;
        }
    }
    return res;
}

int main() {
    int n;
    std::cout << "Enter the number of Queens:";
    std::cin >> n;
    int** arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n](); // Value initialization will set all elements to zero
    }
    nQueen(arr, 0, n);
    cout << "Total solutions: " << totalSolutions << "\n";
    return 0;
}