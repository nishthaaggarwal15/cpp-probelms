#include<bits/stdc++.h>
using namespace std;
int n;
int x[1001];
int dp[1001][1001];
int rec(int l, int r){
// base case
if(l+1==r){
    return;
}
// pruning
//cache checking
if(dp[l][r]!=-1){
    return dp[l][r];
}
// transition
int ans =1e9;
for(int p =l+1 ; p<=r-1;p++){
    ans = min(ans, x[r]-x[l]+rec(l,p)+rec(p,r));
}
// save and return
return dp[l][r]= ans;
}
int main(){

}