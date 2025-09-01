#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
using state = pair<int,int>;

int n, m;
vector<vector<int>> dist, grid;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isvalid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && dist[x][y] == -1);
}

void bfs(queue<state>& q) {
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        int x = s.F, y = s.S;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isvalid(nx, ny)) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    dist.assign(n, vector<int>(m, -1));

    queue<state> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    bfs(q);

    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0 && dist[i][j] != -1) {
                ans = max(ans, dist[i][j]);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
