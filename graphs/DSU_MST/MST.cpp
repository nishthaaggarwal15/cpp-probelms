#include <bits/stdc++.h>
using namespace std;

int parent[100005];  
int sizee[100005];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}


void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sizee[a] < sizee[b]) swap(a, b);
    parent[b] = a;
    sizee[a] += sizee[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sizee[i] = 1;
    }

    vector<pair<int, pair<int,int>>> edgelist;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edgelist.push_back({c, {a, b}});
    }

    sort(edgelist.begin(), edgelist.end());

    long long mst_cost = 0; 
    int cnt = 0;

    for(auto v : edgelist) {
        int x = v.second.first; //a
        int y = v.second.second;//b
        if(find(x) != find(y)) {
            merge(x, y);
            mst_cost += v.first;
            cnt++;
        }
    }

    if(cnt != n-1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << mst_cost << "\n";
    }

    return 0;
}
