#include <iostream>
#include <stack>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/


bool isPalindrome(string s){
	stack<char> st;
	for(int i = 0 ; i < s.length() ; i++){
		st.push(tolower(s[i]));
	}
	
	for(int i = 0 ; i < s.length() ; i++){
		if(tolower(s[i]) != st.top()) return false;
		
		st.pop();
	}
	return true;
}

bool isPalindrome2(string s){
	int n = s.length();
	stack<char> st;
	for(int i = 0 ; i < n/2 ;i++){
		st.push(tolower(s[i]));
	}
	
	int idx = (n%2==0) ? n/2 : n/2+1;
	
	for(int i = idx ; i < n ;i++){
		if(tolower(s[i]) != st.top()) return false;
		
		st.pop();
	}
	
	return true;
}

int main(){
	string s;
	cout << "Enter the string to check for Palindrome : ";
	getline(cin,s);
	
	isPalindrome(s) ? cout << endl << s << " is Palindrome\n" : cout << endl << s << " is not Palindrome\n" ;



	cout << "\n\nEnter the string to check for Palindrome : ";
	getline(cin,s);
	
	isPalindrome2(s) ? cout << endl << s << " is Palindrome\n" : cout << endl << s << " is not Palindrome\n" ;
	return 0;
}