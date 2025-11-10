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

    int getMinDiff() {
        prev = -1;
        minDiff = INT_MAX;
        inOrderMinDiff(root);
        return minDiff;
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

    int prev;
    int minDiff;

    void inOrderMinDiff(TreeNode* node) {
        if (node == nullptr) return;

        inOrderMinDiff(node->left);

        if (prev != -1) {
            int diff = node->val - prev;
            if (diff < minDiff) minDiff = diff;
        }
        prev = node->val;

        inOrderMinDiff(node->right);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);

    cout << "Minimum difference between any two nodes: " << bst.getMinDiff() << endl;

    return 0;
}
