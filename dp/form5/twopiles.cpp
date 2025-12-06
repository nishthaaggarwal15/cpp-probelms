#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1001][1001];
int rec(int x, int y){
//base case
if(x==0&&y==0){
    return 0;
}
// cache check
if(dp[x][y]!=-1){
    return dp[x][y];
}
// transition
int win =0;
for(int i =1; i<=x;i++){
    if(rec(x-i,y)==0){
        win = 1;
    }
}
for(int i =1; i<=min(x,y);i++){
    if(rec(x-i,y-i)==0){
        win = 1;
    }
}
for(int i =1; i<=y;i++){
    if(rec(x,y-i)==0){
        win = 1;
    }
}
// save and return
return dp[x][y]=win;
}
int main(){
    return 0;
}