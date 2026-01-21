#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<int, int> &a, pair<int,int>&b){
    //ai,bi..................ai+1, bi+1
    return a.first+a.second> b.first+b.second;
}
int main(){
int n;
cin>> n;
vector<pair<int,int>> cards(n);
for(int i =0; i<n; i++){
    cin>>cards[i].first>> cards[i].second;
}
sort(cards.begin(), cards.end(), cmp);
for(auto v: cards){
    cout<<v.first<<" "<<v.second<<endl;
}
    return 0;
}