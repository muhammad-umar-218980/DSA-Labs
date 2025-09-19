#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

class Node{
public:
    string url;
    Node* next;
    Node* prev;

    Node(string url){
        this->url = url;
        next = prev = nullptr;
    }
};

class BrowserHistory {
public:
    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }
    
    void visit(string url) {
    	
        if(currentPage->next != nullptr) {
            Node* temp = currentPage->next;
            while(temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            currentPage->next = nullptr;
        }
        
        Node* newPage = new Node(url);
        currentPage->next = newPage;
        newPage->prev = currentPage;
        currentPage = newPage;
    }
    
    string back(int steps) {
        while(currentPage->prev != nullptr && steps>0){
            currentPage = currentPage->prev;
            steps-=1;
        }

        return currentPage->url;
    }
    
    string forward(int steps) {
        while(currentPage->next != nullptr && steps>0){
            currentPage = currentPage->next;
            steps--;
        }

        return currentPage->url;
    }
    
    
    void printHistory() {
        Node* temp = currentPage;
        while(temp->prev != nullptr) {
            temp = temp->prev;
        }

        cout << "Browsing History: ";
        while(temp != nullptr) {
            if(temp == currentPage) {
                cout << " [" << temp->url << "] "; 
            } else {
                cout << temp->url << "  ";
            }
            temp = temp->next;
        }
        cout << "\n\n";
    }
};

int main(){
	
	BrowserHistory BH("mainpage.com");
	
	BH.visit("1.com");
	BH.visit("2.com");
	BH.visit("3.com");
	BH.visit("4.com");
	BH.visit("5.com");
	BH.visit("6.com");
	BH.visit("7.com");
	
	BH.printHistory();
	

	cout<< BH.back(2)<<endl;
	BH.printHistory();
	
	cout << BH.forward(2)<<endl;
	BH.printHistory();
	
	
	cout<< BH.back(2)<<endl;
	BH.printHistory();
	
	cout << BH.forward(2)<<endl;
	BH.printHistory();
	
	BH.visit("new.com");
	BH.printHistory();
	
	
	cout << BH.forward(1)<<endl;
	BH.printHistory();
	
	
	cout <<BH.back(2)<<endl;
	BH.printHistory();
	
	cout <<BH.back(6) <<endl;
	BH.printHistory();
	
	
	cout <<BH.forward(4)<<endl;
	BH.printHistory();
	
	
	return 0;
}