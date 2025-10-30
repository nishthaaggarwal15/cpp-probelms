#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000100];
string s;
int rec(int level){
//pruning 
if(level==n) return 1;
//base case
// cache check
if(dp[level]!=-1){
    return dp[level];
}
// transition
int ans =0;
if(s[level]!='0'){
ans+=rec(level+1);
}
if(level+1<n){
    int num =( s[level]-'0')*10+ s[level+1]-'0';
    if(num >=10 && num<=26){
        ans+= rec(level+2);
    }
}
//save and return
dp[level]=ans;
return ans;
}
void solve() {
  while (true) {
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
 
    if (s == "0") {
      break;
    } else {
      cout << rec(0) << endl;
      s.clear();
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  solve();
  return 0;
}