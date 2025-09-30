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
		(*this).data = data;
		next = nullptr;
	}
};


class LinkedList{
private:
	Node* head;
	Node* tail;
	
public:
	LinkedList(){
		head = nullptr;
		tail = nullptr;
	}
	
	void push_back(int val){
		Node* n = new Node(val);
		if(head == nullptr){
			head = n ;
			tail = n;
			return;
		}
		
		tail->next = n;
		tail = n;
	}
	
	void print(Node* head){
		if(head == nullptr){
			cout << "List is empty";
			return;
		}
		
		while(head != nullptr){
			cout << head->data << " -> ";
			head = head->next;
		}
		
		cout << "nullptr\n\n";
	}
	
	Node* mergeLists(Node* l1head , Node* l2head){
		if(l1head == nullptr) return l2head;
		
		if(l2head == nullptr) return l1head;
		
		Node* temp = new Node(0);
		Node* prev = temp;
		
		while(l2head != nullptr && l1head != nullptr){
			if(l1head->data <= l2head->data){
				prev->next = l1head;
				l1head = l1head->next;
			}else {
				prev->next = l2head;
				l2head = l2head->next;
			}
			
			prev = prev->next;
		}
		
		if(l1head != nullptr) prev->next = l1head;
		
		if(l2head != nullptr) prev->next = l2head;
		
		Node* result = temp->next;
		delete temp;
		return result;
	}
	
	Node* getHead() {
	return this->head;}
	
};

int main(){
	
	LinkedList l1;
	for(int i = 1 ; i <= 10 ;i++){
		if(i%2 == 0) l1.push_back(i);
	}
	
	Node* l1head = l1.getHead();
	
	l1.print(l1head);
	
	LinkedList l2;
	
	for(int i = 1 ; i <= 10 ; i++){
		if(i%2!=0) l2.push_back(i);
	}
	
	
	Node* l2head = l2.getHead();
	l2.print(l2head);
	
	
	
	
	LinkedList MergedList;
	Node* result = MergedList.mergeLists(l1head,l2head);
	
	MergedList.print(result);
	
	
	
	return 0;
}