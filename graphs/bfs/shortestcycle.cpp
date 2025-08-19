#include<bits/stdc++.h>
using namespace std;
int n,m;

vector<vector<int>> g;
int bfs(){
    int ans = INT_MAX;
    for(int start = 1; start<=n; start++){
        vector<int>dist(n+1,-1);
          vector<int>par(n+1,-1);
          queue<int>q;
          dist[start]=0;
          q.push(start);
          while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : g[u]){
                if(dist[v]==-1){
                    dist[v]= dist[u]+1;
                    par[v]= u;
                    q.push(v);
                } else if( v!=par[u]) {
                    // and is still visited
                    //cycle found
                    ans = min(ans,dist[u]+ dist[v]+1);
            }
          }
    }
    }
    return (ans==INT_MAX)? -1: ans;
}
void solve(){
   cin>>n>>m;
     g.assign(n+1, {});  

    for(int i =0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        
    }
    int ans = bfs();
    cout<<ans<<'\n';
    
}
int main(){
 solve();
    return 0;
}