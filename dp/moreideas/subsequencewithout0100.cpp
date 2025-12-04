#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int n;
int rec(int level, int match){
    // pruning
    if(match==4){
        return 0 ;
    }
    // base case
    if(level==n){
        return 1;
    }
    // cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    // transition
    int ans = rec(level+1, match)+ rec(level+1, match+1);
    // save aand return
    return dp[level][match]= ans;
}
int main(){
    return 0;
}