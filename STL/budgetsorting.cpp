#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
   vector<int>arr;
    int q;
    int n;
    cin>>n;
    cin>>q;
    arr.resize(n);
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
       sort(arr.begin(), arr.end());
    for(int i =1; i<n; i++){
        arr[i]+= arr[i-1];
    }
    while(q--){
        int m; 
        cin>>m;
auto it = upper_bound(arr.begin(), arr.end(), m);

  int ans = it - arr.begin();

    cout<<ans<<"\n";
    }
    return 0;
}