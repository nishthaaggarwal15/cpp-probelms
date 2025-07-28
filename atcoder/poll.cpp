#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string , int>m;
    int maxf=0;
    for(int i =0; i<n; i++){
        string s; cin>> s;
        m[s]++;

        maxf= max(m[s], maxf);
    }
    for(auto it: m){
        if(it.second==maxf){
            cout<< it.first<< " ";
        }
        cout<< endl;
    }
    return 0;
}