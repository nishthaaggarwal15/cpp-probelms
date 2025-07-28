#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long binpow(long long base, long long exp, long long mod)
{
    if(exp==0) return 1;
  else  if(exp%2==1){
        return (base* binpow(base, exp-1, mod))%mod;
    }
    else {
      long long temp = binpow(base, exp/2, mod);
       return (temp*temp)%mod;

}
}
int main(){
    int n ;
    cin>> n;
   
        long long res = binpow(2,n,mod);
        cout<< res;
        return 0;
    }
   