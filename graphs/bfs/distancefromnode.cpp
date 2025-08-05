#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visited;
vector<int> dist;

void bfs(int sourcenode) {
    queue<int> q;
    visited[sourcenode] = 1;
    dist[sourcenode] = 0;
    q.push(sourcenode);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto v : g[node]) {
            if (!visited[v]) {
                visited[v] = 1;
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1, 0);
    dist.resize(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int source;
    cin >> source; // example: source = 1
    bfs(source);

    for (int i = 1; i <= n; i++) {
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    solve();
    return 0;
}
