#include<bits/stdc++.h>
using namespace std;
struct bag{
int k;
int sumk;
multiset<int>m1,m2;
void init (int _k){
k= _k;
sumk=0;
m1.clear();
m2.clear();
}
// if size of m1 is greater than k 
//then we remove smallest element and move it to m2
void insert(int x){
    m1.insert(x);
    sumk+=x;
if(m1.size()>k){
    auto it = m1.begin();
    sumk-= *it;
    m2.insert(*it);
    m1.erase(it);
}

}
void remove(int x){
    // if element is in m1
    if(m1.find(x)!=m1.end()){
m1.erase(m1.find(x));
sumk-= x;
    }
    // if element is in m2
   else if(m2.find(x)!=m2.end()){
    m2.erase(m2.find(x));

   }
    // if size of m1 is smaller than k
    if(m1.size()<k && !m2.empty()){
        auto it = m2.end(); it--;
        int val = *it;
        m2.erase(val);
        m1.insert(val);
        sumk+= val;
    }
}
int getSum (){
    return sumk;
}
};
int main(){
    return 0;
}


