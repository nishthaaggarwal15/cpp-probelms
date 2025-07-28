#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>> s;
    int q;
    cin>> q;
    deque<int> d;
    int is_flipped =0;
    while(q--){
      int op ;
      cin>>op;
      if(op==1){
        if(is_flipped=0){
            is_flipped=1;
        } else{
            is_flipped=0;
        }
      }else{
        int f;
        char c;
        cin>>f>>c;
         if(f==1){
            if(is_flipped==0){
                if(f==1){
                    d.push_front(c);
                } else{
                    d.push_back(c);
                }
            } else{
                if(f==1){   
                    d.push_back(c);     

            }
            else{
                d.push_front(c);
            }
         }
      }
      if(is_flipped==1){
        reverse(d.begin(), d.end());
      }
      for(int i : d){
        cout<< i<<" ";
      }
      cout<< endl;
    }}
    return 0;
}