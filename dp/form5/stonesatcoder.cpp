#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[100100];
int a[1001];
int rec(int x){
  if(x<=0) return 0;
  if(dp[x]!=-1){
    return dp[x];
  }
  int ans =0;
  for(int i=0; i<n; i++ ){
    if(a[i]>x)continue;
    if(rec(x-a[i])==0){
      ans =1;
      break;
    }
  }
  return dp[x]=ans;
}
int main(){
  cin>>n>>k;
  for(int i =0; i<n; i++){
    cin>>a[i];
  }
  memset(dp,-1,sizeof(dp));
  int ans = rec(k);
  if(ans ==1){
    cout<<"First"<<"\n";
  } else{
    cout<<"Second"<<"\n";
  }
  return 0;
}