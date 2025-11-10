#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int v) {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        if (!head) {
            head = new ListNode(value);
            return;
        }

        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = new ListNode(value);
    }

    int getSize() {
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = nullptr;
    }

    TreeNode* sortedListToBST(ListNode*& head, int size) {
        if (size <= 0)
            return nullptr;

        TreeNode* leftSubtree = sortedListToBST(head, size - size / 2 - 1);

        TreeNode* node = new TreeNode(head->val);
        node->left = leftSubtree;

        head = head->next;

        node->right = sortedListToBST(head, size / 2);

        return node;
    }

    void buildFromList(LinkedList& list) {
        int size = list.getSize();
        ListNode* temp = list.head;
        root = sortedListToBST(temp, size);
    }

    void inOrder(TreeNode* node) {
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
    LinkedList list;

    list.insert(-10);
    list.insert(-3);
    list.insert(0);
    list.insert(5);
    list.insert(9);

    BST tree;
    tree.buildFromList(list);

    cout << "In-order traversal of height-balanced BST: ";
    tree.inOrder();

    return 0;
}
