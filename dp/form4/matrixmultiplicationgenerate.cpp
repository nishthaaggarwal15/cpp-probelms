#include<bits/stdc++.h>
using namespace std;
int x[1001],y[1001];
int dp[1001][1001];
int back[1001][1001];
int n;
int rec(int l,int r){
    // pruning
    if(l>r)return 0;
    //base case 
    if(l==r) return 0;
    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    // transition
    int ans = 1e9;
    for(int mid = l; mid<r; mid++){
        int bestmid = rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r];
        if(bestmid<ans){
        ans = bestmid;
        back[l][r]= mid;
        }
    }
    //save and return
    return dp[l][r]= ans;
}
int openb[101];
int closeb[101];
void generate(int l, int r){
if(l==r)return;
openb[l]++;
closeb[r]++;
int mid = back[l][r];
generate(l,mid);
generate(mid+1,r);
}
int main(){
    return 0;
}