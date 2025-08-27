#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        components = n;
        for(int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            components--;
        }
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int,int>> edges(m+1);
    for(int i = 1; i <= m; i++) cin >> edges[i].first >> edges[i].second;

    vector<int> queryType(q), queryEdge(q, -1);
    vector<bool> removed(m+1, false);

    for(int i = 0; i < q; i++) {
        cin >> queryType[i];
        if(queryType[i] == 1) {
            cin >> queryEdge[i];
            removed[queryEdge[i]] = true;
        }
    }

    DSU dsu(n);

    // unite all edges that are NOT removed
    for(int i = 1; i <= m; i++) {
        if(!removed[i]) dsu.unite(edges[i].first, edges[i].second);
    }

    vector<int> answers;

    // Process queries in reverse
    for(int i = q-1; i >= 0; i--) {
        if(queryType[i] == 2) {
            answers.push_back(dsu.components);
        } else {
            dsu.unite(edges[queryEdge[i]].first, edges[queryEdge[i]].second);
        }
    }

    reverse(answers.begin(), answers.end());

    for(int x : answers) cout << x << "\n";

    return 0;
}
