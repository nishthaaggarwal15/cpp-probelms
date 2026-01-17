#include<bits/stdc++.h>
using namespace std;
int start = 0;
    int n;
struct hasher{
    int sz,  mod, p;
    vector<long long> fhash,pk;
    void init(string s, int _p, int _mod){
        mod = _mod;
         p= _p;
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
   long long  getfhash(int l, int r){
if(l==0) return fhash[r];
else 
return(( fhash[r]- fhash[l-1]*pk[r-l+1])%mod + mod)%mod;
 }
    };

 hasher h1,h2;
    string longestDupSubstring(string s) {
      n = s.length();
        if (n == 0) return "";

        h1.init(s, 31, 1000000007);
        h2.init(s, 37, 1000000009);

        int len = bs(s);
        return s.substr(start, len);
    } 
    // check if the duplicate of mid(x) length exists
     int bs(string &s){
        int low =1;
        int high = n-1;
        int ans =0;
        while(low<=high){
            int mid= (low+high)/2;
            if(check(mid)){
                ans = mid;
            low = mid+1;

            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }

    // double hashing 
    // check if the current hash(key) exists before in seen set , if yes track duplicate's index through start else insert that hash into set
 bool check(int x){
        unordered_set< unsigned long long> seen;
        for(int i =0; i+x-1<n; i++){
           long long a = h1.getfhash(i,i+x-1);
             long long b = h2.getfhash(i,i+x-1);
               unsigned long long key = (a << 32) | b;
            if(seen.count(key)){
                start = i;
                return true;
            } else{
                seen.insert(key);

            }
        }
        return false;
    }


int main(){
    return 0;
}