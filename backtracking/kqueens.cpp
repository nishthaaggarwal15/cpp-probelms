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
       if(pcol==-1) continue;
       if(pcol==col || abs(row-prow)==abs(pcol-col)){
        return false;
       }
    }
    return true;
}
void rec(int level, int qleft){
// base case
if(level==n){
    if(qleft==0) printer();
    return ;
}
//recursive case
//loop on choices
{//dont place  a queen
queens.push_back(-1);
 rec(level+1,qleft);
queens.pop_back();
}
{
     if(qleft>0){
for(int col = 0; col<n; col++){//choices
    //check if its valid
   if(check(level,col)){
    //make the choice
    queens.push_back(col);
    //recurse on next level
    rec(level+1,qleft);
    //revert back
    queens.pop_back();
   }
    }
}


}

}
int main(){
int n;
cin>>n;
int k;
cin>>k;
rec(n,k);

    return 0;

    
}