#include<bits/stdc++.h>
using namespace std;
string x,y;
int n,m;
int dp [1001][1001];
int back[1001][1001];
int rec(int l1, int l2){
//base case
if(l1==n&& l2==m){
    return 0;
}
// pruning
//cache
if(dp[l1][l2]!=-1){
    return dp[l1][l2];
}
//transition
int ans = 1e9;
if(l1<n){ // -x[l1]
    if(rec(l1+1,l2)+1<ans){
        ans = rec(l1+1,l2)+1;
        back[l1][l2]= 0;
    }
    
}
if(l2<m){ //+y[l2]
    if(rec(l1,l2+1)+1<ans){
        ans = rec(l1,l2+1)+1;
        back[l1][l2]=1;
    }
}
if(l1<n && l2<m && x[l1]==y[l2]){
    if(rec(l1+1,l2+1)+1<ans){
        ans = rec(l1+1,l2+1)+1;
        back[l1][l2]=2;
    }
}
return dp[l1][l2]=ans;
//save and return
}
void generate(int l1,int l2){
    if(l1==n && l2==m){
        return;
    }
    int ch = back[l1][l2];
    if(ch==0){
        cout<< "-"<<x[l1]<<" ";
        generate(l1+1,l2);
    } else if(ch==1){
        cout<< "+"<<y[l2]<<" ";
        generate(l1,l2+1);
    } else{
        cout << x[l1]<<" ";
        generate(l1+1,l2+1);
    }
}
int main(){
    cin >>x>>y;
    n = x.length();
    m = y.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    generate(0,0);
    return 0;
}