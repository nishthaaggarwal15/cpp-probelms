#include<bits/stdc++.h>
using namespace std;
int dp[101][1001];//k,level for iterative only
int a[1001],b[1001];
int n,k,m;

//recursive code
int rec(int level, int num){
if(level<1){
    return 1e9;
}
if(level==1 && num==0){
    return 0;
} else if(level==1){
    return 1e9;
}
if(dp[level][num]!=-1){
    return dp[level][num];
}
int ans = rec(level-1,num)+b[level-1];
if(num>0)for(int j =1;j<=k;j++){
    ans = max(ans, rec(level-j,num-1)+a[level-j]+a[level]);
}
return dp[level][num]=ans;
}



//iterative code
int iter(){
for(int j =0; j<=m; j++){// num of flights
   for(int level=2;level<=n; level++){
if(level==1&& j==0){
dp[j][level]=0;
} else if(level==1){
    dp[j][level]=1e9;
}

dp[j][level]= dp[j][level-1]+b[level-1];
if(j>0) for(int x =1; x<=k; x++){
if(level-x>=1){
    dp[j][level]= min(dp[j][level], dp[j-1][level-x]+a[level-x]+a[level]);
}
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
    for(int j =0; j<=m; j++){// num of flights
        monotonicdeque mt;

   for(int level=2;level<=n; level++){
if(level==1&& j==0){
dp[j][level]=0;
} else if(level==1){
    dp[j][level]=1e9;
}

 else{
dp[j][level]= dp[j][level-1]+b[level-1]; //bus
if(j>0) {
mt.insert(dp[j-1][level-1]+a[level-1]);// c-array
if(level-k-1>=1){
    mt.remove(dp[j-1][level-k-1]+a[level-k-1]);
    dp[j][level]= min(dp[j][level], mt.getmin()+a[level]);
}
}
    }
}
 }

    cout<<dp[n]<<endl;
    return 0;
}