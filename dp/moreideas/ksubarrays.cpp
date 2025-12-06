#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int done[1001][1001];
int p[1001];
int arr[1001];
int n;
int rec(int i, int k){
    if(i<0){
        if(k==0)return 0;
        else return -1e9;
    }
    if(done[i][k])return dp[i][k];
    int ans =rec(i-1,k);//not take this element
    for(int j =1; j<=i+1;j++){
        ans = max(ans,rec(i-j,k)+p[i]-p[i-j]);
    }
    done[i][k]=1;
    return dp[i][k]=ans;
}
int main(){
    int k;
    cin>>n>>k;
    for(int i =0; i<n; i++){
cin>>arr[i];
    }
    for(int i =0; i<n; i++){
        p[i]= arr[i-1]+p[i-1];
        
    }
    cout<<rec(n-1,k)<<endl;
    return 0;
}