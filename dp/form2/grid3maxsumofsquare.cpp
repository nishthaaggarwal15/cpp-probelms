# include<bits/stdc++.h>
using namespace std;
# define int long long
const int INF=1e9;


int n,m;
int A[1010][1010];
vector<vector<int>> dp;


int rec(int r,int c){
    //pruning 
    if(r<0 || c<0) return 0;


    //base case
    if(r==0 && c==0) return A[r][c];


    //cache check
    if(dp[r][c]!=-1){
        return dp[r][c];
    }


    //transition
 int ans =0;
 if(A[r][c]!=0){
    ans = 1+min(rec(r-1,c),min(rec(r,c-1),rec(r-1,c-1)));
 }


    //save and return
    return dp[r][c]=ans;
}


signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  int t; cin>>t;
  while(t--){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    dp.assign(n+1,vector<int>(m+1,-1));
 
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,rec(i,j));
        }
    }


    cout<<ans*ans<<"\n";
  }


    
}


