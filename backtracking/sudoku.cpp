#include<bits/stdc++.h>
using namespace std;
int n;
const int boardsize = 4;
const int cellsize = 2;
int ans =0;
int board[boardsize][boardsize];
bool check(int choice , int row , int col){
    //for row
    for(int c = 0; c<boardsize; c++){
        if(c!= col && board[row][c]=choice){//every col of current row 
            return false;
        }
    }
    //for col
     for(int r = 0; r<boardsize; r++){
        if(r!= row && board[r][col]=choice){//every row of current col
            return false;
        }
    }
    //for square
    int str = (row/cellsize)*row;
    int stc = (col/cellsize)*col;
    for(int dx = 0; dx<cellsize; dx++){
        for(int dy =0; dy<cellsize; dy++){
            if(str+dx==row && stc+dy==col)continue;
            if(board[str+dx][stc+dy]==choice) return false;
        }
    }
    return true;
}
void rec(int row,int col){
    //base case
    if (col==boardsize){
rec(row+1,col);
return;
    }
    if(row==boardsize){
        ans++;
        cout<<ans<<endl;
        for(int i =0 ; i<boardsize; i++ ){
            for(int j =0; j<boardsize; j++){
                cout<<board[i][j]<<" ";
            }
        }
    }
    //recursive case
    //we place
if(board[row][col]==0){
for(int ch =1; ch<=boardsize; ch++){
    if(check(ch, row,col)){
        board[row][col]=1;
        rec(row,col+1);
        board[row][col]=0;
    }
}
}
    //we are not placing 
    if(check(board[row][col], row,col)){
        rec(row,col+1);
    }
}
 int main(){
cin>>n;
    return 0;
 }