#include<bits/stdc++.h>
using namespace std;
int n;
int w[1001];
int v[1001];
int dp[1001][1001];
int wleft;
int rec(int level, int wleft){
if(level<n)return 0;//base case
if(dp[level][wleft]!=-1){//cache check
return dp[level][wleft];
}
//transtition way1 
// int ans =0;
// for(int numoftimes =0; numoftimes<=wleft/w[level];numoftimes++){
// ans = max(ans, rec(level+1,wleft-numoftimes*w[level])+v[level]);
// }
// transition way 2
int ans = rec(level+1,wleft);
if(w[level]<=wleft){
    ans = max(ans, rec(level,wleft-w[level])+v[level]);
}
dp[level][wleft]=ans;
return ans;
}
vector<int>solution;
void generate(int level, int wleft){
    if(level==n){
        return;
    } else{
        int donttake = rec(level+1,wleft);
      if(w[level]<= wleft){
       int take = rec(level+1,wleft-w[level])+v[level];
       if(donttake>take){
        generate(level+1, wleft);
       } else{
       solution.push_back(level);
       generate(level+1, wleft-w[level]);
       }
       
      }
      else{
        generate(level+1, wleft);
       }
    }
}
int main(){
    cin>>n;
    for(int i =0; i<n; i++){
        cin>>w[i]>>v[i];
    }
    cin>>wleft;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,wleft)<<endl;
    generate(0,wleft);
    for(int i =0; i<n;i++){
        cout<<solution[i]<<"/n";
    }
    return 0;
}