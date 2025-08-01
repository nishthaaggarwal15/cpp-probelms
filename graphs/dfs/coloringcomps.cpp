#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
void dfs(int node, int color){
visited[node]=color;
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
int color =1;
int numcomp =0;
for(int i =1;i<=n; i++){
    if(!visited[i]){
        dfs(i,color);
        numcomp++;
        color++;
    }
}
//print colors
for(int i =1; i<=n; i++){
    cout<<visited[i]<<" ";
}
//to check if they are in same component or not
int q;
cin>>q;
while(q--){
    int a,b;
    cin>>a>>b;
    if(visited[a]==visited[b]){
        cout<<"same component"<<endl;
    } 
    else{
        cout<<"diffrent component"<<endl;
    }
}
}
int main(){

}