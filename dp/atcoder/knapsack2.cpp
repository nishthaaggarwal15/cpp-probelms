#include<bits/stdc++.h>
using namespace std;
int weight[101];
int profit[101];
int dp[101][100100];
int n; int w ;
const int INF = 1e9+7;
int rec(int level, int p){
    if(level==n){
        if(p==0){
            return 0;
        }
        return INF;
    }
    if(dp[level][p]!=-1){
        return dp[level][p];
    }
    int ans = rec(level+1,p);
    if(p>=profit[level]) ans = min(ans, rec(level+1,p-profit[level])+weight[level]);
    
    return dp[level][p]= ans; 
}
int main(){
     cin>> n>> w;
     for(int i =0; i<n;i++){
        cin>> weight[i]>>profit[i];
     }
     memset(dp, -1, sizeof(dp));
     int ans=0;
     for(int prof=1; prof<=100000; prof++){
        if(rec(0,prof)<=w) ans = prof;
     }
   cout<<ans<<endl;
    return 0;
}