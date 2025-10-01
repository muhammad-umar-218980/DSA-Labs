#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
*/

class Node {
	public:
		int data;
		Node* next;
		Node* prev;

		Node(int data) {
			this->data = data;
			next = prev = nullptr;
		}
};

class Double_Ended_Queue {
	private:
		Node* front;
		Node* rear;

	public:
		Double_Ended_Queue() {
			front = rear = nullptr;
		}

		bool isEmpty() {
			return front == nullptr;
		}

		void enqueueFront(int val) {
			Node* n = new Node(val);
			if(isEmpty()) {
				front = rear = n;
				return;
			}

			n->next = front;
			front->prev = n;
			front = n;
		}

		void enqueueRear(int val) {
			Node* n = new Node(val);
			if(isEmpty()) {
				front = rear = n;
				return;
			}

			rear->next = n;
			n->prev = rear;
			rear = n;

		}

		int dequeueFront() {
			if(isEmpty()) {
				cout << "\nDouble Ended Queue is Empty\n";
				return -1;
			}

			int value = front->data;

			if(front == rear) {
				delete front;
				front = rear = nullptr;
				return value;
			}

			Node* temp = front;
			front = front->next;
			front->prev = nullptr;
			temp->next = nullptr;
			delete temp;
			return value;
		}

		int dequeueRear() {
			if(isEmpty()) {
				cout << "\nDouble Ended Queue is Empty\n";
				return -1;
			}

			int value = rear->data;

			if(front == rear) {
				delete rear;
				front = rear = nullptr;
				return value;
			}

			Node* temp = rear;
			rear = rear->prev;
			rear->next = nullptr;
			temp->prev = nullptr;
			delete temp;

			return value;

		}

		int peekFront() {
			if (isEmpty()) {
				cout << "Deque is empty!\n";
				return -1;
			}
			return front->data;
		}

		int peekRear() {
			if (isEmpty()) {
				cout << "Deque is empty!\n";
				return -1;
			}
			return rear->data;
		}

		void print() {
			if(isEmpty()) {
				cout << "Double Ended Queue is Empty\n";
				return;
			}

			Node* current = front;
			while(current != nullptr) {
				cout << current->data << " <=> ";
				current = current->next;
			}

			cout << "nullptr\n\n";
		}
};

int main() {

	Double_Ended_Queue dq;

	cout << "\nAfter enqueuing 3-10 from Rear : \n";
	for(int i=3; i<=10; i++) dq.enqueueRear(i);
	dq.print();
	cout << "Front Value = " << dq.peekFront()<<"\n";
	cout << "Rear Value = " << dq.peekRear()<<"\n";



	cout << "\nAfter enqueuing 2 from Front : \n";
	dq.enqueueFront(2);
	dq.print();
	cout << "Front Value = " << dq.peekFront()<<"\n";
	cout << "Rear Value = " << dq.peekRear()<<"\n";
	
	

	cout << "\nAfter enqueuing 1 from Front : \n";
	dq.enqueueFront(1);
	dq.print();
	cout << "Front Value = " << dq.peekFront()<<"\n";
	cout << "Rear Value = " << dq.peekRear()<<"\n";
	
	


	cout << "\nAfter dequeuing 1 from Front : \n";
	int value = dq.dequeueFront();
	dq.print();
	cout << "Dequeued value = " << value <<"\n";
	cout << "Front Value = " << dq.peekFront()<<"\n";
	cout << "Rear Value = " << dq.peekRear()<<"\n";
	
	


	cout << "\nAfter dequeuing 2 from Front : \n";
	value = dq.dequeueFront();
	dq.print();
	cout << "Dequeued value = " << value <<"\n";
	cout << "Front Value = " << dq.peekFront()<<"\n";
	cout << "Rear Value = " << dq.peekRear()<<"\n";



	cout << "\nAfter dequeuing 10 from Rear : \n";
	value = dq.dequeueRear();
	dq.print();
	cout << "Dequeued value = " << value <<"\n";
	cout << "Front Value = " << dq.peekFront()<<"\n";
	cout << "Rear Value = " << dq.peekRear()<<"\n";
	
	



	cout << "\nAfter dequeuing 9 from Rear : \n";
	value = dq.dequeueRear();
	dq.print();
	cout << "Dequeued value = " << value <<"\n";
	cout << "Front Value = " << dq.peekFront()<<"\n";
	cout << "Rear Value = " << dq.peekRear()<<"\n";
	
	
	

	return 0;
}