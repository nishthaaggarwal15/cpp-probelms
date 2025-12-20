#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int arr[1001];
int n;
int rec(int l,int r, int x){
    if(l > r) return 0;
    if(dp[l][r][x]!=-1) return dp[l][r][x];


    int ans = -1e9;


    for(int mid = l+1;mid <= r;mid++){
        if(arr[mid] == arr[l]){
            ans = max(ans, rec(l+1,mid-1,0) + rec(mid,r,x+1));
        }
    }
    ans = max(ans, (x+1)*(x+1) + rec(l+1,r,0));


    return dp[l][r][x] = ans;
}



int main(){

   cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1, 0) << "\n";
    return 0;
}