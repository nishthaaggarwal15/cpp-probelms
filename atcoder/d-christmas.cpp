//https://atcoder.jp/contests/abc115/submissions/65221966

#include<bits/stdc++.h>
using namespace std;

#define int long long

int buns[51];
int pat[51];
void precal(){
 buns[0]=0;
 pat[0]= 1;
 for(int i =1; i<=50; i++){
    buns[i]= 2+ 2*buns[i-1];
    pat[i]= 1+ 2*pat[i-1];
 }
}
int findtoxpat(int n,int x){
    int ans =0;
if(x>=1){
   x-=1;
} else {
    return ans;
}
// we are eating n-1 level
if(x>=buns[n-1]+ pat[n-1]){
    ans+= pat[n-1];
    x-= buns[n-1]+ pat[n-1];
} else{
    return ans+ findtoxpat(n-1, x);
}
// middle pat 
 if(x>=1){
ans++;
x-=1;
 } else{
    return ans;
 }
// we are eatinf 2nd n-1 level bun
if(x>=buns[n-1]+ pat[n-1]){
    ans+= pat[n-1];
    x-= buns[n-1]+ pat[n-1];
} else{
    return ans+ findtoxpat(n-1, x);
}
// last bun
if(x>=1){
    x-=1;
} else {
    return ans;
}
return ans;
}
signed main(){
    precal();
    int n,x; cin>>n>>x;
   cout<< findtoxpat(n,x)<< endl;

}