#include<bits/stdc++.h>
using namespace std;
// when there are diffrent kinda paranthesis lile ({[]})
 map<char,int>mp;
string s;
bool check(){
stack<int>st;
for(auto v: s){
    int val = mp[v];
    if(val>0){
        //open bracket
        st.push(val);
    } else {
        //close bracket
        if(!st.empty()&& st.top()+val==0){
         st.pop();
        } else{
       return false;
        }
    }
}
if(!st.empty()) return false;
return true;
}
int main(){
   
mp['(']= +1;
mp['{'] = +2;
mp['[']=+3;
mp[')']= -1;
mp['}'] = -2;
mp[']']=-3;
int ans = check();
cout <<ans;
    return 0;
}