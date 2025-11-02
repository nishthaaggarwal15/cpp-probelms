#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[1001][1001];
int dp[1001][1001];

int rec(int row, int col) {
    if (row >= n || col >= m)
        return -1e8;
    if (row == n - 1 && col == m - 1)
        return grid[row][col];
    if (dp[row][col] != -1)
        return dp[row][col];
    int down = grid[row][col] + rec(row + 1, col);
    int right = grid[row][col] + rec(row, col + 1);
    
    return dp[row][col] = max(down, right);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
    return 0;
}
