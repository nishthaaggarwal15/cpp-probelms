#include <bits/stdc++.h>
using namespace std;

using state = pair<int, int>;
#define F first
#define S second

int n, m;
vector<vector<int>> arr, visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isvalid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 0 && visited[x][y] == 0;
}

void bfs(int x, int y) {
    queue<state> q;
    vector<state> component;
    q.push({x, y});
    visited[x][y] = 1;
    component.push_back({x, y});

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (isvalid(nx, ny)) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
                component.push_back({nx, ny});
            }
        }
    }

    int compSize = component.size();
    if (compSize == 1) return;

    // Fill all component cells with size
    for (auto [cx, cy] : component) {
        arr[cx][cy] = compSize;
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.assign(n, vector<int>(m));
        visited.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> arr[i][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (arr[i][j] == 0 && visited[i][j] == 0)
                    bfs(i, j);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << arr[i][j];
                if (j != m - 1) cout << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
