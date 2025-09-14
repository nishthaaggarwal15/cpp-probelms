#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
const int LOG = 20;
int n,q;
vector<int>g[N];
int up[N][LOG];
int depth[N];

void dfs(int v, int p){
    up[v][0]=p;
    for(int j =1; j<LOG; j++){
        if(up[v][j-1]!=-1){
            up[v][j]= up[up[v][j-1]][j-1];
        } else{
            up[v][j]=-1;
        }
    }
    for(int u : g[v]){
        if(u!=p){
            depth[u]= depth[v]+1;
            dfs(u,v);
        }
    }
}

int lift(int v, int k){
    for(int j =0; j<LOG; j++){
        if(k & (1<<j)){ 
            v=up[v][j];
            if(v==-1) break;
        }
    }
    return v;
}

int lca(int a, int b){
    if(depth[a]<depth[b]) swap(a,b);
    a = lift(a, depth[a]-depth[b]);// lift node a by depth difference
    if(a==b) return a;
    // jump upwards together
    for(int j = LOG-1; j>=0; j--){
        // if they are not equal move one step
        if(up[a][j]!=up[b][j]){
            a= up[a][j];
            b= up[b][j];
        }
    }
    return up[a][0];
}

int main(){
    cin>>n>>q;
    for(int i =0; i<n-1; i++){  
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth[1]=0;
    dfs(1,-1);
    return 0;
}
