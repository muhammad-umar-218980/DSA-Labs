#include <iostream>
#include <ctime>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

void sortColors(int* nums, int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = nums[i];
        j = i - 1;
        while(j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of objects (size of array): ";
    cin >> n;

    int* nums = new int[n]; 
    
    srand(time(0));

    cout << "\nEnter the colors of the objects using 0 (Red), 1 (White), 2 (Blue):\n";
    for(int i = 0; i < n; i++) {
        while(true) {
            cout << "Color at position " << i+1 << ": ";
            cin >> nums[i];
            if(nums[i] == 0 || nums[i] == 1 || nums[i] == 2) break;
            cout << "Invalid input! Please enter only 0, 1, or 2.\n";
        }
    }

    cout << "\nOriginal Array (colors as 0 = Red, 1 = White, 2 = Blue) : ";
    for(int i = 0; i < n; i++) cout << nums[i] << " ";

    sortColors(nums, n); 

    cout << "\n\nSorted Array (Red -> White -> Blue): ";
    for(int i = 0; i < n; i++) cout << nums[i] << " ";

    delete[] nums;
    return 0;
}
