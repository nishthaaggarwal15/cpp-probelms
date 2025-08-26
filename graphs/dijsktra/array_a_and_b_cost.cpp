#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>mp;
vector<vector<pair<int,int>>> g;
#define F first
#define S second
int n,a,b;
vector<long long> dist;
#define INF 1e9
void dijkstra(int src){
dist.assign(g.size(), INF);
int sc = src;
dist[sc]=0;
priority_queue<pair<long long,int>> q;
q.push({0,sc});
while(!q.empty()){
    auto s = q.top();
    q.pop();
    int weigh = -s.F;
  int node = s.S;

    for(auto v :g[node]){
        int nxt = v.F;
            long long w = v.S; // node--> v dist
            if(dist[nxt] > dist[node] + w){
                dist[nxt] = dist[node] + w;
                q.push({-dist[nxt], nxt}); 
            }
        }
    }
}

void solve(){
    cin>>n>>a>>b;
for(int i =1; i<=n; i++){
    int x;
    cin>>x;
    mp[x].push_back(i);

}
g.resize(n+mp.size()+5);//+5 to be safe
for(int i =1; i<n; i++){
    g[i].push_back({i+1,a});
    g[i+1].push_back({i,a});
}
int disticntnode = n+1;
for(auto &v: mp){
    for(auto u : v.second){
        g[disticntnode].push_back({u,b});
        g[u].push_back({disticntnode,0});
    }
    disticntnode++;
}
int src ;
cin>>src;
dijkstra(src);
for(int i=1; i<=n; i++) cout << dist[i] << " ";
cout << "\n";

}
int main(){
    solve();
    return 0;
}