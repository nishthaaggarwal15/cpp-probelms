#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1001][1001];
int k;
int arr[1001];
int rec(int level, int k){
//base case 
if(level==-1){
    if(k==0){
        return 0;
    }
    else return 1e9;
}
// cache check
if(dp[level][k]!=-1){
    return dp[level][k];
}
// transition
int ans =1e9;
int minseen = arr[level];
for(int j = level-1; j>=-1; j--){
   ans = min(ans, rec(j,k-1)+minseen);
   minseen = min(minseen, arr[j]);
}
// save and return 
dp[level][k]= ans;
return ans;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    int result = rec(n-1,k);
    cout<<result<<endl;
    
    return 0;
}