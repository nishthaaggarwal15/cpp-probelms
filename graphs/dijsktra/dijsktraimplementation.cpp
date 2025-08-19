#include<bits/stdc++.h>
using namespace std;
int n,m;
#define F first 
#define S second
#define ll long long
#define INF 1e18
#define mp make_pair
using state = pair<ll,int>; // distance, node

vector<vector<pair<int,int>>> g; // node, weight
vector<int> visited;

void dijkstra(int sc){
    vector<ll> dist(n+1, INF);
    dist[sc] = 0;
    priority_queue<state> q;
    q.push({-0, sc}); // -distance, node

    while(!q.empty()){
        state s = q.top(); q.pop();
        int node = s.S;
        if(visited[node]) continue;
        visited[node] = 1;

        for(auto v : g[node]){
            int neigh = v.F;
            int weight = v.S;
            if(dist[neigh] > dist[node] + weight){
                dist[neigh] = dist[node] + weight;
                q.push({-dist[neigh], neigh});
            }
        }
    }

    // Print distances
    for(int i=0;i<n;i++){
        cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

int main(){
    cin >> n >> m;
    g.assign(n+1, {});
    visited.assign(n+1, 0);

    for(int i=0;i<m;i++){
        int a,b,c; // edge a-b with weight c
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dijkstra(0); // source = 0
    return 0;
}
