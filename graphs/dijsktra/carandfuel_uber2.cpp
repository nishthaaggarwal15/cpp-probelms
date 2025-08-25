#include<bits/stdc++.h>
using namespace std;
int n,m,k;
using state = pair<int,int>;
#define mp make_pair
#define INF 1e9
#define F first
#define S second
vector<vector<pair<int,int>>> g; // {neigh, dist}
int dist[10005][105]; 
int visited[10005][105];
int c[10005];

void dijkstra(state st, int B){
    //initializing values
    for(int i =0;i<=n; i++){
        for(int j =0; j<=k; j++){
            dist[i][j]=INF;
            visited[i][j]=0;
        }
    }
    // make queue and push start
    priority_queue<pair<int,state>>q; //- {dist,{node,fuel}}
    dist[st.F][st.S]=0;
    q.push(mp(0,st));
    //until queue is empty
    while(!q.empty()){
        auto val = q.top();
        q.pop();
        int curr_dist = -val.F;// dist(cost)
        int curr_state_node = val.S.F;// {node,fuel left}
        int curr_state_fuel = val.S.S;

        /// 1.check visited
        if(visited[curr_state_node][curr_state_fuel]==1) continue;
        visited[curr_state_node][curr_state_fuel]=1;

        ///2.all neighbours
        for(auto v : g[curr_state_node]){
            int newnode = v.first;
            int needFuel = v.second;

            if(curr_state_fuel>=needFuel){ 
                if(dist[newnode][curr_state_fuel-needFuel]> curr_dist){
                    dist[newnode][curr_state_fuel-needFuel]=curr_dist;
                    q.push(mp(-dist[newnode][curr_state_fuel-needFuel],
                              mp(newnode,curr_state_fuel-needFuel)));
                }
            }
        }

        /// 3. extra relaxation here, option to refill
        if(curr_state_fuel<k){
            if(dist[curr_state_node][curr_state_fuel+1]> curr_dist+c[curr_state_node]){
                dist[curr_state_node][curr_state_fuel+1]=curr_dist+c[curr_state_node];
                q.push(mp(-dist[curr_state_node][curr_state_fuel+1],
                          mp(curr_state_node,curr_state_fuel+1)));
            }
        }
    }

    cout << *min_element(dist[B], dist[B] + k + 1) << "\n"; 
    }
void solve(){
    cin>>n>>m;
    g.resize(n+1);

    for(int i =0; i<m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        g[a].push_back(mp(b,d)); 
        g[b].push_back(mp(a,d));
    }
    for(int i =1; i<=n; i++)cin>>c[i];

    int A,B,C;
    cin >> A >> B >> C;
    k = C;

    state st = {A,0};
    dijkstra(st,B);
}

int main(){
    solve();
    return 0;
}
