#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int m;
const int INF =1e9;
int w[1001];
int v[1001];
int dp[1001][1001][1001];
int W;
int rec(int level, int wleft, int itemleft){
if(level==n){
    int sumoftaken = W-wleft;
    if(sumoftaken%m==0){
        return 0;//valid
    }else{
        return -INF;
    }
}
if(dp[level][wleft][itemleft]!=-1){
return dp[level][wleft][itemleft];
}
int ans = rec(level+1,wleft,itemleft);
if(wleft>= w[level]&&itemleft>0){
ans = max(ans, v[level]+rec(level+1,wleft-w[level],itemleft-1));
}
dp[level][wleft][itemleft]=ans;
return ans;
}

int main(){
    cin>>n;
    cin>>k;
    cin>>m;
    for(int i =0; i<n; i++){
        cin>>w[i]>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W,k)<<endl;
   
    return 0;
}