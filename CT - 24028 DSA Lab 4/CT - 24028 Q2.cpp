#include <iostream>
#include <stack>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

string helperFunc(string s) {
    int n = s.size();
    
    stack<char> st;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '#') {
            if(!st.empty()) st.pop();
        } else st.push(s[i]);
    }

    string output = "";
    while(!st.empty()) {
        output = st.top() + output; 
        st.pop();
    }

    return output;
}

bool backspaceCompare(string s, string t) {
    return helperFunc(s) == helperFunc(t);
}

int main() {
    string s1;
    cout << "Enter string 1 : ";
    getline(cin, s1);

    string s2;
    cout << "\nEnter string 2 : ";
    getline(cin, s2);

    cout << (backspaceCompare(s1, s2) ? "\nBoth strings are equal after processing backspaces.\n" : "\nBoth strings are NOT equal after processing backspaces.\n");

    return 0;
}
