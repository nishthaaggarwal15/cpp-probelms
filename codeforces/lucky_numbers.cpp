// #include<bits/stdc++.h>
// using namespace std;

// const long long mod = 1e9+7;

// long long binpow(long long base, long long exp, long long mod)
// {
//     if (exp == 0) return 1;
//     if (exp % 2 == 1)
//         return (base * binpow(base, exp - 1, mod)) % mod;
//     else {
//         long long temp = binpow(base, exp / 2, mod);
//         return (temp * temp) % mod;
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     long long pow2n = binpow(2, n+1, mod);
//     long long res = (pow2n - 2 + mod) % mod;
//     cout << res;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Calculate 2^(n+1) - 2
    long long result = (1LL << (n + 1)) - 2;
    cout << result;
    return 0;
}
