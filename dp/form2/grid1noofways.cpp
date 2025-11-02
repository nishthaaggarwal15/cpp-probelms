#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> grid;


int dp[1001][1001];
int rec(int row,int col){
if(row<=0 && col<=0 && grid[row][col]=='#'){
return 0;
}               
if(row==1&&col==1){
    return 1;
}      
if(dp[row][col]!=-1){
    return dp[row][col];
}                       
int ans = rec(row-1,col)+rec(row,col-1)    ;
dp[row][col]= ans;
return ans;         
}
int main(){
    return 0;
}