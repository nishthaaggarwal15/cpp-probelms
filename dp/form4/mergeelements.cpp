#include<bits/stdc++.h>
using namespace std;

int n;
int dp[1001][1001];
int a[1001];
int sumval[1001][1001];

int rec(int l, int r){
    // base case
    if(l >= r) return 0;

    // cache check
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    // transition
    int ans = 1e9;
    for(int mid = l; mid < r; mid++){
        ans = min(ans, rec(l, mid) + rec(mid+1, r) + sumval[l][mid] * sumval[mid+1][r]);
    }

    // save and return
    return dp[l][r] = ans;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sumval[i][i] = a[i] % 100;
    }

    // Precompute sums
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            sumval[i][j] = (sumval[i][j-1] + a[j]) % 100;
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(1, n) << endl;

    return 0;
}
