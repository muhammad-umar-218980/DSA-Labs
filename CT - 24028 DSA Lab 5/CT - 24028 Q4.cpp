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

    Node(int val) {
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int val) {
        Node* n = new Node(val);
        size++;
        if(front == nullptr) {
            front = rear = n;
            return;
        }
        rear->next = n;
        n->prev = rear;
        rear = n;
    }

    int dequeue() {
        if(front == nullptr) return -1;
        Node* temp = front;
        int val = temp->data;
        front = front->next;
        if(front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        size--;
        return val;
    }

    Node* getRear() {
        return rear;
    }

    int getSize() {
        return size;
    }
};

class ProductOfNumbers {
private:
    Queue q;

public:
    void add(int num) {
        q.enqueue(num);
    }

    int getProduct(int k) {
        if(q.getSize() < k) return 0; 
        
        Node* temp = q.getRear();
        int product = 1;
        int i = 0;
        while(i < k && temp != nullptr) {
            int val = temp->data;
            product *= val;
            temp = temp->prev;
            i++;
        }
        return product;
    }
};

int main() {
    ProductOfNumbers PON;

    PON.add(3);
    PON.add(0);
    PON.add(2);
    PON.add(5);
    PON.add(4);

    cout << "Product of last 2 numbers: " << PON.getProduct(2) << endl; 
    cout << "Product of last 3 numbers: " << PON.getProduct(3) << endl; 
    cout << "Product of last 4 numbers: " << PON.getProduct(4) << endl; 

    PON.add(8);

    cout << "Product of last 2 numbers: " << PON.getProduct(2) << endl; 

    return 0;
}
