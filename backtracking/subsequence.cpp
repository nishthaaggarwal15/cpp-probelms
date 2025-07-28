#include<bits/stdc++.h>
using namespace std;
int n ;
int arr[10];
vector<int> solns;
void rec(int level){
    if(level==n){
        for(int i =0; i<solns.size();i++){
            cout<<solns[i]<<endl;
        }
        return;
    }
    {
        rec(level+1);
    }{
        solns.push_back(arr[level]);
        rec(level+1);
        solns.pop_back();
    }
}
int main(){
  n =4;
  arr[0]= 1; arr[1]=2;
  arr[2]= 3;
  arr[3]=4;
  rec(0);
}