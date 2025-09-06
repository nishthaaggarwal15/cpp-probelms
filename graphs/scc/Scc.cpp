#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>g,gr,sccs;
vector<int>vis;
stack<int>s;
//store nodes ny finish time
void dfs1(int node){
vis[node]=1;
for(int v: g[node]){
    if(!vis[v]){
        dfs1(v);
    }
}
s.push(node);//push when finished
}
void dfs2(int node, vector<int>&comp){
    vis[node]=1;
    comp.push_back(node);
for(int v: gr[node]){
    if(!vis[v]){
        dfs2(v,comp);
    }
}
}
void kosaraju(){
// step 1 dfs on original graph to sort all edges acc to finishing time
for(int i =0; i<n;i++){
    if(!vis[i])dfs1(i);
}
// dfs on reverse graph
fill(vis.begin(),vis.end(),0);
while(!s.empty()){
    int node= s.top(); s.pop();
    if(!vis[node]){
        vector<int> comp;
        dfs2(node,comp);
        sccs.push_back(comp);
    }
}
}
void solve(){
cin>>n>>m;
g.assign(n,{});
gr.assign(n,{});
vis.assign(n,0);
for(int i =0; i<m; i++){
    int a,b; cin>>a>>b;
    g[a].push_back(b);
     gr[b].push_back(a);
}
kosaraju();
 for (auto &comp : sccs) {
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }
}
int main(){
    solve();
    return 0;
}