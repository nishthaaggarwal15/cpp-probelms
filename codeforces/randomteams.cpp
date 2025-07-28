#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    long long max_team_size= (n-m+1);
    long long kmax= (max_team_size * (max_team_size-1))/2;
    long long x = n/m;
    long long r = n%m;
    long long kmin = (((x+1)*x)/2)*r + (m-r)*((x*(x-1))/2);
    cout<< kmin << " " <<kmax << endl;
    return 0;
}