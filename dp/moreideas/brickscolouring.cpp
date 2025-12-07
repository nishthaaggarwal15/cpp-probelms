#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9+7;
int dp[2001][2001];
int n;
int m;
int k;
int rec(int level, int j){
     if(j > k) return 0; 
    
    if(level == n){
        return (j == k);
    }

    if(dp[level][j]!=-1){
        return dp[level][j];
    }
    int ans = 0;
   
    ans = (ans + rec(level+1, j)) % MOD;//not take
   ans = (ans + (m-1) * rec(level+1, j+1)) % MOD;//take
    return dp[level][j]=ans;
}
signed main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        memset(dp, -1, sizeof(dp));

        long long result =(m * rec(1, 0)) % MOD;

        cout << result << "\n";
    }
    return 0;
}