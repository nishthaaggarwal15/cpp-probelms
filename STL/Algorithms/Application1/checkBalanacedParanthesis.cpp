#include<bits/stdc++.h>
using namespace std;
//depth -1 when there is only one kind of bracket
string s;
bool check(){
int depth =0;
for(auto v: s){
    if(v=='('){
        depth++;
    } else{
        depth--;
    }
    if(depth<0) return false;

}
if(depth!=0) return false;
return true;
}

int main(){
cin>>s;
int ans = check();
cout<<ans<<endl;
}