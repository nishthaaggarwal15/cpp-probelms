#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15;

int n, m;
vector<vector<ll>> dist;

void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dist.assign(n + 1, vector<ll>(n + 1, INF));

    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // in case of multiple edges
    }

    floydWarshall();

    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && dist[i][j] < INF && dist[j][i] < INF) {
                ans = min(ans, dist[i][j] + dist[j][i]);
            }
        }
    }

    if (ans == INF) cout << "No cycle\n";
    else cout << "Shortest cycle length = " << ans << "\n";
}
