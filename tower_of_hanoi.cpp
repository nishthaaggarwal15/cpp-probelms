#include<bits/stdc++.h>
using namespace std;
void move(int n, int source, int destination, int helper){
    if(n==1){
        cout<< "moved "<< source << " to "<< destination<< endl;
        return;
    } 
    move(n-1,source, helper, destination);
    cout<< "moved "<< source << " to "<< destination << endl;
    move(n-1,helper,destination, source);
}
int main(){
     int n;
     cin>> n;

    move(n,1,3,2);
    return 0;
}
