#include<bits/stdc++.h>
using namespace std;
using state = pair<int,int>;
int n,m;
vector<vector<state>> g;
int dist[100100];
deque <int> dq;
void O1bfs(int sc){
for(int i =1; i<=n; i++){
    dist[i]= 1e9;
}
dist[sc]=0;
dq.push_back(sc);
while(!dq.empty()){
    int node = dq.front();
    dq.pop_front();
    for(auto v: g[node]){
        int neigh = v.first;// current negihbour of g
        int weight = v.second;//current neighbour's weight
        if(dist[neigh]> dist[node]+weight){
            dist[neigh]= dist[node]+weight;
            if(weight==0){//push below
                dq.push_front(neigh);
            } else{//push above
                dq.push_back(neigh);
            }
        }
    }
}
}
void solve(){
    cin>>n>>m;
g.resize(n+1);
for(int i =0; i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
}
int sc;
cin>>sc;
O1bfs(sc);
}
int main(){
    solve();
    return 0;
}