#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101];
string s1,s2,s3;
int rec(int i, int j, int k){
    //base case 
    if(i>=s1.size()|| j>=s2.size()|| k>=s3.size()){
        return 0;
    }
    //pruning
    //cache check
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    //transition
    int ans =0;
    if(s1[i]==s2[j] && s2[j]==s3[k]){
        ans = max(ans, 1+ rec(i+1, j+1, k+1));
    }
  ans=max(ans,rec(i+1,j,k));
    ans=max(ans,rec(i,j+1,k));
    ans=max(ans,rec(i,j,k+1));
    

    //save and return
    dp[i][j][k]= ans;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2>>s3;
        memset(dp,-1,sizeof(dp));
        cout<<rec(0,0,0)<<"\n";
    }
    return 0;
}