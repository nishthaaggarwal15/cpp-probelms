#include <bits/stdc++.h>
using namespace std;

/*
Manacher’s algorithm is a smart way to find the longest palindrome in a string very fast.
 First, it changes the string by putting special characters (like #) between letters so that it treats even-length and odd-length palindromes the same way.
  Then, it goes through each position in this new string and uses information from a palindrome it already found to skip checking some parts again.
   It keeps track of the rightmost palindrome it has found and uses its mirror positions to guess how far the palindrome at the current position might go.
    Only if needed, it tries to expand the palindrome by comparing characters on both sides.
     Because of this clever trick, it doesn’t check the same things again and again, so the whole process runs very quickly—in linear time.
*/
vector<int> p;

void manachar(string s){                
    int n = s.length();
    p.assign(n, 0);                   
  int l = 0, r = -1;                   
    for(int i = 0; i < n; i++){
        int mirror = l + r - i;          
      if(i <= r)
            p[i] = min(r - i + 1, p[mirror]);
        else
            p[i] = 1;

 while(i - p[i] >= 0 && i + p[i] < n &&
              s[i - p[i]] == s[i + p[i]]){
            p[i]++;
        }

        if(i + p[i] - 1 > r){
            l = i - p[i] + 1;
            r = i + p[i] - 1;
        }
    }
}

void build(string s){
    string t = "#";                      
    for(auto i : s){
        t += i;
        t += "#";                       
    }
    manachar(t);
}

int getLongest(int cen, int odd){
    int pos = 2 * cen + 1 + (!odd);     
    return p[pos] - 1;                 
}

bool checkPalindrome(int l, int r){
    int len = r - l + 1;
    int cen = (l + r) / 2;
    return getLongest(cen, (l % 2) == (r % 2)) >= len;
}

int main(){
    return 0;
}
