#include<bits/stdc++.h>
using namespace std;
int n, a,b;
using state = pair<int,int>;

 vector<state>arr;
 int dp[101][101];
 int rec(int level, int nb){ // at curr level how many number of a and b we have taken
   int na = min(level-nb,a);
       if(na > a || nb > b) return -1e9;
    if(level==n){
        if(na==a&& nb==b){
            return 0;
        }
        return -1e9;
    }
    if(dp[level][nb]!=-1){
        return dp[level][nb];
    }
    int ans = -1e9;
    if(na<a){
     
ans = max(ans, arr[level].first+rec(level+1,nb));
    } else{
        ans = max(ans, rec(level+1,nb));
    }
if(nb<b){
    ans = max(ans, arr[level].second+rec(level+1,nb+1));
}
return dp[level][nb]=ans;
 }
int main(){
    cout<<"hello world";
    return 0;
}