#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int arr[1001];
int n, k;
int INF = 1e9;
//iterative
int solve(){
   cin>>n>>k;
   for(int i =0; i<n; i++){
    cin>>arr[i];
   }
   dp[0]=arr[0];
   for(int i=1; i<n; i++){
    int jmin = max(i-k,0);
    int jmax= i-1;
    dp[i]= INF;
    for(int j =jmin; j<=jmax; j++){
      dp[i]= min(dp[j]+arr[i],dp[i]);
    }
   }
   cout<<dp[n-1]<<endl;
}
//opitmized with monotonic deque
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
    cin>>n>>k;
   for(int i =0; i<n; i++){
    cin>>arr[i];
   }
   monotonicdeque mt;
   dp[0]=arr[0];
   for(int i=1; i<n; i++){
    mt.insert(dp[i-1]);
    if(i-k>=0) mt.remove(dp[i-k-1]);
    dp[i]= mt.getmin()+arr[i];
   }
   cout<<dp[n-1]<<endl;
    return 0;
}