#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        pq.push({(*it).second, (*it).first});
    }

    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
