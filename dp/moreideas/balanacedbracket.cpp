#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1001][1001];
string s;
int n;
const int mod = 1e9+7;
int modadd(int a, int b){
    return (a+b)%mod;
}
int rec(int level, int open){
    //pruning
    if(open<0) return 0;
       if (open > n - level) return 0; 
    if(level==n){
        return open ==0;
    }
    if(dp[level][open]!=-1){
        return dp[level][open];
    }
    int ans=0;
    if(s[level]=='('){
      ans = rec(level+1,open+1);
    } else if(s[level]==')'){
        ans = rec(level+1,open-1);
    } else{ //?
        ans = modadd(ans, rec(level+1,open+1));
          ans = modadd(ans, rec(level+1,open-1));
    }
    return dp[level][open]=ans;
}
signed main(){
     ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        cin>>s;
        n= s.size();
         for(int start=0;start<n;start++)
        {
            for(int end=0;end<=n; end++)
            {
                dp[start][end]=-1;
            }
        }
      cout<<  rec(0,0)<<"\n";
    }
    return 0;
}