#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1001][16];
int rec(int level, int lastthree){
    if(level==n){
        return 1;
    }
    if(dp[level][lastthree]!=-1){
        return dp[level][lastthree];
    } 
    int ans =0;
     // lastThree == 2 --> 010 put 1 only to, not match it with t
    // lastThree == 2 --> 10 || 010 || ... etc. ---> so we need (level>=3) 
    //strict transition only it is 2 and have 3 digits
    if(level>=3&& lastthree==2){
        ans += rec(level+1,5);//0101
    } else{
        ans = rec(level+1, ((lastthree<<1)|0)&7)+
       rec(level+1, ((lastthree<<1)|1)&7) ;
    }
    return dp[level][lastthree]=ans;
}
int main(){
    return 0;
}