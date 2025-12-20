#include<bits/stdc++.h>
using namespace std;

int n; 
string s;
int k;

int arr[1010];
int dp[1010][4][1010];
int back[1010][4][1010];// to store the choices to print them


map<char,int> mp; // to map p r s
string final_ans;// final ans in char

int win(int ch1, int ch2){
    // P=0, R=1, S=2
    if((ch1==0 && ch2==1) ||   
       (ch1==1 && ch2==2) ||  
       (ch1==2 && ch2==0))    
        return 1;
    return 0;
}

int rec(int level, int lastchoice, int count){ // at current level what was the lastchoice and what count is left of k
    if(count < 0) return -1e9;
    if(level == n) return 0;

    if(dp[level][lastchoice][count] != -1){
        return dp[level][lastchoice][count];
    }

    int ans = -1e9;
    back[level][lastchoice][count] = -1;

    int order[3] = {0,1,2}; // P < R < S

    for(int idx = 0; idx < 3; idx++){ //traverse all 3 of them
        int i = order[idx];

        int add;
        if(lastchoice == 3) add = 0;        // first move
        else if(i == lastchoice) add = 0; // if last choice is same as curr oone then it'll not cost us
        else add = 1; // else it will cost us

        int curr = win(i, arr[level]) + rec(level + 1, i, count - add); // cost of change win(if mychoice is not same as opp choice and it beats the opp then win will increment)

        if(curr > ans || (curr == ans && i < back[level][lastchoice][count])){ // if curr is greater than last calc or maybe is equal but we want lexo order so we make this i (current choice as newer lexo)
            ans = curr;
            back[level][lastchoice][count] = i;
        }
    }
    return dp[level][lastchoice][count] = ans;
}

void generate(int level, int lastchoice, int count){
    if(level == n) return;

    int x = back[level][lastchoice][count]; // curr choice at this state

    if(x == 0) final_ans.push_back('P');
    if(x == 1) final_ans.push_back('R');
    if(x == 2) final_ans.push_back('S');

    int add;
    if(lastchoice == 3) add = 0;
    else if(x == lastchoice) add = 0;
    else add = 1; // transition for next states 

    generate(level + 1, x, count - add);
}

void solve(){
    cin >> n >> k;
    cin >> s;

    for(int i = 0; i < n; i++){
        arr[i] = mp[s[i]];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            for(int x = 0; x <= k; x++){
                dp[i][j][x] = -1;
                back[i][j][x] = -1;
            }
        }
    }

    int ans = rec(0, 3, k);   // 3 = no previous move
    cout << ans << "\n";

    generate(0, 3, k);
    cout << final_ans << "\n";
    final_ans.clear();
}

int main(){
    mp['P'] = 0;
    mp['R'] = 1;
    mp['S'] = 2;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
