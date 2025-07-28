#include<bits/stdc++.h>
using namespace std;
vector <int> queens;
int n;
void printer(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==queens[i]){
                cout<< "Q";
            } else{
                cout<<".";
            }
        }
    }
}
bool check(int row, int col){
    
    for(int prow =0; prow<row; prow++ ){
       int pcol = queens[prow];
       if(pcol==col || abs(row-prow)==abs(pcol-col)){
        return false;
       }
    }
    return true;
}
void rec(int level){
// base case
if(level==n){
    printer();
    return ;
}
//recursive case
//loop on choices
for(int col = 0; col<n; col++){//choices
    //check if its valid
   if(check(level,col)){
    //make the choice
    queens.push_back(col);
    //recurse on next level
    rec(level+1);
    //revert back
    queens.pop_back();
   }

}

}
int main(){
int n;
cin>>n;
rec(n);

    return 0;

    
}