#include<bits/stdc++.h>
using namespace std;
const int boardsize = 9;
 const int cellsize = 3;
int board [boardsize][boardsize];
bool check(int choice, int row, int col){
// for row 
for(int c=0; c<col; c++){
    if(c!= col && board[row][c]==choice) return false; 
}
// for col
for(int r=0; r<row; r++){
    if(r!= row && board[r][col]==choice) return false; 
}

//for square
int str = (row/cellsize)*cellsize;
int src = (col/cellsize)*cellsize;
for(int dx = 0; dx<cellsize; dx++){
    for(int dy = 0; dy<cellsize; dy++){
        int sr = dx+str;
        int sy = dy+stc;
        if(sr==row && sy == col) continue;
        if(board[sr][sy]==choice) return false;
    }
}
return true;
} 
void rec(int row, int col){
//base case
if(col==boardsize){
    rec(row+1,0);
    return;
}
if(row==boardsize){
    for(int i =0; i<boardsize;i++){
        for(int j =0; j<boardsize; j++){
            cout<< board[i][j];
        }
    }
}

if(board[row][col]=='.'){
    for(int choices = 1; choices<=boardsize; choices+= ){
        if(check(choices, row, col)){
            board[row][col]= choices;
            rec( row, col+1);
        }
    }
} else{
    if(check(board[row][col], row,col)){
        rec(row,col+1);
    }
}
}
int main (){
    return 0;

}