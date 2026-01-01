#include<bits/stdc++.h>
using namespace std;

vector<int>  solve(string s){
    int n;
vector<int> z(n);
    int l =0; int r=0;
    for(int i =1; i<n; i++){
        if(i>r){
           l=r=i;
           while(r<n && s[r-l]== s[r]){
            r++;
           }
           z[i]= r-l; r--;
        } else{
            int k =i-l;
            if(z[k]<r-i+1)z[i]=z[k];
            else{
                l=i;
           while(r<n && s[r-l]== s[r]){
            r++;
           }
           z[i]= r-l; r--;
            }
        }
    }
    return z;
}
int main(){
    string text = "aabxaabxcaabxaabxay"; 
    vector<int> Z = solve(text); 
    cout << "The Z-array is: ";
     for (int i = 0; i < Z.size(); i++) 
     { 
        cout << Z[i] << " ";
     } 
      cout << endl;
    return 0;
}