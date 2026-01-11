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
    vector<int>pk,revhash;
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
 int n = s.length();

        revhash.resize(n+1);
        revhash[n] = 0;
           for(int i=n-1;i>=0;i--){
            int num = (s[i]-'a'+1);
            revhash[i] = (revhash[i+1] * p + num) % mod; 
        }
    }
    int getfHash(int l , int r){
        if(l==0) return fhash[r];
    else  return ( (fhash[r] - fhash[l-1]*pk[r-l+1] % mod + mod) % mod );

    }
    int getrevHash(int l, int r){
        if(l==0) return revhash[r];
        else return ((revhash[l]-revhash[r+1]*pk[r-l+1]%mod +mod)%mod);
    }

};
struct double_hash{
    hasher a,b;
    void init(string s){
       a.init(s,37,1000000021);
b.init(s,39,1000000007);

}
pair<int,int> gethash(int l, int r){
return {a.getfHash(l,r), b.getfHash(l,r)};
}
pair<int,int> getrevhash(int l, int r){
return {a.getrevHash(l,r), b.getrevHash(l,r)};
}
bool ispalindrome(int l, int r){
    return gethash(l,r)== getrevhash(l,r);
}
};
int pal_count(string s){
    int n = s.length();
    hasher h;
    h.init(s, 39, 100000009);
    int finalans=0;
    for(int i =0;i<n;i++){
        int low =1;
        int high =min(i-0+1,n-i);
        int ans =0;
        while(low<=high){
            int mid = (low+high)/2;
            if(h.getfHash(i-mid+1,i)== h.getrevHash(i,i+mid-1)){
                ans = mid;
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        finalans+= ans;
    }

}
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