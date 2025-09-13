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

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node* deleteDuplicates(Node* head) {
    Node* current = head;
    
    while (current != nullptr && current->next != nullptr) {
    	
        if (current->data == current->next->data) {
            Node* duplicateNode = current->next;
            current->next = duplicateNode->next;
            delete(duplicateNode);
        } else {
            current = current->next;
        }
    }
    return head;
}

void push_back(Node*& head, int val) {
    Node* n = new Node(val);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    push_back(head, 1);
    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 3);
    push_back(head, 4);

    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
