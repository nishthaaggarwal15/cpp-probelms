#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[1001][1001];
string s1,s2;
int rec(int i, int j){
    if(i>=n|| j>=m){
        return 0 ;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans= 0;
    if(s1[i]==s2[j]){
        ans = max(ans, 1+rec(i+1,j+1));
    } else{
        ans =0;
    }
    dp[i][j]= ans;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        n = s1.size();
        m = s2.size();
        memset(dp,-1, sizeof(dp));
        int res =0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
              res = max(res,rec(i,j));
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}