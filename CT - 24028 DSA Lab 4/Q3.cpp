#include <iostream>
#include <vector>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

void getPermutations(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    int n = nums.size();
    if(idx == n) {
        ans.push_back(nums);
        return;
    }

    for(int i = idx; i < n; i++) {
        swap(nums[i], nums[idx]);
        getPermutations(nums, idx + 1, ans);
        swap(nums[i], nums[idx]); 
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " distinct integers : ";
    for(int i = 0; i < n; i++) {
    	cout << "\nEnter number " << i+1 << " : ";
        cin >> nums[i];
    }

    vector<vector<int>> ans;
    getPermutations(nums, 0, ans);

    cout << "\nAll permutations:\n";
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout <<  ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
