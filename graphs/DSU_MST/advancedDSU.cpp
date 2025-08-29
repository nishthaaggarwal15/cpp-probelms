#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second 
using state = pair<int,int>;

vector <int> rankz;         // ✅ extra: actually this is "size", not rank
vector<state> par;          // par[i] = {parent, distance_from_parent}
int n,q;

state finda(int x){
if(par[x].F == x){
    return par[x];          // if node is root, return itself
}
int parent = par[x].F;
state temp = finda(parent);
return par[x]= {temp.F, temp.S+par[x].S};  // ✅ extra: path compression with distance update
}

void merge(int x,int y, int z){
state rootX = finda(x);
state rootY = finda(y);
if(rootX.F == rootY.F){
int existing = par[x].S - par[y].S;// if they have same root check the
 //z value given is same as present in graph
 if(existing!=z){
    cout<<"Inconsistent"<<endl;
 }
 else{
    cout<<"Consistent"<<endl;
 }
 return;
}
// merge smaller graph to larger one
if(rankz[rootX.F]<=rankz[rootY.F]){ 
    rankz[rootY.F]+=rankz[rootX.F]; 
    par[rootX.F]= {rootY.F, par[y].S+z-par[x].S}; 
    // ✅ extra: formula ensures distance consistency when merging X under Y
} else{
    rankz[rootX.F]+= rankz[rootY.F];
    par[rootY.F]= {rootX.F, par[x].S-z-par[y].S};
    // ✅ extra: formula ensures distance consistency when merging Y under X
}
}

void solve(){
 cin>>n>>q;
    par.resize(n+1);            // ✅ extra: size = n+1 (1-indexed input)
    rankz.assign(n+1,1);        
    for(int i =1; i<=n; i++){   
        par[i]= {i,0};// initially each node is its own parent and dist is 0
    }
    while(q--){
        int choice; cin>>choice;
        if(choice ==0){
            int x, y,z;
            cin>>x>>y>>z;
            merge(x,y,z);
        }
        else{
            int x ,y;
            cin>>x>>y;
            state rootx = finda(x);
          state rooty = finda(y);
            if(rootx.F!=rooty.F){    
                cout<<"?"<<endl;
            } else{
          cout<<par[x].S- par[y].S<<endl;
          //dist[x->root]- dist[y->root]= z;(dist[x->y])
          // ✅ extra: par[x].S = dist(x→root), par[y].S = dist(y→root)
            }
        }

    }
  
}
int main(){
    solve(); 
   return 0;
}
