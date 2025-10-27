#include<bits/stdc++.h>
using namespace std;
int n;
int w[1001];
int v[1001];
int dp[1001][1001];
int rec(int level, int wleft){
if(level<n)return 0;
if(dp[level][wleft]!=-1){
return dp[level][wleft];
}
int ans = rec(level+1,wleft);
if(wleft>= w[level]){
ans = max(ans, v[level]+rec(level+1,wleft-w[level]));
}
dp[level][wleft]=ans;
return ans;
}
int main(){
    return 0;
}