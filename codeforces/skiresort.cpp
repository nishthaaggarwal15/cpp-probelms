#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        vector <int> arr (n);
        for(int i =0; i<n; i++){
            cin>> arr[i];
        }
        long long ans =0;
        int count=0;
        for(int i =0; i<n; i++){
          if(arr[i]<=q){
            count++;
          } else{
            if(count>=k){
                long long x = count-k+1;
             ans+= (x*(x+1))/2;
            }
            count =0;
          }
         
        }
        if(count>=k){
            long long x = count-k+1;
            ans+= (x*(x+1))/2;
           }
           cout<< ans<<endl;
    }
   
    return 0;
}