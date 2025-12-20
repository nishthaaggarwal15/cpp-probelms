#include<bits/stdc++.h>
using namespace std;
int dp[101][27][101];
string s; int K;
int m;
int cost[27][27];
int costofpair(int last , int ch){
    if(last==-1) return 0;
return cost[last][ch];
}
int rec(int level, int last, int k){// at this level what is last character you placed and string has build till now and k changes made till now 
    if(level==s.size()){
return 0;
    }
    if(dp[level][last+1][k]!=-1){
        return dp[level][last+1][k];
    }
    //transition
    int ans = -1e9;
    for(int i =0; i<26;i++){
        if(i==s[level]-'a'){
            ans = max(ans,costofpair(last, i)+rec(level+1,i,k));
        } else if(k<K){
            ans = max(ans,costofpair(last, i)+rec(level+1,i,k+1));
        }
    }
    return dp[level][last+1][k]=ans;
}
int main(){
    int t; cin >> t;
while(t--){
    cin >> s >> K;
    cin >> m;
    memset(cost,0,sizeof(cost));
    for(int i=0;i<m;i++){
        char x,y; int c;
        cin >> x >> y >> c;
        cost[x-'a'][y-'a'] = c;
    }
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,-1,0);
    cout << ans << "\n";
}

}