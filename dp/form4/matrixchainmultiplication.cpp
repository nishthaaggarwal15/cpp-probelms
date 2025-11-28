#include<bits/stdc++.h>
using namespace std;
int x[1001], y[1001];
int n;
int dp[1001][1001];
int rec(int l, int r){
    //pruning
     if(l>r)return;
    //base case
    if(l==r) return 0;// if one matrix cost will be 0
    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    // transition
    int ans =1e9;
    for(int mid = l; mid<r; mid++){
        ans = min(ans, rec(l,mid)+ rec(mid+1,r)+ x[l]*y[mid]*y[r]);
    }
    // save and return
    return dp[l][r]= ans;
}
int main(){
    cin>>n;


	for(int i=1; i<=n; i++) {
		cin>>x[i]>>y[i];
	}


	memset(dp,-1,sizeof(dp));


	cout << rec(1,n) << endl;

    return 0;
}