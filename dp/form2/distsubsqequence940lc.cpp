#include<bits/stdc++.h>
using namespace std;
 int distinctSubseqII(string s) {
        int n = s.size();
        int dp[n+1];
        int last [27];
        int prefix[n+1];
        int mod =1e9 +7;
        memset(last,-1,sizeof(last));
dp[0]=1;
prefix[0]=1;
for(int i =1; i<=n; i++){
dp[i]= prefix[i-1];
if(last[s[i-1]-'a']!=-1){
    int index = last[s[i-1]-'a'];
    dp[i] -=prefix[index];
    dp[i]= dp[i]%mod;
}
last[s[i-1]-'a']= i-1;
prefix[i]= prefix[i-1]+dp[i];
prefix[i]= prefix[i]%mod;
}
return (prefix[n]-1+mod)%mod;
    }
    int main(){
       cout<<distinctSubseqII("abcabc");
       
        return 0;
    }