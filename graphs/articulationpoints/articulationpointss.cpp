#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visited, tin, low;
int timer;
set<int> cutpoints;  // to store articulation points

void dfs(int node, int p = -1) {
    visited[node] = 1;
    tin[node] = low[node] = timer++;
    int children = 0;

    for (int to : g[node]) {
        if (to == p) continue;

        if (visited[to]) {
            // back edge
            low[node] = min(low[node], tin[to]);
        } else { // forward edge
            dfs(to, node);
            low[node] = min(low[node], low[to]);

            if (low[to] >= tin[node] && p != -1) {
                cutpoints.insert(node);
            }
            ++children;
        }
    }

    if (p == -1 && children > 1) {
        cutpoints.insert(node);
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    low.assign(n + 1, -1);
    tin.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    timer = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    // print articulation points
    cout << "Articulation points: ";
    for (int cp : cutpoints) cout << cp << " ";
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
