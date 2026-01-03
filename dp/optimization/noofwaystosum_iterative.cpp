#include<bits/stdc++.h>
using namespace std;
int sum;
int arr[1001];
int dp[1001][1001];
int n;
int rec(int level, int sumleft){
    if(sumleft<0)return 0;
if(level==n){
    if(sumleft==0){
        return 1;
    } 
    return 0;
}
if(dp[level][sumleft]!=-1){
    return dp[level][sumleft];
}
int ans =0;
for(int i= 0; i<=arr[level]; i++){
    ans+= rec(level+1,sumleft-i);
}
return dp[level][sumleft]=ans;
}
int iterative(){
    for(int level = n; level>=0; level--){
        for(int sumleft=0; sumleft<=sum; sumleft++){
if(level==n){
    if(sumleft==0){
        dp[level][sumleft]= 1;
        
    } 
    dp[level][sumleft] =0;
    continue;
}
int ans =0;
for(int i= 0; i<=arr[level]; i++){
   if(sumleft>=i) ans+= dp[level+1][sumleft-i];
}
 dp[level][sumleft]=ans;
        }
    }
    cout<<dp[0][sum]<<endl;
}
int main(){
    cin>>n>>sum;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    iterative();
    return 0;
}