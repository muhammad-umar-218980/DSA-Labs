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

int sumOfNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum + rightSum + root->val;
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

    int totalSum = sumOfNodes(root);
    cout << "Sum of all nodes: " << totalSum << endl;

    return 0;
}
