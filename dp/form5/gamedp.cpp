#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int x;
int rec(int x){
// base case 
if(x==0) return 0;// if you cant play you'll lose
// cache check
if(dp[x]!=-1){
    return dp[x];
}
// transition
int ans =0;
for(int m = 0; (1<<m)<=x; m++){
if(rec(x-(1<<m))==0){// if next state is losing state you'll win as your opponent will play and he'll lose
    ans =1;
    break;
}
}
// save and return
return dp[x]= ans;
}
int main(){
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
 for(int i =0; i<10; i++){
    cout<< rec(i)<<endl;
 }
 /* there is a pattern so we can also do n%3 to get the answer 
 */
    return 0;
}