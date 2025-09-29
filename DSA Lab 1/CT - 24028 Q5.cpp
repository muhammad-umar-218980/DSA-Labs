#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

bool Search(int** arr, int rows, int cols, int target) {
    int start = 0;
    int end = rows * cols - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int row_index = mid / cols;
        int col_index = mid % cols;
        int mid_val = arr[row_index][col_index];

        if (mid_val == target) {
            return true;
        } else if (mid_val < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    int target;
    cout << "\nEnter target to search: ";
    cin >> target;

    if (Search(arr, rows, cols, target) == true) {
        cout << "\nResult: Found" << endl;
    } else {
        cout << "\nResult: Not Found" << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
