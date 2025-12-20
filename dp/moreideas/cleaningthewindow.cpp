#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int n, m;
int dx[] = {-1, -1, -1};
int dy[] = {-1, 0, 1};
int solve(){
      vector<vector<int>> ans(n, vector<int>(m, 0));
    int maxabove =0;
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int maxAbove = 0;
            for (int d = 0; d < 3; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                    maxAbove = max(maxAbove, dp[ni][nj]);
            }
            ans[i][j] = (a[i][j] >= maxAbove ? 1 : 0);
            dp[i][j] = max(maxAbove, a[i][j]);
        }
    }

  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ans[i][j];
        cout << "\n";
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = 0;

        solve();
    }
    return 0;
}