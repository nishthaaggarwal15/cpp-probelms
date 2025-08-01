#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
  int numnode =0;
void dfs(int node, int color){
visited[node]=color;
numnode++;
for(auto v: g[node]){
    if(!visited[v]){
        dfs(v,color);
    }
}
}
void solve(){
int n,m;
cin>>n>>m;
g.resize(n+1);
for(int i =0; i<m; i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    // if undirected 
    g[b].push_back(a);
}
vector<int> compsize;
int color =1;
int numcomp =0;
for(int i =1;i<=n; i++){
    if(!visited[i]){
        numnode =0;
        dfs(i,color);
        compsize.push_back(numnode);
        color++;
    }
}
//print colors
for(int i =1; i<=n; i++){
    cout<<visited[i]<<" ";
}
for(auto V: compsize){
    cout<<V<<" "; 
}
}
int main(){

}