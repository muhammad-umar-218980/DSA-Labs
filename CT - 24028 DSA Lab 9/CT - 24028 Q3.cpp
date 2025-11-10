#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    return root;
}

TreeNode* leastCommonAncestor(TreeNode* root, int n1, int n2) {
    if (root == nullptr) return nullptr;

    if (root->val > n1 && root->val > n2)
        return leastCommonAncestor(root->left, n1, n2);

    if (root->val < n1 && root->val < n2)
        return leastCommonAncestor(root->right, n1, n2);

    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    int n1 = 5, n2 = 15;
    TreeNode* lca = leastCommonAncestor(root, n1, n2);

    if (lca != nullptr)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
