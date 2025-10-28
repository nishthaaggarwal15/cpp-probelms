#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int dp[101][101];
int points [1001][3];
int rec (int level,int prevchoice){
if(level==n){
    return 0;
}
if(dp[level][prevchoice]!=-1){
    return dp[level][prevchoice];
}
 int ans =0;
for(int currchoice =1; currchoice<=3; currchoice++){
    if(currchoice!=prevchoice)
 ans = max(ans, points[level][currchoice]+rec(level+1, currchoice));
}
dp[level][prevchoice]= ans;
return ans;
}
int main(){
    return 0;
}