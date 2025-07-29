// s= "??A?B?C"- no of ways to replace ? with (A/B/C/D) such that no two neighbours are same
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[10001][4];
int rec(int i, int last){
    //pruning
    //base case 
    if(i==n) return 1;
    //cache check
    if(last!=-1 && dp[i][last]!=-1){
        return dp[i][last];
    }
    //transition
    int ans =0;
    if(s[i]=='?'){
for(int ch = 0; ch<4; ch++){
    if(ch==last) continue;
    ans+= rec(i+1,ch);
 } 
    
}
else if(s[i]-'A'==last) ans= 0; 
else {
ans = rec(i+1,s[i]-'A');
}
//save and return
if(last!=-1) dp[i][last]= ans;
return ans;
}

int main(){
cin>>n>>s;
}