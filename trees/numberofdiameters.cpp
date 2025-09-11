#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;
int n, depth[MAXN], par[MAXN];
vector<int> g[MAXN];

void dfs(int node, int parent, int depthh) {
    depth[node] = depthh;
    par[node] = parent;
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, depthh + 1);
        }
    }
}

pair<int,int> farthest_node(int start) {
    dfs(start, 0, 0);
    int best = start;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > depth[best]) best = i;
    }
    return {best, depth[best]};
}

int count_deepest(int node, int parent, int targetDepth) {
    if (depth[node] == targetDepth) return 1;
    int cnt = 0;
    for (auto v : g[node]) {
        if (v != parent) cnt += count_deepest(v, node, targetDepth);
    }
    return cnt;
}

pair<int,long long> tree_diameter_and_count() {
    auto [u, _] = farthest_node(1);
    auto [v, D] = farthest_node(u);

    vector<int> path;
    int cur = v;
    while (cur != 0) {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    int len = path.size();

    if (len % 2 == 1) {
        int center = path[len / 2];
        int maxDepth = 0;
        for (auto v : g[center]) {
            dfs(v, center, 1);
            for (int i = 1; i <= n; i++) maxDepth = max(maxDepth, depth[i]);
        }

        vector<int> counts;
        for (auto v : g[center]) {
            dfs(v, center, 1);
            int cnt = count_deepest(v, center, maxDepth);
            if (cnt > 0) counts.push_back(cnt);
        }

        long long ways = 0;
        for (int i = 0; i < (int)counts.size(); i++) {
            for (int j = i + 1; j < (int)counts.size(); j++) {
                ways += 1LL * counts[i] * counts[j];
            }
        }
        return {D, ways};
    } else {
        int c1 = path[len/2 - 1], c2 = path[len/2];
        dfs(c1, c2, 0);
        int max1 = *max_element(depth+1, depth+n+1);
        int cnt1 = count_deepest(c1, c2, max1);

        dfs(c2, c1, 0);
        int max2 = *max_element(depth+1, depth+n+1);
        int cnt2 = count_deepest(c2, c1, max2);

        long long ways = 1LL * cnt1 * cnt2;
        return {D, ways};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto [diameter_length, num_diameters] = tree_diameter_and_count();
    cout << diameter_length << " " << num_diameters << "\n";

    return 0;
}
