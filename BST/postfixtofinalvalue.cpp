#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int x): val(x), left(NULL), right(NULL) {}
};

bool isoperator(const string &val) {
    return (val=="-"||val=="+"||val=="*"||val=="/");
}

int handlecase(const string &op, int left, int right){
    if(op=="+") return left+right;
    if(op=="-") return left-right;
    if(op=="/") return left/right;
    if(op=="*") return left*right;
    return 0;
}

node* postfixtofinal(vector<string> postfix){
    stack<node*> st;
    for(auto val: postfix){
        if(isoperator(val)){
            node* rightval = st.top(); st.pop();
            node* leftval = st.top(); st.pop();

            int res = handlecase(val, leftval->val, rightval->val);
            node* newnode = new node(res);

            newnode->left = leftval;
            newnode->right = rightval;

            st.push(newnode);
        } else {
            st.push(new node(stoi(val)));
        }
    }
    return st.top();
}

int main(){
    vector<string> postfix = {"3","4","+","2","*","7","/"};
    node* root = postfixtofinal(postfix);

    cout << "Final Value at Root = " << root->val << endl; // prints 2
    return 0;
}
