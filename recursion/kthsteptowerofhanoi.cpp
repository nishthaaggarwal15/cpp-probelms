#include<bits/stdc++.h>
using namespace std;

void findkthmove(int disks, int src, int dest, int h, int k ){
  if(k<=(1<<(disks-1))-1)  {
    findkthmove(disks-1, src, h,  dest , k);
     
    }
   else if (k==(1<<(disks-1))) {
    cout<< "move from"<<  src << " to"<< dest<<endl;
    }
   else {
      findkthmove(disks-1, h, dest, src, k-(1<<(disks-1)));
    }
}

int main(){
    for(int i =1; i<=7; i++){
        findkthmove(3,1,3,2,i);
    }

    return 0;
}