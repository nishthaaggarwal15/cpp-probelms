#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>arr;
int dp[1001][1001];
int rec(int row, int col){
if(row>=m|| col>=n){
    return 1e8;
}
// base case
if(row==n-1&& col == m-1){
return max(1, 1-arr[row][col]);
}
// cache
if(dp[row][col]!=-1){
    return dp[row][col];
}
// transition
int right = rec(row,col+1);
int down = rec(row+1,col);
int need= min(right,down)-arr[row][col];
if(need <=0) need =1;
dp[row][col]=need;
return need;
}
int main(){
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        memset(dp, -1, sizeof(dp));
        cout << rec(0, 0) << "\n";
    }
    return 0;
}