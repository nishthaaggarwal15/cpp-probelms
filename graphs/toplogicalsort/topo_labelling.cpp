#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> indeg;
vector<int> label;
int n, m;

void kahns() {
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) pq.push(i);
    }
    int curLabel = n;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        label[u] = curLabel--; // assign current largest label
        for (auto v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) pq.push(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    g.assign(n + 1, {});
    indeg.assign(n + 1, 0);
    label.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a); // reverse edges for labeling logic
        indeg[a]++;
    }

    kahns();

    if (*min_element(label.begin() + 1, label.end()) == 0) {// if ee cany assign labels to every node there might be a cycle
        cout << -1 << '\n'; 
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << label[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}