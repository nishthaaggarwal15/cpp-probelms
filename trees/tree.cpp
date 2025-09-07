#include<bits/stdc++.h>
using namespace std;
vector<int>g[100100];
int dep[100100];//depth
int par[100100];//parent
bool isleaf[100100];//leaf
int subtreesz[100100];//subtree size
int numchild[100100]; // number of child
// if we want path, take v and keep traversing par[] until 4 and print all parents
// if we want a dist b/w u and v, call dfs(u,0,0) & depth of v will be the distpv
void dfs(int node, int parent, int depth){
dep[node]= depth;
par[node]= parent;
subtreesz[node]=1;
numchild[node]=1;
for(auto v : g[node]){
    if(v!=parent){
        numchild[node]++;
        dfs(v,node,depth+1);
        subtreesz[node]+= subtreesz[v];
    }
}
if(numchild[node]==0){
    isleaf[node]=1;
}
}
void solve(){
int n;
cin>>n;
for(int i =0; i<n-1; i++){
int a ,b;
cin>>a>>b;
g[a].push_back(b);
g[b].push_back(a);
}
dfs(1,0,0);
}
int main(){
    return 0;
}