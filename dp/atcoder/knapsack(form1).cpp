#include<bits/stdc++.h>
using namespace std;
#define int long long
int N,W;
vector<int>weight,value;
const int INF=1e8;
int dp[101][100001];
int rec(int level,int curweigh){
    //pruning
    if(curweigh>W) return -INF;
    //base case
    if(level==N){
       return 0;
    }
    //caching
    if(dp[level][curweigh]!=-1) {
        return dp[level][curweigh];
    }
    //transition
    //not take
    int ans1=rec(level+1,curweigh);
    //for take we need to check conditions
    //take
    int ans2=-INF;
    if(curweigh+weight[level]<=W)
    ans2=value[level]+rec(level+1,curweigh+weight[level]);
    //this dp is returning max val
    int ans=max(ans1,ans2);
    //save and return
    dp[level][curweigh]=ans;
    return ans;
}
void solve(){
    cin>>N>>W;
    weight.resize(N);
    value.resize(N);
    for(int i=0;i<N;i++){
        cin>>weight[i]>>value[i];
    }
    memset(dp,-1,sizeof(dp));//dp array ko -1
    cout<<rec(0,0)<<endl;
}
signed main(){
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
  
}