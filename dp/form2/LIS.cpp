#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int n;
int arr[1001];
int rec(int level){
//pruning 
if(level<0) return 0;
//base case
// cache check
if(dp[level]!=-1){
    return dp[level];
}
// transition
int ans =1;
for(int prevtaken =1; prevtaken<=n; prevtaken++){
    if(arr[level]>arr[prevtaken]){
        ans = max(ans, rec(prevtaken)+1);// if condition we add length till prev one plus 1 (current one)
    }
}
//save and return
dp[level]=ans;
return ans;
}
int main(){
    return 0;
}