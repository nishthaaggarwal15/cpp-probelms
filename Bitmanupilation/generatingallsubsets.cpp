#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
    for(int mask =0; mask<(1<<n); mask++){
        cout<<mask <<" : "; // 2-> 010
        for(int i =0; i<n; i++){
            if((mask>>i)&1){
                cout<<a[i]<<" , ";
            }
            
        }
        cout<<"\n";
    }
    return 0;
}