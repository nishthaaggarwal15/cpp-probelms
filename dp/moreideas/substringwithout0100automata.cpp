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
   int ans =0;
   if(match==0){
    ans = rec(level+1,0)+rec(level+1,1);
   }
   else if(match==1){
    ans = rec(level+1,1)+rec(level+1,2);
   }
    else if(match==2){
    ans = rec(level+1,3)+rec(level+1,0);
   }
    else if(match==3){
    ans = rec(level+1,4)+rec(level+1,2);
   }
    // save aand return
    return dp[level][match]= ans;
}
int main(){
    return 0;
}