#include<bits/stdc++.h>
using namespace std;
int pat[50];
int bun[50];
void precal(){
    bun[0]=0;
    pat[0]=1;
for(int i =0; i<50; i++){
pat[i]= 1+ 2*pat[i-1];
bun[i]= 2+ 2*bun[i-1];
}
}
int findxthpat(int n, int x){
    // base case 
    if(n==0){
        return x;
    }
    // we are eating the top bun
    int ans =0;
    if(x>=1){
        x-=1;
    }
    //if we are eating  first n-1 level bunn
    if(x>=bun[n-1]+pat[n-1]){
    ans+= pat[n-1];
    x-= bun[n-1]+pat[n-1];
    } else{
        return ans + findxthpat(n-1, x);
    }
    //if we are eating middle pat
    if(x>=1){
        ans++;
        x-=1;
    }else{
        return ans;
    }
    // we are eating 2nd n-1 level bun
if(x>=bun[n-1]+pat[n-1]){
    ans+= pat[n-1];
    x-= bun[n-1]+pat[n-1];
    } else{
        return ans + findxthpat(n-1, x);
    }
    // if we are eating the last bun
   if(x>=1){
        ans++;
        x-=1;
    }else{
        return ans;
    }
}
int main(){

    return 0;
}