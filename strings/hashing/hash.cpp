#include<bits/stdc++.h>
using namespace std;
#define int long long
int quickHash(string s, int p, int mod){
int ans = (s[0]-'a'+1);
for(int i =1; i<s.length();i++){
    ans = (ans*p +( s[i]-'a'+1))%mod;
}
return ans;
}
struct hasher{
    int sz,  mod, p;
    vector<int> fhash;
    vector<int>pk;
    void init(string s, int _p, int _mod){
        mod = _mod; p= _p;
        sz = s.length();
        fhash.resize(sz);
        pk.resize(sz);
        fhash[0]= (s[0]-'a'+1);
        pk[0]=1;
        for(int i =1; i<s.length();i++){
    fhash[i] = (fhash[i-1]*p +( s[i]-'a'+1))%mod;
    pk[i]= (pk[i-1]*p)%mod;
}
    }
    int getfHash(int l , int r){
        if(l==0) return fhash[r];
        else return ((fhash[r]-fhash[l-1]*pk[r-l+1]));
    }
};
void solve(){
    string s;
    cin>>s;
    hasher shash;
    shash.init(s,31,1e9+7);
    int n = s.length();
    for(int i =0; i<n; i++){
        for(int j =i; j<n; j++){
            cout<<shash.getfHash(i,j)<<endl;
        }
    }
}
signed main(){
    return 0;
}