#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> workers;

    for (int i = 0; i < n; i++) {
        double ratio = (double)wage[i] / quality[i];
        workers.push_back({ratio, quality[i]});
    }

    sort(workers.begin(), workers.end());

    priority_queue<int> pq; 
    int sumQuality = 0;
    double result = 1e9;

    for (int i = 0; i < n; i++) {
        int q = workers[i].second;
        pq.push(q);
        sumQuality = sumQuality + q;

        if (pq.size() > k) {
            sumQuality = sumQuality - pq.top();
            pq.pop();
        }

        if (pq.size() == k) {
            double cost = sumQuality * workers[i].first;
            if (cost < result) result = cost;
        }
    }
    return result;
}

int main() {
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;
    cout << mincostToHireWorkers(quality, wage, k) << endl; 

    quality = {3,1,10,10,1};
    wage = {4,8,2,2,7};
    k = 3;
    cout << mincostToHireWorkers(quality, wage, k) << endl; 
}
