#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e15

int n, m;
vector<vector<ll>> dist;

void floydwarshal() {
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

void printdiameter() {
    ll ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] < INF) {
                ans = max(ans, dist[i][j]);
            }
        }
    }
    cout << (ans == -1 ? -1 : ans) << "\n"; // -1 if graph is disconnected
}

int main() {
    cin >> n >> m;
    dist.assign(n + 1, vector<ll>(n + 1, INF));

    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // multiple edges case
        dist[b][a] = min(dist[b][a], c); // if graph is undirected
    }

    floydwarshal();
    printdiameter();
    return 0;
}
