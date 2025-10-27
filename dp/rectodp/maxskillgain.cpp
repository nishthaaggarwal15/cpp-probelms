#include<bits/stdc++.h>
using namespace std;
int t[100100];
int s[100100];
int taken[100100];
int x,k;
int n;

bool check(int level){
    int timetakentillnow =0;
    int itemtaken =0;
    for(int i =0; i<level; i++){
        if(taken[i]){
timetakentillnow+= t[i];
itemtaken+= 1;
        }
    }
    timetakentillnow+= t[level];
    itemtaken++;
    if(timetakentillnow<=x && itemtaken<=k){
        return true;
    }
    return false;
}
int rec(int level){// max skill i can make from 0 to level[n-1]
    //level is current item we are at
    //base case
    if(level==n) return 0;
    //pruning
//choice 
//choice 1 dont take
int ans =rec(level+1);
//choice 2 take it
if(check(level)){//check
    //place the change
    taken[level]=1;

    //move
   ans = max(ans, s[level]+rec(level+1)) ;
    //revert
    taken[level]=0;
}
return ans;
}
void solve(){

cin>>n;
for(int i =0; i<n;i++){
    cin>>t[i]>>s[i];
}
cin>>x>>k;
cout<<rec(0)<<endl;
}
int main(){
    return 0;
}