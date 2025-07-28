#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<long long> flowers(n);
    for(int i =0; i<n;i++) cin>> flowers[i];

    long long min_el = *min_element(flowers.begin(), flowers.end());
    long long max_el = *max_element(flowers.begin(), flowers.end());
    long long diff = max_el- min_el;
    long long min_count = count(flowers.begin(), flowers.end(), min_el);
    long long max_count = count(flowers.begin(), flowers.end(), max_el);

    long long ways;
    if(min_el== max_el){
        ways = (1LL* n * (n-1))/2;
    } else{
        ways = min_count* max_count;
    }
    cout<< diff << " "<< ways ;
    return 0;

}