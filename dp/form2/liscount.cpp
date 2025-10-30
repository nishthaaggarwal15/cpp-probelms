#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10001];
int dp[10001];
int cnt [10001];
int mod = 1e7;
int rec(int level){
if(dp[level]!=0) return dp[level];
int ans =1;
cnt[level]=1;
for(int prevtaken =0; prevtaken<n; prevtaken++){
    int len = rec(prevtaken)+1;
    if(ans<len){
        ans = len;
        cnt[level]= cnt[prevtaken];
    } else if(ans ==len){
        cnt[level]= (cnt[level]+cnt[prevtaken]%mod);
    }
}
dp[level]= ans;
return ans;
}
int main(){
    memset(dp,0, sizeof(dp));
    memset(cnt,0,sizeof(dp));
    cin>>n;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int maxlen =0;
    for(int i =0; i<n;i++){
        
        maxlen = max(rec(i),maxlen);
    }
    int total =0; 
    for(int i =0; i<n; i++){
        if(dp[i]==maxlen){
            total= (total+cnt[i])%mod;
        }
    }
    cout<<total%mod<<endl;
    return 0;
}