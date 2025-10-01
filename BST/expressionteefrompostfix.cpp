#include <bits/stdc++.h>
using namespace std;

struct node {
    string val;
    node *left, *right;
    node(string x) : val(x), left(NULL), right(NULL) {}
};

bool isoperator(const string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

node* expressiontree(vector<string> postfix) {
    stack<node*> st;

    for (auto &val : postfix) {
        if (!isoperator(val)) {
            // operand → make leaf node
            st.push(new node(val));
        } else {
            // operator → pop 2 nodes and make new node
            node* right = st.top(); st.pop();
            node* left = st.top(); st.pop();

            node* newNode = new node(val);
            newNode->left = left;
            newNode->right = right;

            st.push(newNode);
        }
    }

    return st.top(); // root of expression tree
}

int main() {
    vector<string> postfix = {"3", "4", "+", "2", "*", "7", "/"};
    node* root = expressiontree(postfix);

    //  root now contains the tree
    return 0;
}
