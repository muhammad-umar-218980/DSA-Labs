#include <iostream>
#include <queue>
using namespace std;

class DataStream {
    int value;
    int k;
    int count;
    queue<int> q;

public:
    DataStream(int val, int num) {
        value = val;
        k = num;
        count = 0;
    }

    bool consec(int num) {
        q.push(num);
        if (num == value) count++;

        if (q.size() > k) {
            int front = q.front();
            q.pop();
            if (front == value) count--;
        }

        if (q.size() < k) return false;
        return count == k;
    }
};

int main() {
    DataStream dataStream(4, 3); 

    dataStream.consec(4) ? cout << "true\n" : cout << "false\n";
    dataStream.consec(4) ? cout << "true\n" : cout << "false\n";
    dataStream.consec(4) ? cout << "true\n" : cout << "false\n";
    dataStream.consec(3) ? cout << "true\n" : cout << "false\n";

    return 0;
}
