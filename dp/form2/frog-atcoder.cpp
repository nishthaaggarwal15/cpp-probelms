#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int mod = 1e9+7;

int n,k;
int arr[105000];
int dp[105000];
int rec(int level){
    if(level<0){
        return 0;
    }
    if(level==n-1){
        return 0;
    }
    if(dp[level]!=-1){
        return dp[level];
    }
    int ans =1e18;
    for(int jumps =1; jumps<=k; jumps++){
        if(level+jumps<n){
   ans = min(ans, rec(level+jumps)+abs(arr[level]-arr[level+jumps]));
        }
    }
    dp[level]=ans;
    return ans;
}

signed main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
cin>>n>>k;
for (int i = 0; i<n; i++)
{
    cin>>arr[i];
}
memset(dp,-1,sizeof(dp));
cout<<rec(0)<<endl; 
 
return 0;
}