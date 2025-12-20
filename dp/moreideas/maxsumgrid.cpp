#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
vector<vector<int>> arr;
int kadane(vector<int> &a){
     int best = a[0];
    int curr = a[0];

    for(int i = 1; i < a.size(); i++){
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }
    return best;
}
int solve(){
    int ans = -1e18;
if(n <= m){
    for(int r1 = 0; r1 < n; r1++){
        vector<int> colsum(m, 0);
        for(int r2 = r1; r2 < n; r2++){
            for(int c = 0; c < m; c++){
                colsum[c] += arr[r2][c];
            }
            ans = max(ans, kadane(colsum));
        }
    }
} else {
     for(int c1 = 0; c1 < m; c1++){
        vector<int> rowsum(n, 0);
        for(int c2 = c1; c2 < m; c2++){
            for(int r = 0; r < n; r++){
                rowsum[r] += arr[r][c2];
            }
            ans = max(ans, kadane(rowsum));
        }
    }
}
return ans;
}
signed main(){
    int t; 
    cin>>t;
    while(t--){
cin>>n>>m;
    arr.assign(n, vector<int>(m));
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arr[i][j];
        }
    }
   int result =  solve();
   cout<<result<<"\n";
   
    }
    return 0; 
}