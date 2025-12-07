#include<bits/stdc++.h>
using namespace std;
double dp[3003][3003];
vector<double>p;
int n;
double  rec(int level, int heads){
    if(level==n){
        int tails = n-heads;
        if(heads>tails)return 1.0;
        return 0;
    }
    if(dp[level][heads]!=-1){
        return dp[level][heads];
    }
  double ans =0;
    ans+= p[level]*rec(level+1,heads +1);
   ans += (1 - p[level]) * rec(level+1, heads);

  
    return dp[level][heads]=ans;
}
int main(){
    cin>>n;
       p.resize(n);
         for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i =0; i<n; i++){
        cin>> p[i];
    }
   double ans = rec(0,0);
     cout <<fixed << setprecision(10) << ans << "\n";
    return 0;
}