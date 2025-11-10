#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (int i = 0; i < s.size(); i++) {
        freq[s[i]]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        pq.push({(*it).second, (*it).first});
    }

    string ans = "";
    while (!pq.empty()) {
        int count = pq.top().first;
        char ch = pq.top().second;
        pq.pop();
        for (int i = 0; i < count; i++) {
            ans += ch;
        }
    }
    return ans;
}

int main() {
    string s = "tree";
    string result = frequencySort(s);
    cout << result << endl;

    s = "cccaaa";
    result = frequencySort(s);
    cout << result << endl;
}
