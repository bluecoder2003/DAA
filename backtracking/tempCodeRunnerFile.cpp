#include<iostream>
using namespace std;

bool isSafe(int **board,int r,int c,int n){//c is the column index where you want to place the queen,r is the row index where you want to place the queen
    for(int i=0;i<r;i++){
        if(board[i][c]==1){
            return false;
        }
    }
    int x=r;
    int y=c;
    while(x>=0 && y>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }
    x=r;
    y=c;
    while(x>=0 && y<n){
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}
void printArray(int **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
                cout<<"Q ";
            }
            else{
                cout<<"_ ";
            }
        }
        cout<<endl;
    }
}
void nqueen(int **board,int r,int n){
    if(r==n){ //r=current row to place a queen
        printArray(board,n);
        cout<<endl;
        return;
    }
        for(int i=0;i<n;i++){//loop iterates over each column
            if(isSafe(board,r,i,n))
            {
            board[r][i]=1;
            nqueen(board,r+1,n);//moves to the next row
            board[r][i]=0;
            }
    }
}
int main(){
    int n;
    cout<<"Enter no of queens:"<<endl;
    cin>>n;
    int **board=new int*[n]; //each element points to the beginning of a row
    for(int i=0;i<n;i++){//for row iteration
        board[i]=new int[n];//allocates memory for each row of chessboard
        for(int j=0;j<n;j++){//initializes each cell of the allocated row to 0
            board[i][j]=0;
        }
    }
    nqueen(board,0,n);
    return 0;
}