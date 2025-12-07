#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int n;
string s;

int rec(int i,int j){
    if(i>j) return 0;
    if(i==j){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = -1e9;
   if(s[i]==s[j]){
    ans = 2+rec(i+1,j-1);
   }
   ans = max(ans,rec(i+1,j));
   ans = max(ans, rec(i,j-1));
   return dp[i][j]=ans;
}
int main(){
int t;
cin>> t;
while(t--){
    cin>>s;
    n = s.size();
    memset(dp,-1,sizeof(dp));
    int ans = n-rec(0,n-1);
    cout<<ans<<endl;
    return 0;
}
}