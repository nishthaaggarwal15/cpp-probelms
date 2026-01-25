#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[1001];
struct monotonic_deque {
    deque<int> dq;
    void insert(int x){
     while(!dq.empty() && dq.back()>x) dq.pop_back();
     dq.push_back(x);
    }
 void remove(int x){
if(dq.front()==x) dq.pop_front();
 }
 int getmin(){
    return dq.front();
 }
};
int main(){
    cin>>n>>k;
    monotonic_deque mt;
for(int i =0; i<n; i++){
mt.insert(arr[i]);
if(i-k>=0)mt.remove(arr[i-k]);
if(i>=k-1) cout<<mt.getmin()<<endl;
}
    return 0;
}