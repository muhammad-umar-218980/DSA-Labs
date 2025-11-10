#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        this->key = k;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* balance(Node* node) {
        updateHeight(node);
        int bf = balanceFactor(node);
        if (bf > 1) {
            if (balanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (bf < -1) {
            if (balanceFactor(node->right) > 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* insertFunc(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insertFunc(node->left, key);
        else if (key > node->key)
            node->right = insertFunc(node->right, key);
        else
            return node;
        return balance(node);
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return node;
        
        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
            
        else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* inOrderSuccessor = minValueNode(node->right);
                node->key = inOrderSuccessor->key;
                node->right = deleteNode(node->right, inOrderSuccessor->key);
            }
        }
        if (!node) return node;
        return balance(node);
    }

    void insert(int key) { root = insertFunc(root, key); }
    void deleteKey(int key) { root = deleteNode(root, key); }

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
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "In-order traversal before deletion: ";
    tree.inOrder();

    tree.deleteKey(20);

    cout << "In-order traversal after deleting 20: ";
    tree.inOrder();

    return 0;
}
