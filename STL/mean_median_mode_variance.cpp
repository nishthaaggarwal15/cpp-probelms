#include<bits/stdc++.h>
using namespace std;
struct{
    //mean and variance
    int sum =0;
    int sumsq=0;
    int count =0;
//median
    multiset<int>lo,hi;
    //mode
    map<int,int> mp;
    multiset<pair<int,int>> mt;
    void balance(){
if(lo.size()<hi.size()){
    auto it = *hi.begin();
    hi.erase(hi.find(it));
    lo.insert(it);
}
else if(lo.size()>hi.size()+1){
    auto it = *lo.rbegin();
    lo.erase(lo.find(it));
    hi.insert(it);
}
   
}

void insert(int x){
//mean and variance
sum+= x;
sumsq+= x*x;
count++;
// mode 
if(mt.find(make_pair(mp[x],x)) != mt.end()){
    mt.erase(mt.find(make_pair(mp[x],x)));
}
mp[x]++;
mt.insert(make_pair(mp[x],x));
//median
if(lo.empty()) lo.insert(x);
else if(*lo.rbegin()>= x) lo.insert(x);
else hi.insert(x);
balance();
}

void remove(int x){
    //mean and variance
sum-=x;
sumsq-=x*x;
count--;
//median
if(hi.find(x)!=hi.end()){
    hi.erase(hi.find(x));
} else{
    lo.erase(lo.find(x));
}
//mode
if(mt.find(make_pair(mp[x],x)) != mt.end()){
    mt.erase(mt.find(make_pair(mp[x],x)));
}
mp[x]--;
mt.insert(make_pair(mp[x],x));
}
double mean(){
return sum/count;
}
double mode(){
return mp.rbegin()->second;
}
double median(){
if((lo.size()+ hi.size())%2){
    return *lo.rbegin();
} else{
    return (*lo.rbegin()+ (*hi.begin()))/2.0;
}
}
double variance(){
int ans = mean();
return  sumsq/count -(ans*ans); 
}

};
int main(){
    return 0;
}