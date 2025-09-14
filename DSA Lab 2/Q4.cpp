#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
*/

class Node{
public:
	int data;
	Node* next;
	
	Node(int data){
		this->data = data;
		next = nullptr;
	}
};

class LinkedList{
private:
	Node* head;
	Node* tail;
	
public:
	LinkedList(){
		head = tail = nullptr;
	}
	
	void print(){
		if(head == nullptr){
			cout << "List is empty ";
			return;
		}
		
		cout << "\n\n";
		Node* Temp = head;
		while(Temp != nullptr){
			cout << Temp->data << " -> ";
			Temp = Temp->next;
		}
		
		cout << "nullptr\n\n";
	}
	
	void push_back(int val){
		Node* n = new Node(val);
		if(head == nullptr) {
			head = tail = n;
			return;
		}
		
		tail->next = n;
		tail = n;
	}
	
	Node* ReverseList(Node* n){
		Node* prev = nullptr;
		Node* current = n;
		Node* NextPtr = nullptr;
		
		while(current != nullptr){
			NextPtr = current->next;
			current->next = prev;
			
			prev = current;
			current = NextPtr;
		}
		
		return prev;
	}
	
	bool isPalindrome(){
		if(head == nullptr) return true;
		
		if(head->next == nullptr) return true;
		
		Node* slow = head;
		Node* fast = head;
		
		while(fast != nullptr && fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
		}
		
		Node* temp = slow->next;
		temp = this->ReverseList(temp);
		
		Node* l1 = head;
		
		while(temp != nullptr){
			if(l1->data != temp->data){
				return false;
			}
			
			l1 = l1->next;
			temp = temp->next;
		}
		
		return true;
	}
};

int main(){
	
	LinkedList ll;
	ll.push_back(1);
	ll.push_back(2);
	ll.push_back(3);
	ll.push_back(3);
	ll.push_back(2);
	ll.push_back(1);
	
	ll.print();

	ll.isPalindrome() ? cout << "The list is palindrome \n" : cout << "The list is not palindrome \n";
	
	
	
	
	LinkedList ll2;
	for(int i=1;i<=6;i++){
		ll2.push_back(i);
	}
	
	ll2.print();
	ll2.isPalindrome() ? cout << "The list is palindrome \n" : cout << "The list is not palindrome \n";
	return 0;
}