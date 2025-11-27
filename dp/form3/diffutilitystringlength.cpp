#include<bits/stdc++.h>
using namespace std;
string x,y;
vector<vector<int>> dp;
int n,m;
int rec(int l1, int l2){
//base case
if(l1==n && l2==m){
    return 0;
}
//caching
if(dp[l1][l2]!=-1){
    return dp[l1][l2];
}
//transition
int ans = 1e9;
if(l1<n){
    ans = min(ans, rec(l1+1, l2)+1);
}
if(l2<m){
    ans = min(ans, rec(l1,l2+1)+1);
}
if(l1<n&& l2<m && x[l1]==y[l2]){
    ans = min(ans, rec(l1+1, l2+1)+1);
}
//save and return 
return dp[l1][l2]=ans;
}
int main(){
    return 0;
}