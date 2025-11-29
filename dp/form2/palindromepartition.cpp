#include<bits/stdc++.h>
using namespace std;
string s;
int dp1[1001][1001];
int dp2[1001];
int rec1(int l, int r){// check palindrome
if(l>=r){
    return 1;
}
if(dp1[l][r]!=-1){
    return dp1[l][r];
}
int ans =0;
if(s[l-1]==s[r-1] && rec1(l+1, r-1)) ans =1;
return dp1[l][r]=ans;

}
int rec2(int i){// min cuts for 1 to i
// base case
if(i==0) return -1;
//cachhe check
if(dp2[i]!=-1){
    return dp2[i];
}
// tranaition
int ans =1e9;
for(int j = i-1 ; j>i; i--){
    if(rec1(j+1,i)){
 ans = min(ans,rec2(j)+1);
    }

}
// save and return
return dp2[i]= ans;
}

int main(){
    return 0;
}