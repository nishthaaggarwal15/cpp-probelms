// given n , find all soln abcde/fghij=n , no two chars have same digit one to one mapping
#include<bits/stdc++.h>
using namespace std;
 int main(){
    int n ;
    cin>>n;
    string s = "0123456789";
    do{
     int num = stoi(s.substr(0,5));
     int den = stoi(s.substr(5,5));
     if(num%den==0 && num/den==n){
        cout<< num <<" "<< den;
     }
    } while(next_permutation(s.begin(), s.end()));
    return 0;
 }