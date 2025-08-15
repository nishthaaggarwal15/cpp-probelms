#include<bits/stdc++.h>
using namespace std;
vector<int> topo;
vector<int> visited;
vector<vector<int>> g;
void topo_dfs(int node){
visited[node]=1;
for(auto v: g[node]){
    if(!visited[v]) {
        topo_dfs(v);
    }
}
topo.push_back(node);
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
for(int i =0; i<=n; i++){
    if(!visited[i]){
        topo_dfs(i);
    }
}
reverse(topo.begin(), topo.end());
}