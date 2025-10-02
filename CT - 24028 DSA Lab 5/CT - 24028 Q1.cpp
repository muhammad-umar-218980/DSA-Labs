#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class MyCircularDeque {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        arr = new int[k];
        capacity = k;
        size = 0;
        front = 0;
        rear = -1;
    }

    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        if(size == 0) {
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }
        if(size == 0) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        if(size == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }
        if(size == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return true;
    }

    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    ~MyCircularDeque() {
        delete[] arr;
    }
};

int main() {
    MyCircularDeque dq(3);

    cout << "Inserting 1 at rear: " 
         << (dq.insertLast(1) ? "Success" : "Failed") << endl;

    cout << "Inserting 2 at rear: " 
         << (dq.insertLast(2) ? "Success" : "Failed") << endl;

    cout << "Inserting 3 at front: " 
         << (dq.insertFront(3) ? "Success" : "Failed") << endl;

    cout << "Trying to insert 4 at front (should fail, deque is full): " 
         << (dq.insertFront(4) ? "Success" : "Failed") << endl;

    cout << "Current rear element: " << dq.getRear() << endl;

    cout << "Is deque full? " << (dq.isFull() ? "Yes" : "No") << endl;

    cout << "Deleting last element: " 
         << (dq.deleteLast() ? "Deleted" : "Failed") << endl;

    cout << "Inserting 4 at front: " 
         << (dq.insertFront(4) ? "Success" : "Failed") << endl;

    cout << "Current front element: " << dq.getFront() << endl;

    return 0;
}
