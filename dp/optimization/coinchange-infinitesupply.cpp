#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int arr[101];
int dp[101][101];
void solve(){

for(int level =n; level>=0 ;level--){
    for(int s = 0; s<=m; s++){
        if(level==n){
            if(s==0){
                dp[level][s]=1;
            } else{
                dp[level][s]=0;
            }
        }
       dp[level][s]=0;
        if(dp[level+1][s]){
            dp[level][s]=1;
        }
        if(s>=arr[level]&& dp[level][s-arr[level]]){
       dp[level][s]=1;
        }
    }
   
}
 cout<< dp[0][m]<<endl;
}
int main(){
    cin>>n>>m;
  
    memset(dp, -1, sizeof(dp));
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
      solve();
    return 0;
}