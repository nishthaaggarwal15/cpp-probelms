#include<bits/stdc++.h>
using namespace std;
int n;
int depth[100100];
int par[100100];
vector<int>g[100100];
void dfs(int node , int parent, int depthh){
depth[node]= depthh;
par[node]= parent;
for(auto v: g[node]){
    if(v!=parent){
        dfs(v,node,depthh+1);
    }
}
}
void solve(){
cin>>n;
for(int i =0; i<n; i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
dfs(1,0,0);
int match = 1; 
for(int j=2; j<=n;j++ ){
if(depth[j]>depth[match]){
    match = j;
}
}
dfs(match,0,0);
match =1;
for(int j=2; j<=n; j++){
    if(depth[j]>depth[match]){
        match = j;
    }
}
vector<int> path;
int cur = match;
while(cur!=0){
    path.push_back(cur);
    cur = par[cur];
}

    int len = path.size();
    if (len % 2 == 1) {
        cout << path[len / 2] << "\n";  // one center
    } else {
        cout << path[len / 2 - 1] << " " << path[len / 2] << "\n";  // two centers
    }
}
int main(){
    return 0;
}