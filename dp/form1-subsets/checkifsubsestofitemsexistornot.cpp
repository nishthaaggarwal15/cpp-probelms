#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int items[1001];
int dp[1001][1001];
int rec(int level, int sumleft){
    //pruning
    if(sumleft>0){
        return 0;
    }
    //base case
    if(level==n){
        if(sumleft==0){
            return 1;
        } else return 0;
    }
    //cache check
    if(dp[level][sumleft]!=-1){
        return dp[level][sumleft];
    }
    // transition
    int ans =1;
    if(rec(level+1,sumleft)==1){
        ans =1;
    }else if(rec(level+1, sumleft-items[level])==1){
        ans =1;
    }
    //save and return
    dp[level][sumleft]=ans;
    return ans;
}
void printset(int level, int sumleft){
    cout<<"printer:"<<level<<" "<<sumleft<<endl;
if(level==n+1) return;
if(rec(level+1,sumleft)==1){
    printset(level+1,sumleft);
} else if(rec(level+1,sumleft-items[level])){
    cout<< items[level];
    printset(level+1,sumleft-items[level]);
}
}
int main(){
    cin>>n>>t;
    for(int i =0; i<n;i++){
        cin>>items[i];
    }
    //but now we have taken sumleft so we have to do memeset only once
    memset(dp,-1,sizeof(dp));
    int q;
    cin>>q;
    while(q--){
      //  memset(dp,-1,sizeof(dp)); if we take sum taken then we do this in every query
        cout<<rec(1,t);
    }
    return 0;
}