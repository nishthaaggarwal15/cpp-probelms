#include<bits/stdc++.h>
using namespace std;

 string t;

vector<int> kmp(string s){
    int n = s.length();
    vector<int> kmp(n + 1);
    int i =0, j=-1; kmp[0]=-1;
    while(i<n){
while(j!=-1 && s[i]!=s[j])j= kmp[j];
j++;i++;
kmp[i]=j;
    }
    return kmp;
}
int main(){
    cin>>t;
     string r = t;                 
    reverse(r.begin(), r.end());  
    string w = r + "#" + t;      
    vector<int> arr = kmp(w);

    int n = t.size();
    int ans = t.size() - arr[2*n + 1];
   
   cout <<ans<<endl;
    return 0;
}