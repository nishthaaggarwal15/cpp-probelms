#include<bits/stdc++.h>
using namespace std;
static const long long MOD = 1000000007;

long long modpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long x){
    return modpow(x, MOD - 2);
}

struct ans{
    //mean and variance
    long long sum =0;
  long long sumsq=0;
  long long count =0;
//median
    multiset<int>lo,hi;
    //mode
    map<int,int> mp;
 multiset<pair<int,long long>> mt;

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
if(mt.find(make_pair(mp[x],-x)) != mt.end()){
    mt.erase(mt.find(make_pair(mp[x],-x)));
}
mp[x]++;
if(mp[x] == 0){
    mp.erase(x);
} else {
    mt.insert({mp[x], -x});
}

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
auto it = lo.find(x);
if(it != lo.end()) lo.erase(it);
else hi.erase(hi.find(x));

//mode
if(mt.find(make_pair(mp[x],-x)) != mt.end()){
    mt.erase(mt.find(make_pair(mp[x],-x)));
}
mp[x]--;
if(mp[x] == 0){
    mp.erase(x);
} else {
    mt.insert({mp[x],- x});
}

balance();
}


// double mean(){
// return sum/count;
// }
long long mean(){

    return (sum % MOD) * inv(count) % MOD;
}

// double mode(){
// return -mt.rbegin()->second;
// }
long long mode(){
    return -mt.rbegin()->second;
}


// double median(){
// if((lo.size()+ hi.size())%2){
//     return *lo.rbegin();
// } else{
//     return (*lo.rbegin()+ (*hi.begin()))/2.0;
// }
// }
long long median(){
    if((lo.size() + hi.size()) % 2 == 1){
        // odd
        return *lo.rbegin();
    } else {
        // even
        long long a = *lo.rbegin();
        long long b = *hi.begin();
        return ((a + b) % MOD) * inv(2) % MOD;
    }
}




};
int main(){
    int t;
    cin>>t;
    while(t--){
        int q;
          cin>>q;
         ans bag;
        while(q--){
    string s;
    cin >> s;

    if(s == "insert"){
        int x; cin >> x;
        bag.insert(x);
    }
    else if(s == "remove"){
        int x; cin >> x;
        bag.remove(x);
    }
    else{
        if(bag.count == 0){
            cout << -1 << "\n";
            continue;
        }
        if(s == "getMean") cout << bag.mean() << "\n";
        else if(s == "getMedian") cout << bag.median() << "\n";
        else if(s == "getMode") cout << bag.mode() << "\n";
    }
}


        }
          return 0;
    }
  
