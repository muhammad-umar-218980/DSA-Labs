#include <iostream>
#include <algorithm>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

void flip(int arr[], int k) {
    int start = 0;
    int end = k;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void pancakeSort(int arr[], int n, int flips[], int &flipCount) {
    flipCount = 0;
    for(int i = n; i > 1; i--) {
        int maxIndex = 0;
        for(int j = 1; j < i; j++) {
            if(arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if(maxIndex != i - 1) {
            if(maxIndex != 0) {
                flip(arr, maxIndex);
                flips[flipCount] = maxIndex + 1;
                flipCount++;
            }
            flip(arr, i - 1);
            flips[flipCount] = i;
            flipCount++;
        }
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++) {
    	cout << "\nEnter element " << i+1 << " : ";
        cin >> arr[i];
    }

    int* flips = new int[2 * size];
    int flipCount;

    pancakeSort(arr, size, flips, flipCount);

    cout << "\nFlip sequence: ";
    for(int i = 0; i < flipCount; i++) {
        cout << flips[i] << " ";
    }
    cout << endl;

    cout << "\nSorted array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] flips;
    return 0;
}
