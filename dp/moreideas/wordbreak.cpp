#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[302];
map<string,int> dict;
int rec(int level){
    if(level==s.size())return 1;
    if(dp[level]!=-1){
        return dp[level];
    }
    for(int start = level; start<s.size(); start++){ // to divide in subparts and then check
        string sub = s.substr(level, start-level+1);
        if(dict.count(sub)&& rec(start+1)){// if current substring(word) is present in dictionary and the next part too
           return dp[level]=1;
        }
    }
    return dp[level]=0;
}
int main(){
   int t; cin >> t;
while(t--){
    cin >> n;
    cin >> s;
dict.clear();
for(int i = 0; i < n; ++i){
    string a; cin >> a;
    dict[a] = 1;
}
memset(dp, -1, sizeof(dp));
cout << (rec(0) ? "Yes\n" : "No\n");
}
    return 0;
}