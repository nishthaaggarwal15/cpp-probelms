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
dp[i]= prefix[i-1];//if it is not a repeatd char num of subsequenecw will be same as prev
if(last[s[i-1]-'a']!=-1){ // if it has occured before
    int index = last[s[i-1]-'a'];// take the index
    dp[i] -=prefix[index];// remove its prefix the sum before this because it already generated that and we dont want to again 
    dp[i]= dp[i]%mod;
}
last[s[i-1]-'a']= i-1;
//now mark index of curr element to keep track when it was visited
prefix[i]= prefix[i-1]+dp[i];// prefix of curr el will be prefix of prev + subsequence of curr char
prefix[i]= prefix[i]%mod;
}
return (prefix[n]-1+mod)%mod;
    }
    int main(){
       cout<<distinctSubseqII("abcabc");
       
        return 0;
    }