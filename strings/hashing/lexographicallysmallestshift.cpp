#include<bits/stdc++.h>
using namespace std;
#define int long long 
int quickHash(string s, int p, int mod){
int ans = s[0]-'a'+1;
for(int i =0; i<s.length(); i++){
ans = (ans*p +( s[i]-'a'+1)) %mod;
}
}
struct hasher{
    int sz, p,mod;
vector<int> fhash;
vector<int> pk;
 void init(string s, int _p, int _mod){
   p=_p;
   mod = _mod;
sz= s.length();
fhash.resize(sz);
pk.resize(sz);
fhash[0]= s[0]-'a'+1;
pk[0]=1;
for(int i =1; i<s.length(); i++){
fhash[i]= (fhash[i-1]*p + (s[i]-'a'+1))%mod;
pk[i]= (pk[i-1]*p)%mod;
}
 }
 int getfhash(int l, int r){
if(l==0) return fhash[r];
else return( (fhash[r]-fhash[l-1]*pk[r-l+1])%mod+mod)%mod;
 }


};
hasher shash;
string s;
int n;
bool cmp (int i, int j){
    int low =1; int high = n;
int ans =0;
while(low<=high){
    int mid = (low+high)/2;
    if(shash.getfhash(i,i+mid-1)==shash.getfhash(j,j+mid-1)){
        ans = mid;
        low = mid+1;
    }else{
        high =mid-1;
    }
}
if(ans==n){
    return false;
}else{
    return s[i+ans]<s[j+ans];
}

}
void solve(){
    cin>>s;
    int n= s.length();
    s= s+s;
    shash.init(s,37,999999937);
    vector<int> final;
    for(int i =0; i<n; i++){
        final.push_back(i);
    }
    sort(final.begin(),final.end(),cmp);
    for(auto v:final){
        cout<<v<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}