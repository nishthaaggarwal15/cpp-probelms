#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[1001][4][4][1001];
int rec(int i, int last, int first, int aleft){
    //pruning
    //base case
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
string ans;
void generate(int i, int last, int first, int aleft){
    //base case
    if(i==n){
        return;
    }
    //transition

    if(s[i]=='?'){
        for(int ch =0; ch<=3; ch++){
            if(ch==last) continue;
            if(i==0){ //if we get the first soln here 
                if(rec(i+1, ch,ch,aleft-(ch==0?1:0))>0){
                ans+= char('A'+ch);
                generate(i+1,ch,ch,aleft-(ch==0?1:0));
                return;
                }
            } else{
                if(rec(i+1,ch,first,aleft-(ch==0?1:0))>0){ //first soln after a 
                    ans+= char('A'+ch);
                     ans = rec(i+1, ch, first,aleft-(ch==0?1:0));
                     return;
                }
               
            }
        }
    }
    else if(s[i]-'A'==last){
        //non reachabe to get soln so we do nothing
    }
    else{
        int ch = s[i]-'A';
    
        if(i==0){
                ans +=s[i] ;
                generate(i+1, ch,ch,aleft-(ch==0?1:0));
                return;
            } else{
                ans +=s[i];
                 generate(i+1, ch, first,aleft-(ch==0?1:0));
                 return;
            }
    }

 
}
int main(){
cin>> n>>s;

}