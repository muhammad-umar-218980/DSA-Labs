#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class deque {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    deque(int n) {
        arr = new int[n];
        front = 0;
        rear = -1;
        size = 0;
        capacity = n;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void insertRear(int x) {
        if(isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void insertFront(int x) {
        if(isFull()) return;
        front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        size++;
    }

    void deleteFront() {
        if(isEmpty()) return;
        front = (front + 1) % capacity;
        size--;
    }

    void deleteRear() {
        if(isEmpty()) return;
        rear = (rear - 1 + capacity) % capacity;
        size--;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }

    int getSize() {
        return size;
    }

    ~deque() {
        delete[] arr;
    }
};

int findWinner(int n, int k) {
    deque dq(n);
    for(int i = 1; i <= n; i++) {
        dq.insertRear(i);
    }

    while(dq.getSize() > 1) {
        for(int i = 0; i < k - 1; i++) {
            int temp = dq.getFront();
            dq.deleteFront();
            dq.insertRear(temp);
        }
        dq.deleteFront();
    }
    return dq.getFront();
}

int main() {
    int n, k;

    cout << "Enter the number of friends (n): ";
    cin >> n;

    cout << "Enter the counting number (k): ";
    cin >> k;

    while(k > n) {
        cout << "\nInvalid! Counting number (k) cannot be greater than number of friends (n)." << endl;
        cout << "Please enter a valid counting number (k): ";
        cin >> k;
    }

    int winner = findWinner(n, k);

    cout << "\nThe winner of the game is Friend no." << winner << endl;

    return 0;
}
