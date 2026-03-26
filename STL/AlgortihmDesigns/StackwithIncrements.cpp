#include<bits/stdc++.h>
using namespace std;
class CustomStack{
vector<int>st;
vector<int>inc;
int maxsize;
public: 
CustomStack(int maxsize){
this->maxsize= maxsize;
}
void push(int x){
if(st.size()==maxsize){
    return;
}
st.push_back(x);
inc.push_back(0);
}
int pop(){
if(st.empty())return -1;
int i =st.size()-1;
int res = st.back()+inc[i];
if(i>0){
    inc[i-1]+= inc[i];
    st.pop_back();
    inc.pop_back();
}
}
void increment(int k, int val){
int i = min(k,(int)st.size())-1;
if(i>=0){
    inc[i]+= val;
}
}
};
int main(){
    return 0;
}