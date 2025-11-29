#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int isPal[205][205];
int dp[205][205];

// Check if a[l..r] is palindrome
int checkPal(int l, int r) {
    if (l >= r) return 1;
    int &res = isPal[l][r];
    if (res != -1) return res;

    if (a[l] == a[r] && checkPal(l + 1, r - 1))
        return res = 1;
    return res = 0;
}

// Minimum operations to delete a[l..r]
int solveDP(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    if (checkPal(l, r)) return 1;

 if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;

    // Case 1: If boundaries match, remove middle first
    if (a[l] == a[r])
        ans = min(ans, solveDP(l + 1, r - 1));

    // Case 2: Try splitting
    for (int mid = l; mid < r; mid++)
        ans = min(ans, solveDP(l, mid) + solveDP(mid + 1, r));

    return dp[l][r] = ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(isPal, -1, sizeof(isPal));
    memset(dp, -1, sizeof(dp));

    cout << solveDP(0, n - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
