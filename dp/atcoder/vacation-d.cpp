#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int dp[100001][4];
int points[100001][4];

int rec(int level, int prevchoice) {
    if (level == n) return 0;
    if (dp[level][prevchoice] != -1) 
        return dp[level][prevchoice];
    int ans = 0;
    for (int currchoice = 1; currchoice <= 3; currchoice++) {
        if (currchoice != prevchoice) {
            ans = max(ans, points[level][currchoice] + rec(level + 1, currchoice));
        }
    }
    return dp[level][prevchoice] = ans;
}

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i][1] >> points[i][2] >> points[i][3];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
    return 0;
}
