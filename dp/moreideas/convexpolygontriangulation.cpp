#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define endl '\n'


const int inf = 1e18;


int n;
vector<int> val;
int dp[105][105];


// rec: min cost of triangulating verices [l,....,r]
int rec(int l, int r){
    // pruning
    if(l > r){
        return inf;
    }
    // base case
    if(l+1 == r){
        return 0;
    }
    // cache check
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    // transitions
    int ans = inf;
    for(int mid=l+1; mid<r; mid++){
        ans = min(ans, rec(l, mid) + rec(mid, r) + val[l]*val[mid]*val[r]);
    }
    // save and return
    return dp[l][r] = ans;
}


void solve(){
    cin>>n;
    val.resize(n);
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, n-1)<<endl;
}


signed main()
{
    ios
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
