/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// int main()
// {
    // string s;
    // cin>>s;
    // int q ;
    // cin>> q;
    // deque<char> dq(s.begin(), s.end());
    // int is_flipped =0;
    
    // while(q-->0){
    //     int op;
    //     cin>>op;
    //   if(op==1){
    //       if(is_flipped==0){
    //           is_flipped=1;
    //       } else{
    //           is_flipped=0;
    //       }
    //   } else{
    //       int side;
    //       char ch ;
    //       cin>> side>> ch;
    //       if(is_flipped){
    //           side = (1+2)-side;
    //       }
    //       if(side==1){
    //           dq.push_front(ch);
    //       } else{
    //           dq.push_back(ch);
    //       }
    //   }
     
    // }
    
    //  if(is_flipped){
    //       reverse(dq.begin(), dq.end());
    //   }
    //   for (int i = 0; i < dq.size(); i++) {
    //     cout << dq[i];
    // }
    //   cout<<endl;
    // return 0;
    
    
    
    const long long MOD = 1e9 + 7;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter length: ";
    cin >> n;
    vector<long long> arr(n);

    cout << "Enter values of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long pop = 1;
    long long product = 1;

    for (int i = 0; i < n; i++) {
        long long power = modPow(arr[i], i + 1, MOD);
        pop = (pop * power) % MOD;
        product = (product * pop) % MOD;
    }

    cout << "Product of products of all subarrays: " << product << endl;
    return 0;
}