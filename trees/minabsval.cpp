#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int n;
int val[N], ans[N];
vector<int> g[N];
multiset<int> mt;

void insert_val(int x) {
    mt.insert(x);
}
void remove_val(int x) {
    mt.erase(mt.find(x));
}
int query(int x) {
    int res = 1e9;
    auto it = mt.lower_bound(x);
    if (it != mt.end()) res = min(res, abs(*it - x));
    if (it != mt.begin()) {
        it--;
        res = min(res, abs(*it - x));
    }
    return res == 1e9 ? -1 : res;  // if no ancestor yet
}

void dfs(int node, int par) {
    ans[node] = query(val[node]);
    insert_val(val[node]);
    for (auto v : g[node]) {
        if (v != par) dfs(v, node);
    }
    remove_val(val[node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);  // assuming root is 1

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
