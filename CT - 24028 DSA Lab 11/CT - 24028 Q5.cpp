#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iomanip>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

priority_queue<double> maxHeap; // smaller half
priority_queue<double, vector<double>, greater<double>> minHeap; 
unordered_map<double, int> delayed; 
int maxSize = 0, minSize = 0;
int k;

void removeDelayedMax() {
    while (!maxHeap.empty()) {
        double num = maxHeap.top();
        if (delayed.count(num) && delayed[num] > 0) {
            delayed[num]--;
            maxHeap.pop();
        } else break;
    }
}

void removeDelayedMin() {
    while (!minHeap.empty()) {
        double num = minHeap.top();
        if (delayed.count(num) && delayed[num] > 0) {
            delayed[num]--;
            minHeap.pop();
        } else break;
    }
}

void balance() {
    if (maxSize > minSize + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        maxSize--; minSize++;
        removeDelayedMax();
    } else if (maxSize < minSize) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
        maxSize++; minSize--;
        removeDelayedMin();
    }
}

void insert(double num) {
    if (maxHeap.empty() || num <= maxHeap.top()) {
        maxHeap.push(num);
        maxSize++;
    } else {
        minHeap.push(num);
        minSize++;
    }
    balance();
}

void erase(double num) {
    delayed[num]++;
    if (!maxHeap.empty() && num <= maxHeap.top()) maxSize--;
    else minSize--;
    balance();
}

double getMedian() {
    if (k % 2 == 1) return maxHeap.top();
    return (maxHeap.top() + minHeap.top()) / 2.0;
}

vector<double> medianSlidingWindow(vector<int>& nums, int windowSize) {
    k = windowSize;
    vector<double> result;
    for (int i = 0; i < nums.size(); i++) {
        insert(nums[i]);
        if (i >= k - 1) {
            result.push_back(getMedian());
            erase(nums[i - k + 1]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int windowSize = 3;

    vector<double> res = medianSlidingWindow(nums, windowSize);
    cout << fixed << setprecision(5);
    for (double d : res) cout << d << " ";
    cout << endl;

    return 0;
}
