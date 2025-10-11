#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class Call {
public:
    int callID;
    string arrivalTime;
    string customerName;

    Call(int id, string time, string name) {
        callID = id;
        arrivalTime = time;
        customerName = name;
    }
};

class CallCenter {
private:
    queue<Call> callQueue;
    int numCSR;
    vector<bool> csrAvailable;

public:
    CallCenter(int n) {
        numCSR = n;
        csrAvailable = vector<bool>(n, true);
    }

    void addCall(Call c) {
        callQueue.push(c);
        cout << "\nNew call added: " << c.customerName << " (Call ID: " << c.callID << ")\n";
    }

    void processCalls() {
        while (!callQueue.empty()) {
            bool anyAssigned = false;
            for (int i = 0; i < numCSR && !callQueue.empty(); i++) {
                if (csrAvailable[i]) {
                    Call current = callQueue.front();
                    callQueue.pop();
                    csrAvailable[i] = false;
                    cout << "\nCSR " << i + 1 << " is handling call " << current.callID << " from " << current.customerName << "\n";
                    cout << "CSR " << i + 1 << " has handled call from " << current.customerName << " and is now free.\n";
                    csrAvailable[i] = true;
                    anyAssigned = true;
                } else {
                    cout << "CSR " << i + 1 << " is busy\n";
                }
            }
            if (!anyAssigned) {
                cout << "\nAll CSRs are busy, waiting for next available...\n";
            }
        }
        cout << "\nAll calls have been handled successfully!\n";
    }
};

int main() {
    CallCenter center(3);

    center.addCall(Call(1, "10:00", "Umar"));
    center.addCall(Call(2, "10:02", "Ali"));
    center.addCall(Call(3, "10:05", "Sara"));
    center.addCall(Call(4, "10:08", "Zain"));
    center.addCall(Call(5, "10:10", "Areeba"));

    center.processCalls();
    return 0;
}
