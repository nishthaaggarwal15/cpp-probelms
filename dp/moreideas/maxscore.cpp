#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[1001][1001];
int dp[1001][1001][1005];

int rec(int row, int col, int sum){
    // pruning
    if (col < 0 || col >= m) return -1; 
    //base case
    if (row == 0){
        if (sum % k == 0) return sum;
        else return -2;
    }
    // cache check
    if (dp[row][col][sum] != -1) return dp[row][col][sum];

    int ans = -2;
// transition
    if (col - 1 >= 0)
        ans = max(ans, rec(row - 1, col - 1, sum + arr[row - 1][col - 1]));

    if (col + 1 < m)
        ans = max(ans, rec(row - 1, col + 1, sum + arr[row - 1][col + 1]));
//save and return
    return dp[row][col][sum] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        
        cin >> n >> m >> k;

        for (int i = 0; i < n; i++){
            string s;
            cin >> s;
            for (int j = 0; j < m; j++){
                arr[i][j] = s[j] - '0';
            }
        }

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                for(int x = 0; x < 1005; x++)
                    dp[i][j][x] = -1;

        int res = -1;

        for (int col = 0; col < m; col++){
            int ans = rec(n - 1, col, arr[n - 1][col]);
            res = max(res, ans);
        }

        cout << res << "\n";
    }
    return 0;
}
