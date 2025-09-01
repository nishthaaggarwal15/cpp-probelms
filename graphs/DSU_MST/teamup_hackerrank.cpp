#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 100100;  // adjust size
int par[MAXN*2], sizee[MAXN*2], power[MAXN*2], team[MAXN];
void init(){
    for (int i =1; i<=n; i++){
        sizee[i]= 1;
        par[i]=i;
        team[i]=i;
        power[i]=i;
    }
}

int find(int x){
if(par[x]==x) return x;
par[x]= find(par[x]);
return par[x];
}
void merge(int a, int b){
int x = find(a);
int y = find(b);
if(x!=y){
    if(sizee[x]<sizee[y]) swap(x,y);
    sizee[x]+= sizee[y];
    power[x]+= power[y];
    par[y]= x;
}
}
void move(int person , int team1, int team2){
int t1= find(team1);
int t2= find(team2);
if(t1==t2)return;
sizee[t1]--;
power[t1]-=person;
sizee[t2]++;
power[t2]+=person;
team[person]= t2;
}
void solve(){
    int q;
    cin>>q;
    init();
    while(q--){
        int ch; 
        cin>>ch;
        if(ch==1){
int a,b;
cin>>a>>b;
a = team[a];
b = team[b];
merge(a,b);// merge teams instead of child
        }
       else if(ch==2){
     int a ;
     cin>>a;
     a = team[a];
     a = find(a);// find root of a and print it's size and strentgth
     cout<< sizee[a]<< " " << power[a];
        }
       else if(ch==3){
int a ,b;
cin>>a>>b;
move(a, team[a],team[b]);
        }
    }
}
int main(){
    int T; 
    cin >> T;
    while(T--){
        cin >> n;
        solve();
        cout << "\n";
    }
    return 0;

}