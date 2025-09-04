#include<bits/stdc++.h>
using namespace std;
using state = pair<int,int>;
int n,m;
vector<vector<state>>g;
const int INF =1e9;
#define F first
#define S second
inline int get_in(int tier){
return n+tier;
}
inline int get_out(int tier){
return n+tier+3;
}
vector<int>dis;
vector<int>vis;
void dijkstra(vector<int>src){
dis.resize(n+7,INF);
vis.resize(n+7,0);
priority_queue<state>pq;
for(auto v: src){
    pq.push({-0,v});
    dis[v]=0;

}
while(!pq.empty()){
    state s = pq.top();
    pq.pop();
    int cur_dist = s.F;
    int cur_node = -s.S;
    if(vis[cur_node]==1) continue;
    vis[cur_node]=1;
    for(auto v: g[cur_node]){
        if(dis[v.F]>dis[cur_node]+v.S){
            dis[v.F]=dis[cur_node]+v.S;
pq.push({dis[v.F],v.F});
        }
    }
}
}
void solve(){
    //taking input
    cin>>n>>m;
    g.resize(n+7);// because of 6 extra tier nodes
    int a,b,c;
    cin>>a>>b>>c;
    int tier[n+1];
    for(int i =1; i<=n; i++){
        cin>>tier[i];
    }
    //making rail graph
    for(int i =0; i<m;i++){
        int x,y,z;
cin>> x>>y>>z;
g[x].push_back({y,z});
g[y].push_back({x,z});
    }
    //build aiport b/w cities
    g[get_in(1)].push_back({get_out(2),a});
       g[get_in(1)].push_back({get_out(3),c});
          g[get_in(2)].push_back({get_out(1),a});
             g[get_in(2)].push_back({get_out(3),b});
                g[get_in(3)].push_back({get_out(1),c});
                   g[get_in(3)].push_back({get_out(2),b});
    //connecting rail and airport
    vector<int>src;
    for(int i =1; i<=n; i++){
        g[i].push_back({get_in(tier[i]),0});
        g[get_out(tier[i])].push_back({i,0});
        if(tier[i]==1) src.push_back(i);
    }
    // dijkstra
    dijkstra(src);
    // print 
    for(int i =1; i<=n;i++){
        cout<< i<<" "<< dis[i]<<endl;
    }
}
int main(){
return 0;    
}