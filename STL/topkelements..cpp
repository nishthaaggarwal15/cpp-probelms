#include<bits/stdc++.h>
using namespace std;
struct bag{
int k;
priority_queue<int>pq;
int sumK;
void init(int _k){
    k= _k;
    sumK=0;
}
void insert(int x){
    sumK+=x;
    pq.push(-x);
    if(pq.size()>k){
int sm = -pq.top();
pq.pop();
sumK-= sm;
    }
}
int topk(){
    return sumK;
}
};
int main(){
    return 0;
}