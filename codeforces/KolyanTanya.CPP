#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long binpow(long long base, long long exp, long long mod)
{
    if (exp == 0) return 1;
    if (exp % 2 == 1)
        return (base * binpow(base, exp - 1, mod)) % mod;
    else {
        long long temp = binpow(base, exp / 2, mod);
        return (temp * temp) % mod;
    }
}

int main() {
    int n;
    cin >> n;
    long long total = binpow(3, 3 *1LL*n, MOD);
    long long unsatisfactory = binpow(7, n, MOD);

    long long answer = (total - unsatisfactory ) % MOD;
    cout << (answer%MOD+MOD)%MOD << endl;
    return 0;
}