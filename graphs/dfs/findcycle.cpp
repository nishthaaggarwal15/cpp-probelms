//directed graph
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> vis;
bool is_cycle = false;
void dfs(int node){
vis[node]=2;
for(auto v : g[node]){
    if(vis[v]==1) dfs(v);//forward edge

    else if(vis[v]==2) is_cycle = true;
    else if(vis[v]==3){
        //cross edge
    }
}
vis[node]=3;
}
void solve(){
    cin>>n>>m;
g.resize(n);
vis.assign(n,1);
for(int i =0; i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
for(int i =0; i<n; i++){
    if(vis[i]=1){
        dfs(i);
    }
}
if(is_cycle) cout<<"yes"<<endl;
else cout<<"no"<<endl;
}
int main(){
    
    return 0;
}