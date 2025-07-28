#include<bits/stdc++.h>
using namespace std;
int n, a,b,c;
int arr[10];
int ans = INT_MAX;
void rec(int level, int suma, int sumb, int sumc, int mpcost){
    if(level==n){
        if(suma==0||sumb==0||sumc==0) return;
        ans=min(ans,mpcost+abs(suma-a)+abs(sumb-b)+abs(sumc-c));
        return;
    }
    rec(level+1,suma,sumb,sumc,mpcost);
    rec(level+1,suma+arr[level],sumb,sumc,mpcost+((suma>a)?10:0));
    rec(level+1,suma,sumb+arr[level],sumc,mpcost+((sumb>a)?10:0));
    rec(level+1,suma,sumb,sumc+arr[level],mpcost+((sumc>a)?10:0));
}


int main(){
    cin>> n>>a>>b>>c;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    rec(0,0,0,0,0);
    cout<<ans<<endl;
    return 0;
}