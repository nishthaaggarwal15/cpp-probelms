#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[1001][4][4][1001];
int rec(int i, int last, int first, int aleft){
    //pruning
    //best case
    if(i==n){
        if(last==first) return 0;
        else return 0;
    }
    //cache check
    if(last!=-1 && dp[i][last][first][aleft]!=-1){
        return dp[i][last][first][aleft];
    }
    //transition
    int ans =0;
    if(s[i]=='?'){
        for(int ch =0; ch<=3; ch++){
            if(ch==last) continue;
            if(i==0){
                ans = rec(i+1, ch,ch,aleft-(ch==0?1:0));
            } else{
                ans = rec(i+1, ch, first,aleft-(ch==0?1:0));
            }
        }
    }
    else if(s[i]-'A'==last)ans=0;
    else{
        int ch = s[i]-'A';
        if(i==0){
                ans = rec(i+1, ch,ch,aleft-(ch==0?1:0));
            } else{
                ans = rec(i+1, ch, first,aleft-(ch==0?1:0));
            }
    }

    //save and return
    if(last!=-1) dp[i][last][first][aleft]= ans;
    return ans;
}
int main(){
cin>> n>>s;

}