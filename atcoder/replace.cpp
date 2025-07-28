#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    int n ;
    cin>> n;
    map<int,int> m;
    int sum =0;
    for(int i =0; i<n; i++){
       int x;
       cin>> x;
       m[x]++;
       sum+= x;
    }
    int q;
    cin>> q;
    while(q--){
        int b,c;
        cin>>b>>c;
        int chng = m[b];
        m[b]-= chng;
        m[c]+= chng;
        sum-= chng*b;
        sum+= chng*c;
        cout<< sum<< " ";
        cout<< endl;
    }
    return 0;
}