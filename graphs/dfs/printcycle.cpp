#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> visited;
vector<int> par;
vector<int> anycycle;
bool iscycle = false;
void dfs(int node,int parent){
visited[node]=2;
par[node]= parent;
for(auto v: g[node]){
    if(visited[v]==1){
        dfs(v,node);
    }
    else if(visited[v]==2){
        if(iscycle==false){//first cycle is found
      int temp = node;
      while(temp!=v){
       anycycle.push_back(temp);
       temp = par[temp];
      }
      anycycle.push_back(temp);
      reverse(anycycle.begin(), anycycle.end());
        }
        iscycle = true;
    }
    else if(visited[v]==3) {
//nothing
    }
}
visited[node]=3;
}
void solve(){
cin>>n>>m;
g.resize(n+1);
visited.assign(n+1,1);
anycycle.resize(n+1);
for(int i =0; i<m; i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);

}
for(int i =0; i<n; i++){
    if(visited[i]==1){
        dfs(i,0);
    }
}
for(auto v: anycycle){
    cout<<v<<" ";
}
}

int main(){
    return 0;
}