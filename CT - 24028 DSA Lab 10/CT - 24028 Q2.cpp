#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        Node* node = new Node(nums[mid]);
        node->left = sortedArrayToBST(nums, start, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, end);
        return node;
    }

    void buildTree(vector<int>& nums) {
        root = sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    BST tree;
    tree.buildTree(nums);

    cout << "In-order traversal of height-balanced BST: ";
    tree.inOrder();

    return 0;
}
