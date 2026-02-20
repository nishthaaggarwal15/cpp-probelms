#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

void binary(ll x){
    ull u=(ull)x;
    for(int i=63;i>=0;i--) cout<<((u>>i)&1);
    cout<<endl;
}

int msb(ll x){
    if(x==0) return -1;
    ull u=(ull)x;
    return 63-__builtin_clzll(u);
 // count leading zeroes
//     //x = 8 = 000...1000
// leading zeros = 60
// MSB position = 63 - 60 = 3
// }
}

int rsb(ll x){
    if(x==0) return -1;
    ull u=(ull)x;
    return __builtin_ctzll(u);//count trailing zeroes
    /*
    x = 12 = 1100
trailing zeros = 2
largest power divisor = 2^2 = 4
    */
}

int is_pow2(ll x){
    if(x<=1) return 0;
    ull u=(ull)x;
    return __builtin_popcountll(u)==1; //count no of setbits
    /*
    x = 8 → 1 bit → power of 2
x = 6 → 2 bits → not power of 2
    */
}

ll largest_pow2_div(ll x){
    if(x==0) return -1;
    ull u=(ull)x;
    return (1ULL<<__builtin_ctzll(u));
    /*
    12 = 1100 → 2 trailing zeros
    (1ULL << 2) = 4
    */
}

ll smallest_pow2_ge(ll x){
    if(x<=1) return 2;
    ull u=(ull)(x-1);
    return (1ULL<<(64-__builtin_clzll(u)));
}

void solve(){
    ll n;
    cin>>n;
    binary(n);
    cout<<msb(n)<<endl;
    cout<<rsb(n)<<endl;
    cout<<is_pow2(n)<<endl;
    cout<<largest_pow2_div(n)<<endl;
    cout<<smallest_pow2_ge(n)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}