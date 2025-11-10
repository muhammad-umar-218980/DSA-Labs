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

    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;
    int diameter;

    BST() {
        root = nullptr;
        diameter = 0;
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr)
            return new TreeNode(value);

        if (value < node->val)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight + rightHeight > diameter)
            diameter = leftHeight + rightHeight;

        return max(leftHeight, rightHeight) + 1;
    }

    int getDiameter() {
        height(root);
        return diameter;
    }
};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(6);
    tree.insert(15);
    tree.insert(3);
    tree.insert(8);
    tree.insert(20);

    cout << "Diameter of BST: " << tree.getDiameter() << endl;
    return 0;
}
