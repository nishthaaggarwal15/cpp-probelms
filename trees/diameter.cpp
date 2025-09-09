#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int dep[100100];
void dfs(int node,int parent, int depth){
dep[node]=depth;
for(auto v: g[node]){
    if(v!=parent){
        dfs(v,node, depth+1);
    }
}
}
void solve(){
    int n;
    cin>>n;
    for(int i =1; i<n; i++){
        int a ,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    int match =1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[match]){
            match =j;
        }
    }
    dfs(match,0,0);
    int match =1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[match]){
            match =j;
        }
    }
    cout<<dep[match];
}
int main(){
    return 0;
}
//hello world