#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int i = s[0] - 'a'; 
        int j = s[1] - 'a'; 
        if (j > i) j--;    
        int index = i * 25 + j + 1;
        cout << index<< endl;
    }
    return 0;
}
