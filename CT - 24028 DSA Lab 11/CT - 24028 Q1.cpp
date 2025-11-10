#include <iostream>
#include <vector>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class HeapSort {
public:
    void heapify(vector<int> &arr, int n, int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < n && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    void buildMaxHeap(vector<int> &arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    void heapSort(vector<int> &arr) {
        int n = arr.size();
        buildMaxHeap(arr, n);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void printArray(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {20, 15, 30, 40, 10, 5, 25};
    HeapSort hs;
    cout << "Original array: ";
    hs.printArray(arr);
    hs.heapSort(arr);
    cout << "Sorted array (Heap Sort): ";
    hs.printArray(arr);
    return 0;
}
