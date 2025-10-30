#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[1001][1001];
int dp[1001][1001];
bool done[1001][1001];


int rec(int row,int col){


    if(row<0 || col<0 ){
      return -1e9;
    }
   if(done[row][col]){
    return dp[col][col];
   }
    if(row==0 && col==0) return arr[0][0];
    int ans=-1e9;
    if(row!=0){
       ans=max(ans,rec(row-1,col) + arr[row][col]);
    }
    if(col!=0){
        ans=max(ans,rec(row,col-1) + arr[row][col]);
    }
   


    done[row][col]=1;
    return dp[row][col]= ans;
     
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }}
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,m-1)<<"\n";


}
