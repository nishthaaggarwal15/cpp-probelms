#include<bits/stdc++.h>
using namespace std;
int n,m,k;
using state = pair<int,int>;
#define mp make_pair
#define INF 1e9
#define F first
#define S second
vector<vector<pair<int,state>>>g;
int dist[1001][1001]; //{node, fuel left}
int visited[1001][1001];// '''''''''''
int c[1001];

void dijkstra(state st){
    //initializing values
for(int i =0;i<=n; i++){
    for(int j =0; j<=k; j++){
        dist[i][j]=INF;
        visited[i][j]=0;
    }
}
// make queue and push start
priority_queue<pair<int,state>>q; //- {dist,{node,fuel}}
dist[st.F][st.S]=0;
q.push(mp(0,st));
//until queue is empty
while(!q.empty()){
    auto val = q.top();
    q.pop();
    int curr_dist = val.F;// dist(cost)
   int curr_state_node = val.S.F;// {node,fuel left}
   int curr_state_fuel = val.S.S;
/// 1.check visited
if(visited[curr_state_node][curr_state_fuel]==1) continue;
visited[curr_state_node][curr_state_fuel]==1;
///2.all neighbours
for(auto v : g[curr_state_node]){
    int newnode_fuel= v.S.F;
    int newnode = v.F;
    int newnode_dist = v.S.S;
///3.relax
if(curr_state_fuel>=newnode_fuel){ // currnode fuel left >=neighnode fuel to reach it
if(dist[newnode][curr_state_fuel-newnode_fuel]> curr_dist){
    dist[newnode][curr_state_fuel-newnode_fuel]=curr_dist;
    q.push(mp(-dist[newnode][curr_state_fuel-newnode_fuel],mp(newnode,curr_state_fuel-newnode_fuel)));
}
}
}
/// 4. extra relaxation here, is option to refill
//If buying petrol here improves (reduces) the cost to reach this state, then update it.
if(curr_state_fuel<k){
    if(dist[curr_state_node][curr_state_fuel+1]> curr_dist+c[curr_state_node]){
        dist[curr_state_node][curr_state_fuel+1]= curr_dist+c[curr_state_node];
        q.push(mp(-dist[curr_state_node][curr_state_fuel+1],mp(curr_state_node,curr_state_fuel)));
    }
}
}


}
void solve(){
cin>>n>>m>>k;
g.resize(n+1);
int st_node = 1; int en_node =n;
for(int i =1; i<=n; i++)cin>>c[i];
for(int i =0; i<m; i++){
    int p, d, a,b;
     g[a].push_back(mp(b, mp(p,d)));// {node{fuel,dist}}
     g[b].push_back(mp(a,mp(p,d)));
     // g{a- par node, b = node, p = fuel cost, d= dist}
}
state st = {st_node,0};
dijkstra(st);
}
int main(){
    solve();
    return 0;
}