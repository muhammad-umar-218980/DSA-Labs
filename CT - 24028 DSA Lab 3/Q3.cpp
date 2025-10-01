#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
*/

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = prev = nullptr;
    }
};

class Doubly_Linked_List {
public:
    Node* head;
    Node* tail;
    Doubly_Linked_List() {
        head = tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push_back(int val) {
        Node* n = new Node(val);
        if (isEmpty()) {
            head = tail = n;
            return;
        }
        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr\n\n";
    }

};


Doubly_Linked_List concatenate(Doubly_Linked_List L, Doubly_Linked_List M) {
    Doubly_Linked_List N;

    Node* temp = L.head;
    while (temp != nullptr) {
        N.push_back(temp->data);
        temp = temp->next;
    }

    temp = M.head;
    while (temp != nullptr) {
        N.push_back(temp->data);
        temp = temp->next;
    }

    return N;
}

int main() {
    Doubly_Linked_List L; // Doubly Linked List for Even Numbers
    Doubly_Linked_List M; // Doubly Linked List for Odd Numbers

    for (int i = 2; i <= 10; i += 2) L.push_back(i);
    cout << "List L : \n";
    L.print();

    for (int i = 1; i <= 9; i += 2) M.push_back(i);
    cout << "List M : \n";
    M.print();

    Doubly_Linked_List N = concatenate(L, M);
    cout << "List N (concatenation of L and M): \n";
    N.print();

    return 0;
}
