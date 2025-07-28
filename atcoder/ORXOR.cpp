#include<bits/stdc++.h>
using namespace std;
int n;
int arr[21];
int ans = INT_MAX;
void rec(int level, int inv_xor, int curr_or){
if(level==n){
    ans = min(ans, inv_xor^curr_or);
    return;
}
else{
    rec(level+1,  inv_xor, curr_or|arr[level]);
    rec( level+1,  inv_xor^curr_or, arr[level]);
}
}
int main (){
 cin>>n;
 for(int i =0; i<n; i++){
    cin>>arr[i];
 }
 rec(1,0,arr[0]);
 cout<<ans<<endl;
}
