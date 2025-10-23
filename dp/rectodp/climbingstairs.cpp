#include<bits/stdc++.h>
using namespace std;
int n;
int rec(int level){
    //base case
    if(level==n)return 1;
    //pruning
    if(level>n) return 0;
    // choices 
    int ans=0;
    for(int steps = 1; steps<=3; steps++){
        if(level+steps<=n){//check if valid step
           int ways = rec(level+steps);//move (if valid choice move to that and find no of ways from that step to n)
           ans+= ways;// add number of ways from all steps
        }
    }

    return ans;
}
int main(){
    return 0;
}