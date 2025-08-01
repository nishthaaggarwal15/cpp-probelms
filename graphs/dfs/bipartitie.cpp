#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int>visited;
bool is_bipartite = true;
 void dfs(int node,int color){
visited[node]= color;
for(auto v: g[node]){
    if(!visited[v]){
        dfs(v,3-color);
    } else if(visited[node]==visited[v]){
        is_bipartite= false;
    }
}
 }
 void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    visited.resize(n+1);
    for(int i =0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int num_comp =0;
    for(int i =1; i<=n; i++){
     if(!visited[i]){
        dfs(i, 1);
        num_comp++;
     }
    }
    cout<<is_bipartite<<endl;
    for(int i =1; i<=n; i++){
        cout<<i<<":"<< visited[i];
    }
 }
 int main(){
    solve();
    return 0;
 }