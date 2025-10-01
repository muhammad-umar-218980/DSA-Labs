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
        (*this).data = data;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void Enqueue(int val) {
        Node* n = new Node(val);
        if (isEmpty()) {
            front = rear = n;
            n->next = front;
            return;
        }
        n->next = front;
        rear->next = n;
        rear = n;
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return ;
        }
        if (front == rear) {
            delete front;
            front = rear = nullptr;
            return ;
        }
        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
        return ;
    }

    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        Node* current = front;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != front);
        cout <<current->data<< "(back to front) " << "\n\n";
    }
};

int main() {
    CircularQueue cq;

	for(int i = 1 ; i <= 5 ; i++){
		cq.Enqueue(i);
	}
	
	cq.print();
	
	
	cq.Dequeue();
	cq.print();
	cout << "Peek of Queue = " << cq.peek() << "\n\n";
	
	
	cq.Dequeue();
	cq.print();
	cout << "Peek of Queue = " << cq.peek() << "\n\n";
	
	for(int i = 101 ; i <= 110;i++){
		cq.Enqueue(i);
	}
	
	cq.print();
	cq.Dequeue();
	cq.Dequeue();
	cq.Dequeue();
	cq.Dequeue();
	
	cq.print();
	cout << "Peek of Queue = " << cq.peek() << "\n\n";
	
	

    return 0;
}
