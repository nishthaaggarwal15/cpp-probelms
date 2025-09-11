#include<bits/stdc++.h>
using namespace std;
int n;
int ans [100100];
int val[100100];
vector<int>g[100100];
void dfs(int node, int parent, int maxval, int minval){
    ans[node]= max(abs(maxval-val[node]), abs(minval-val[node]));
for (auto v: g[node]){
  if(v!=parent){
    dfs(v,node, max(maxval,val[node], min(minval, val[node])));
  }
}
}
void solve(){
cin>>n;
for(int i =1; i<=n; i++){
    cin>>val[i];
}
for(int i =0; i<n; i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
int root=1;
dfs(root,0, val[root], val[root]);
for(int i =1; i<=n; i++){
    cout<<ans[i]<<endl;
}
}
int main(){
    solve();
    return 0;
}