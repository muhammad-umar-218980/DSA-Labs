#include <iostream>
#include <algorithm>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
*/

class MedianFinder {
    int* arr;
    int size;
    int capacity;

public:
    MedianFinder() {
        capacity = 1;
        size = 0;
        arr = new int[capacity];
    }

    void addNum(int num) {
        if(size == capacity) {
            capacity = capacity * 2;
            int* newArr = new int[capacity];
            for(int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size] = num;
        size++;
        sort(arr, arr + size);
    }

    double findMedian() {
        if(size % 2 == 1) {
            return arr[size / 2];
        }
        
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;

    }

    ~MedianFinder() {
        delete[] arr;
    }
};

int main() {
    MedianFinder* medianFinder = new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(2);
    cout << medianFinder->findMedian() << endl;
    medianFinder->addNum(3);
    cout << medianFinder->findMedian() << endl;
    return 0;
}
