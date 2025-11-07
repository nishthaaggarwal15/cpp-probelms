#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int n, m, K;
vector<vector<int>> grid;
int dp[205][205][405];
bool seen[205][205][405];

int rec(int row, int col, int kleft) {
    if (row < 0 || col < 0) return 0;
    if (row == 0 && col == 0) {
        if (grid[row][col] == 0) return 1;
        if (grid[row][col] == 1 && kleft > 0) return 1;
        return 0;
    }
    if (seen[row][col][kleft]) return dp[row][col][kleft];
    seen[row][col][kleft] = true;
    int ans = 0;
    if (grid[row][col] == 0)
        ans = (rec(row - 1, col, kleft) + rec(row, col - 1, kleft)) % MOD;
    else if (kleft > 0)
        ans = (rec(row - 1, col, kleft - 1) + rec(row, col - 1, kleft - 1)) % MOD;
    return dp[row][col][kleft] = ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> K;
        grid.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k <= K; k++)
                    seen[i][j][k] = false;
        long long ans = rec(n - 1, m - 1, K) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
