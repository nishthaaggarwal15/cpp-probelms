#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;


 long long binpow(long long base, long long exp,long long mod){
    if(exp==0) return 1;
    if(exp%2==1){
   return (base * binpow(base, exp-1, mod))%mod;
    } else{
       long long temp = binpow(base,exp/2,mod);
       return (temp* temp)%mod;
    }
 }
 long long inv(long long x){
    return binpow(x, mod-2, mod);
 }
 long long fact (int n){
    int ans =1;
    for(int i =2; i<=n; i++){
       ans = (ans*i)%mod;
    }
    return ans;
 }
//  long long ncr(int n, int r){
//     int num = fact(n);
//     int den = (fact(n-r)* fact(r))%mod;
//     return (num * inv(den))%mod;
//  }

long long single_ncr(int n, int r) { // O(r)
    // 4!
    if (r > n) return 0;
    long long num = 1, den = 1;
    for (int i = 1; i <= r; i++) {
        num = (num * (n - i + 1)) % mod;
        den = (den * i) % mod;
    }
    return (num * inv(den)) % mod;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout <<single_ncr(a, b) << '\n';
    }
    return 0;
}