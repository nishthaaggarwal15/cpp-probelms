#include<bits/stdc++.h>
using namespace std;
class SnapshotArray{
int snapid;
vector<vector<pair<int,int>>>history;
public:
SnapshotArray(int length){
snapid=0;
history.resize(length);
for(int i =0; i<length; i++){
    history[i].push_back({0,0});
}
}
void set(int index,int val){
history[index].push_back({snapid,val});
}
int snap(){
return snapid++;
}
int get(int index, int snapid){
auto &vec= history[index];
int left = 0;
int right = vec.size()-1;
while(left<=right){
    int mid = (left+right)/2;
if(vec[mid].first<=snapid){
    left = mid+1;
} else{
    right= mid-1;
}
}
return vec[right].second;
}
};
int main(){
    return 0;
}