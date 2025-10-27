#include<bits/stdc++.h>
using namespace std;
int n;
int x,k;
int t[100100], s[100100];
int dp[1001][1001][12];
int rec(int level, int timetaken, int itemtaken){
    if(level==n){//base case
        return 0;
    }
    //if already saved return that vlaue
    if(dp[level][timetaken][itemtaken]!=-1){
        return dp[level][timetaken][itemtaken];
    }
    int ans = rec(level+1, timetaken, itemtaken);//not take the item
    if(timetaken+t[level]<=x && itemtaken+1<=k){ //check
        ans = max(ans, s[level]+rec(level+1, timetaken+t[level], itemtaken+1));
        //take the time and return max of ans 
    }
ans = dp[level][timetaken][itemtaken];
return ans;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i] >> s[i];
    cin >> x >> k;

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

