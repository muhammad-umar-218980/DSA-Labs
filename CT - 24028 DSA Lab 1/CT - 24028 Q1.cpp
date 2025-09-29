#include <iostream>
using namespace std;

/*

	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028

*/

int main(){
	
	int rows , cols;
	
	cout << "Enter the number of rows : " ;
	cin >> rows;
	
	cout << "Enter the number of columns : " ;
	cin >> cols;
	
	int** arr = new int*[rows];
	int* newArr = new int[rows*cols];
	
	for(int i = 0 ; i < rows ; i++){
		arr[i] = new int[cols];
	}
	
	cout << "\n";
	
	for(int i = 0 ; i < rows ; i++){
		for(int j = 0 ; j < cols ; j++){
			cout << "Enter element [" << i << "][" << j << "] :";
			cin >> arr[i][j]; 
		}
	}
	
	
	int idx = 0;
	for(int j = 0 ; j < cols ; j++){
		for(int i = 0 ; i < rows ; i++){
			newArr[idx] = arr[i][j];
			idx++;
		}
	}
	
	cout << "\n";
	
	for(int i = 0 ; i < rows*cols ; i++){
		cout << "newArr[" << i << "] : " << newArr[i] << "\n";
	}
	
	for(int i = 0 ; i < rows ;i++){
		delete[] arr[i];
	}
	
	delete[] arr;
	delete[] newArr;
	
	
	return 0;
}
