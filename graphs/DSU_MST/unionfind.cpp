#include <bits/stdc++.h>
using namespace std;

int parent[100005], size[100005];

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]); // path compression
    }
    return parent[x]; // always return root
}

void unite(int a, int b, int &components){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]) swap(a, b); // union by size
        parent[b] = a;
        size[a] += size[b];
        components--; // two components merged
    }
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }

    int components = n; // total components initially

    while(q--){
        int c, a, b;
        cin >> c >> a >> b;

        if(c == 0){ // unite query
            unite(a, b, components);
            cout << components << "\n";
        } else {    // check if same component
            cout << (same(a, b) ? 1 : 0) << "\n";
        }
    }
    return 0;
}
