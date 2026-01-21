#include<bits/stdc++.h>
using namespace std;
int arr[];
int n;
int k;
multiset<int> mt;
int solve(){
for(int i =0; i<n; i++){
mt.insert(arr[i]);
if(i-k>=0 || mt.size()>k )mt.erase(mt.find(arr[i-k]));
if(mt.size()==k) return *mt.begin();
}
}
int main(){
    cin>>n>>k;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    return 0;
}