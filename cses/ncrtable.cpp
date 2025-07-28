#include<bits/stdc++.h>
using namespace std;
#define int long long
int ncr[1001][1001];
const int mod = 1e9+7;
void ncr_table(){

    for(int i =0; i<=1000;i++){
        ncr[i][0]=1;
        for(int j =1; j<=i; j++){
          
            ncr[i][j]= (ncr[i-1][j-1]+ ncr[i-1][j])%mod;
            
        }
    }

}
int main(){
    int t ;
    cin>>t;
    ncr_table();
    while(t--){
        int n ;
        cin>>n;
        for(int r=0; r<=n; r++){
            cout<<ncr[n][r]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}