#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int a,b;
//recursion
int rec(int x,int y){
//base case
if(x==0 && y==0) return 0; 
// cache check
if(dp[x][y]!=-1){
    return dp[x][y];
}
// transition
int ans=0;
for(int z=0; z<x; z++){
if(rec(x,z)==0){
    ans =1;
    break;
}
}
for(int z=0; z<y; z++){
if(rec(z,y)==0){
    ans =1;
    break;
}
}
// save and return 
for(int z=0; z<min(x,y); z++){
if(rec(x-z,y-z)==0){
    ans =1;
    break;
}
}
return dp[x][y]=ans;
}
//iterative
void solve(int x, int y){
    for(int x=0; x<=a; x++){
        for(int y =0; y<=b; y++){
            if(x==0 && y==0) dp[x][y]=0 ; 

// transition
int ans=0;
for(int z=0; z<x; z++){
if(dp[z][x]==0){
    ans =1;
    break;
}
}
for(int z=0; z<y; z++){
if(dp[z][x]==0){
    ans =1;
    break;
}
}
// save and return 
for(int z=0; z<min(x,y); z++){
if(dp[x-z][y-z]==0){
    ans =1;
    break;
}
}
        }
    }

}
int main(){
    return 0;
}