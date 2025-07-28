// number of ways to make sum =x;
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10001];
int dp[10001][10001];
int rec(int level,int sumleft){
    //pruning
    if(sumleft<0) return 0;
    //base case
    if(level==n){
        if(sumleft==0) return 1;
        else return 0;
    }
    //cache checking
if(dp[level][sumleft]!=-1){
    return dp[level][sumleft];
}
    //transition
    int ans =0;
    ans+= rec(level+1, sumleft-arr[level]);
    ans+= rec(level+1, sumleft);
    //save and return value
    dp[level][sumleft]= ans;
    return ans;
}
int main (){
    int x;
    cin>>n>>x;
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    rec(0,x);
}