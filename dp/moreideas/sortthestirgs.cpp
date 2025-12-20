#include<bits/stdc++.h>
using namespace std;

#define int long long
const long long INF = 1e18;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
 vector<int> c(n);
        vector<string> s(n), r(n);

        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = 0; i < n; i++){
            cin >> s[i];
            r[i] = s[i];
            reverse(r[i].begin(), r[i].end());
        }

        vector<vector<long long>> dp(n, vector<long long>(2, INF));

        dp[0][0] = 0;
        dp[0][1] = c[0];

        for(int i = 1; i < n; i++){
            if(s[i-1] <= s[i]) //  dont reverse both curr and prev string
                dp[i][0] = min(dp[i][0], dp[i-1][0]);

            if(r[i-1] <= s[i]) // reverse prev string and not curr one
                dp[i][0] = min(dp[i][0], dp[i-1][1]);

            if(s[i-1] <= r[i]) // reverse curr one not previous one
                dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);

            if(r[i-1] <= r[i]) // reverse both 
                dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
        }

        long long ans = min(dp[n-1][0], dp[n-1][1]);

        cout << (ans >= INF ? -1 : ans) << "\n";
    }
}
