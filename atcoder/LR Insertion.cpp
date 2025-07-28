/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int q ;
    cin>> q;
    deque<char> dq(s.begin(), s.end());
    int is_flipped =0;
    
    while(q-->0){
        int op;
        cin>>op;
      if(op==1){
          if(is_flipped==0){
              is_flipped=1;
          } else{
              is_flipped=0;
          }
      } else{
          int side;
          char ch ;
          cin>> side>> ch;
          if(is_flipped){
              side = (1+2)-side;
          }
          if(side==1){
              dq.push_front(ch);
          } else{
              dq.push_back(ch);
          }
      }
     
    }
    
     if(is_flipped){
          reverse(dq.begin(), dq.end());
      }
      for (int i = 0; i < dq.size(); i++) {
        cout << dq[i];
    }
      cout<<endl;
    return 0;
}