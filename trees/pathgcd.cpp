#include <bits/stdc++.h>
#define int long long
using namespace std;

#define pb push_back
#define foe(i, a, b) for (int i = a; i <= b; i++)

int n, q;
vector<int> value;
vector<vector<int>> g, par, dp;
vector<int> dep;

// DFS to build par and dp tables
void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node][0] = parent;
    dp[node][0] = value[node]; // node itself

    foe(i, 1, 20){
        par[node][i] = par[par[node][i-1]][i-1];
        dp[node][i] = __gcd(dp[node][i-1], dp[par[node][i-1]][i-1]);
    }

    for(auto v : g[node]){
        if(v != parent){
            dfs(v, node, depth + 1);
        }
    }
}

// Answer a single GCD query between u and v
int computePathGCD(int u, int v){
    if(dep[u] < dep[v]) swap(u,v);

    int k = dep[u] - dep[v];
    int ans = 0;

    // Bring u to same depth as v
    foe(i, 0, 20){
        if(k & (1<<i)){
            ans = __gcd(ans, dp[u][i]);
            u = par[u][i];
        }
    }

    if(u == v) return __gcd(ans, value[u]);

    // Lift both u and v until LCA
    for(int i = 20; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            ans = __gcd(ans, dp[u][i]);
            ans = __gcd(ans, dp[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }

    ans = __gcd(ans, value[u]);
    ans = __gcd(ans, value[v]);
    ans = __gcd(ans, value[par[u][0]]); // LCA value
    return ans;
}

// Initialize/reset arrays for a test case
void init(int nodes){
    value.resize(nodes + 1);
    g.clear();
    g.resize(nodes + 1);
    par.assign(nodes + 1, vector<int>(21, 0));
    dp.assign(nodes + 1, vector<int>(21, 0));
    dep.assign(nodes + 1, 0);
}

// Solve a single test case
void solve(){
    cin >> n;
    init(n);

    foe(i, 1, n) cin >> value[i];

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 0, 0);

    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << computePathGCD(x, y) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
