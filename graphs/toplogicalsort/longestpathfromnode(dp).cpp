#include<bits/stdc++.h>
using namespace std;
vector<int> topo;
vector<int> visited;
vector<vector<int>> g;

//from dp
int dp[100100];
int rec(int node){
    if(dp[node]!=-1) return dp[node];
int ans =1;
for(auto v: g[node]){
    ans = max(ans, 1+rec(v));
}
return dp[node]= ans;
}
int main(){
int n,m;
cin>>n>>m;
g.resize(n+1);
visited.assign(n+1,0);
for(int i =0; i<m; i++){
    int a,b;
    cin>> a>>b;
    g[a].push_back(b);
}
// for(int i =0; i<=n; i++){
//     if(!visited[i]){
//         topo_dfs(i);
//     }
// }
// reverse(topo.begin(), topo.end());
memset(dp,-1,sizeof(dp));
int ans=0;
for(int i =1; i<=n;i++){
    ans = max(ans,rec(i));
}
cout<<ans<<endl;
}