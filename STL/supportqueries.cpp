#include<bits/stdc++.h>
using namespace std;
struct bag{
    int curr_sum =0;
    map<int, int>mp;
    void insert(int x){
curr_sum+= x;
mp[x]++;
    }
void remove(int x){
curr_sum-=x;
mp[x]--;
if(mp[x]==0){
    mp.erase(x);
}

}
int getmax(){
return (*mp.rbegin()).first;// rbegin refers to last element and mp.end takes it outside thats why we use rbegin
}
int getmin(){
    return (*mp.begin()).first;
}
int sum(){
return curr_sum;
}
int getdistinct(){
return mp.size();
}
};
int main(){
    return 0;
}