#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int a[1001],b[1001];
int n,k,m;
//recursive code
int rec(int level){
if(level<1){
    return 1e9;
}
if(level==1){
    return 0;
}
if(dp[level]!=-1){
    return dp[level];
}
int ans = rec(level-1)+b[level-1];
for(int j =1;j<=k;j++){
    ans = max(ans, rec(level-j)+a[level-j]+a[level]);
}
return dp[level]=ans;
}
//iterative code
int iter(){
    dp[1]=0;
    for(int level=2;level<=n; level++){
dp[level]= dp[level-1]+b[level-1];
for(int j =1; j<=k; j++){
if(level-j>=1){
    dp[level]= min(dp[level], dp[level-j]+a[level-j]+a[level]);
}
}
    }
    cout<<dp[n]<<endl;
}
//optimized code - monotanic deque

struct monotonicdeque{
   deque<int> dq;
void insert(int x){
while(!dq.empty() && dq.back()>x){
    dq.pop_back();
}
dq.push_back(x);
}
void remove(int x){
if(dq.front()==x) dq.pop_front();
}
int getmin(){
return dq.front();
}
};
int main(){
    dp[1]=0;
    monotonicdeque mt;
    for(int level =2; level<=n; level++){
        dp[level]= dp[level-1]+b[level-1];
        mt.insert(dp[level-1]+ a[level-1]);
        if(level-k-1>=1) mt.remove(dp[level-k-1]+a[level-k-1]);
        dp[level]= min(dp[level], mt.getmin()+ a[level]);

    }
    cout<<dp[n]<<endl;
    return 0;
}