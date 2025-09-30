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

class Stack{
private:
	Node* head;

public:
	Stack(){
		head = nullptr;
	}	
	
	void push(int val){
		Node* newStackNode = new Node(val);
		
		if(head == nullptr){
			head = newStackNode;
			return;
		}
		
		newStackNode->next = head;
		head = newStackNode;
	}
	
	int pop(){
		if(head == nullptr){
			cout << "Stack is Empty\n";
			return -1;
		}
		
		Node* deletedStackNode = head;
		int topValue = head->data;
		head = head->next;
		delete(deletedStackNode);
		return topValue;
	}
	
	void print(){
		if(head == nullptr){
			cout << "Stack is Empty\n";
			return;
		}
		cout << "\n\n";
		Node* temp = head;
		while(temp){
			cout << temp->data << " " ;
			temp = (*temp).next;
		}
	}
	
	int peek() {
		if(head == nullptr) {
			cout << "\nStack is Empty\n";
			return -1;
		}
	return head->data;}
};

int main(){
	
	Stack s;
	s.push(1);
	s.push(2);
	s.push(4);
	
	s.print();
	s.pop();
	s.pop();
	
	s.print();
	
	int stackPeek = s.peek();
	cout << "\n\nPeek of Stack = " << stackPeek;
	
	
	s.pop();
	
	for(int i=10;i>0;i--){
	 s.push(i);}
	
	
	s.print();
	
	stackPeek = s.peek();
	cout << "\n\nPeek of Stack = " << stackPeek;
	
	s.pop();
	s.pop();
	
	s.print();
	stackPeek = s.peek();
	cout << "\n\nPeek of Stack = " << stackPeek;
	
	
	return 0;
}