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
   string text, pattern;
   cin>>text>>pattern;
   int p= pattern.length();
   int h = quickHash(pattern,31,999999929);
   hasher texth;
   texth.init(text,31,999999929);
   for(int i =0; i+p-1<text.length(); i++){
    if(h==texth.getfHash(i, i+p-1)){
        cout<<"match at"<<i<<endl;
    }
   }
}
signed main(){
    return 0;
}