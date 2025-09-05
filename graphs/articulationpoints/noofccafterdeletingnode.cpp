#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> visited, tin, low;
int timer;
set<int> cutpoints;
int comp=0;
vector<int>extra;
vector<int>cnodes;
void dfs(int node, int p=-1){
visited[node]=1;
int child=0;
tin[node]=low[node]= timer++;
for(int to: g[node]){
    if(visited[to]){
     if(to==p) continue;
     low[node]= min(low[node],tin[to]);
    }else{
        cnodes.push_back(node);
        dfs(to,node);
    low[node]= min(low[node],low[to]);
    child++;
    }
}
if(p==0){
    extra[node]= child-1;
} else{
for(auto v: cnodes){
    if(low[v]>=tin[node]){
        //this child will have a seprate cc 
        extra[node]++;
    }
}
}
}
void solve(){
cin>>n>>m;
cin >> n >> m;
    g.resize(n + 1);
        extra.assign(n + 1,0);
    low.assign(n + 1, -1);
    tin.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    timer = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp++;
dfs(i);
        } 
    }
    for (int i = 1; i <= n; i++){
        cout<<i<<": "<< comp+extra[i]<<endl;
    }
}
int main(){
    return 0;
}