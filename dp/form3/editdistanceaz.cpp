#include<bits/stdc++.h>
using namespace std;
string x,y;
int dp[1001][1001];
int rec (int i,int j){
    //base case 
    if(i<0) return j+1;
    if(j<0) return i+1;

    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //transition
    int ans = 1e9;
    if(x[i]==y[j]){
        ans= min(ans, rec(i-1,j-1));
    }
    else{
        ans = min(ans,1+rec(i,j-1));// insert
        ans = min(ans,1+ rec(i-1,j));//delete
        ans = min(ans, 1+rec(i-1,j-1));//replace
    }
    // save and return
    return dp[i][j]= ans;
}
int main(){
    cin>> x>>y;
   memset(dp, -1, sizeof(dp));
    cout << rec(x.size()-1, y.size()-1) << endl;
    return 0;
}