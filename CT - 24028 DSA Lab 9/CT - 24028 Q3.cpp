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

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    TreeNode* leastCommonAncestor(int n1, int n2) {
        return leastCommonAncestorRec(root, n1, n2);
    }

private:
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == nullptr)
            return new TreeNode(key);
        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);
        return node;
    }

    TreeNode* leastCommonAncestorRec(TreeNode* node, int n1, int n2) {
        if (node == nullptr) return nullptr;

        if (node->val > n1 && node->val > n2)
            return leastCommonAncestorRec(node->left, n1, n2);

        if (node->val < n1 && node->val < n2)
            return leastCommonAncestorRec(node->right, n1, n2);

        return node;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    int n1 = 5, n2 = 15;
    TreeNode* lca = bst.leastCommonAncestor(n1, n2);

    if (lca != nullptr)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
