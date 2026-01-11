#include<bits/stdc++.h>
using namespace std;
#define int long long
int quickHash(string s, int p, int mod){
int ans = (s[0]-'a'+1);
for(int i =1; i<s.length(); i++){
    ans = ((ans*p + s[i]-'a'+1))%mod ;
}
return ans;
}
struct hasher{
   int sz, p, 
   mod;
   vector<int> fhash;
   vector<int> pk;
   void init(string s, int _p, int _mod){
    mod = _mod; p = _p;
    sz = s.length();
    fhash.resize(sz);
    pk.resize(sz);
    fhash[0]= s[0]-'a'+1;
        pk[0] = 1;   
    for(int i =1; i<s.length(); i++){
    fhash[i]= (fhash[i-1]*p + (s[i]-'a'+1))%mod;
    pk[i]= (pk[i-1]*p)%mod;
    }
   }
  int getfhash(int l, int r){
if(l==0) return fhash[r];
else return ((fhash[r]- fhash[l-1]*pk[r-l+1])%mod+mod)%mod;
   }
};

bool check(string s1, string s2, int x){
    if(x==0) return true;
hasher h1,h2;
h1.init(s1,31,1000000007);
h2.init(s2,31,1000000007);
unordered_set<int>st;
for(int i =0; i+x-1<s1.size(); i++){
st.insert(h1.getfhash(i, i+x-1));
}
for(int i =0; i+x-1<s2.size(); i++){
   if( st.count(h2.getfhash(i,i+x-1)))
    return true;
}
return false;
}
string getSubstring(string s1, string s2, int x){

hasher h1,h2;
h1.init(s1,31,1000000007);
h2.init(s2,31,1000000007);
unordered_map<int,int>mp;
for(int i =0; i+x-1<s1.size(); i++){
mp[(h1.getfhash(i, i+x-1))]=i;
}
for(int i =0; i+x-1<s2.size(); i++){
   int h = h2.getfhash(i, i+x-1);
   if(mp.count(h)){
    return s1.substr(mp[h],i);
   }
}
return " ";
}
int bs (string s1, string s2){
    int lo =0; int high = min(s1.length(), s2.length());
    int ans =0;
    while(lo<=high){
        int mid = lo+(high-lo)/2;
 if(check(s1,s2,mid)==1){
    ans = mid;
lo = mid+1;
 } else{
    high = mid-1;
 }
    }
       return ans;
}
int main(){
    return 0;
}