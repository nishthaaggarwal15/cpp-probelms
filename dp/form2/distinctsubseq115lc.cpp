#include<bits/stdc++.h>
using namespace std;
long long dp[1001][1001];
string s,t;

long long rec(int i, int j){
  if (j == t.size()) return 1; 
        if (i == s.size()) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long ans =0;
    if(s[i]==t[j]){
        ans += rec(i+1,j+1);
    }
ans+= rec(i+1,j);
    dp[i][j]= ans;
    return ans;
}
    int numDistinct(string S, string T) {
        s=S;
        t = T;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
    int main(){
        string S,T;
        cin>>S>>T;
       int ans= numDistinct(S,T);
       cout<<ans<<endl;
        return 0;
    }