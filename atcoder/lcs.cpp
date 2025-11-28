#include<bits/stdc++.h>
using namespace std;
#define int long long


string s,t;
int n,m;
int dp[3010][3010];
int back[3010][3010];


void generate(int i,int j)
{
    if(i==n || j==m) return ;
    if(back[i][j]==3)
    {
        cout<<s[i];
        generate(i+1,j+1);
    }
    else if(back[i][j]==1)
    {
        
        generate(i+1,j);
    }
    else if(back[i][j]==2)
    {
        //cout<<t[j];
        generate(i,j+1);
    }
}


int rec(int i,int j)
{
    if(i==n || j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(rec(i+1,j) > rec(i,j+1)) 
    {
        ans = rec(i+1,j);
        back[i][j] = 1; 
    }
    else{
        ans = rec(i,j+1);
        back[i][j] = 2; 
    }
    if(s[i]==t[j])
    {
        if(ans < rec(i+1,j+1) + 1)
        {
            ans = rec(i+1,j+1) + 1;
            back[i][j] = 3; 
        }
    }
    return dp[i][j] = ans;
}


void solve()
{
    cin>>s>>t;
    n=s.size();
    m=t.size();
    memset(dp,-1,sizeof(dp));
    rec(0,0);
    generate(0,0);
    cout<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while (t--)
    {
        solve();
    }
}
