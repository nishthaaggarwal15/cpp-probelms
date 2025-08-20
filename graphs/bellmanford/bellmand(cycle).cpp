#include<bits/stdc++.h>
using namespace std;
int n,m;
using state = pair<int,int>;
vector<array<int,3>>g;
#define INF 1e9
int a,b,c;
bool bellman(int source){
vector<int>dist(n+1,INF);
dist[source]=0;
for(int i =1; i<=n-1;i++){
    for( auto v:g){
        int node = v[0];
        int neigh = v[1];
        int weight = v[2];
        if(dist[neigh]!=INF && dist[neigh]>dist[node]+weight){
            dist[neigh]= dist[node]+weight;
        }
    }
}

  for( auto v:g){
        int node = v[0];
        int neigh = v[1];
        int weight = v[2];
        if(dist[neigh]!=INF && dist[neigh]>dist[node]+weight){
            return true;//negative cycle exits
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m;i++){
        
        cin>>a>>b>>c;
        g.push_back({a,b,c});
    }
    bellman(1);
    return 0;
}