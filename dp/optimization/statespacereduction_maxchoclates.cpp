#include<bits/stdc++.h>
using namespace std;

int dp[51][51][51];
int arr[101][101];
int n, m;

int dx[] = {0, 1};
int dy[] = {1, 0};

int check(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m) return 1;
    return 0;
}

int rec(int i, int j, int a){
    int b = i + j - a;// optimized as i+j== a+b

    if(!check(i,j) || !check(a,b)) return -1e9;

    if(i == n-1 && j == m-1){
        return arr[i][j];
    }

    if(dp[i][j][a] != -1){
        return dp[i][j][a];
    }

    int initialcost = arr[i][j] + arr[a][b];
    if(i == a && j == b){
        initialcost = arr[i][j];
    }

    int ans = 0;

    for(int k1 = 0; k1 < 2; k1++){
        for(int k2 = 0; k2 < 2; k2++){
            int ni = i + dx[k1];
            int nj = j + dy[k1];
            int na = a + dx[k2];
            ans = max(ans, rec(ni, nj, na) + initialcost);
        }
    }

    return dp[i][j][a] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    memset(dp, -1, sizeof(dp));

    cout << rec(0, 0, 0) << "\n";
    return 0;
}
