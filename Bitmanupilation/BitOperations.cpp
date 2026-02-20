#include<bits/stdc++.h>
using namespace std;
struct bitbag{
    long long state=0;
    int k=64;
int check(int i){
if(state& (1LL<<i)){
    return 1;
} else {
    return 0;
}
}
void set(int i ){
   state= state|(1LL<<i);
}
void clear(int i){
    state = state&~(1LL<<i);
}
void flip (int i){
    state = state^(1LL<<i);
}
int print (){
   long long mask = (1LL<<k)-1;
    if((state&mask)==mask){
        return 1;
    } else return 0;
}
int any(){
   long long mask = (1LL<<k)-1;
   if((state&mask)>0) return 1;
   else return 0;
}
int none(){
   long long mask = (1LL<<k)-1;
    if((state&mask)==0) return 1;
    else return 0;
}
int count (){
    int cnt=0;
    long long temp = state;
    while(temp!=0){
        temp = temp& (temp-1) ;
        cnt++;
    }
    return cnt;
}
long long val(){
    return state;
}
int checkpower(){
    if(state>0 && (state&state-1)==0){
        return 1;
    } else return 0;
}
int leftmostbit(){
    for(int i= state-1; i>=0; i--){
        if((state>>i)&1){
            return i;
        }
        return -1;
    }
}
int rightmostbit(){
     for(int i= 0; i<state; i++){
        if((state>>i)&1){
            return i;
        }
        return -1;
    }
}
int biggestpoweroftwo(){
    for(int i =0; i<state; i++){
        if((state>>i)&1){
            return 1LL<<i;
        }
    }
}
int smallestpoweroftwo(){
    int p =1;
    while(p<state){
        p= p*2;
        return p;
    }
}
};
int main(){
    return 0;
}