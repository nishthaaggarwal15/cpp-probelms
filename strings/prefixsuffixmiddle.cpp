#include<bits/stdc++.h>
using namespace std;

 string t;
int n;
void print(int len ){
   for(int i = 0; i < len; i++){
        cout << t[i];
    }
    cout << "\n";
}
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
    int T ;
    cin>>T;
    while(T--){
        cin>>n;
  cin>>t;
      vector<int> arr = kmp(t);
    int len = arr[n];
  while(len > 0){ // for ffffff
            bool check = false;
            for(int i = 1; i < n; i++){
                if(arr[i] == len){
                    check = true;
                    break;
                }
            }
            if(check){
                print(len);
                break;
            }
            len = arr[len];  
        }
        if(len == 0){
            cout << -1 << "\n";
        }
   
    }
  
    return 0;
}