#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int,int> mp;

TreeNode* build(vector<int>& preorder, int prestart, int preend,
                vector<int>& inorder, int instart, int inend) {
    if (prestart > preend || instart > inend) return NULL;

    int rootval = preorder[prestart];
    TreeNode* root = new TreeNode(rootval);

    int inIndex = mp[rootval];
    int leftsize = inIndex - instart;

    root->left = build(preorder, prestart + 1, prestart + leftsize,
                       inorder, instart, inIndex - 1);

    root->right = build(preorder, prestart + leftsize + 1, preend,
                        inorder, inIndex + 1, inend);

    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
        mp[inorder[i]] = i;
    }
    return build(preorder, 0, n - 1, inorder, 0, n - 1);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n"; 
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    TreeNode* root = buildTree(preorder, inorder);
    printLevelOrder(root);

    return 0;
}
