#include <iostream>
using namespace std;

void bubbleSort(int* arr , int n){
	
	for(int i = 0 ; i < n-1 ; i++){
		bool swapped = false;
		
		for(int j = 0 ; j < n-1-i ; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		
		if(not swapped){
			cout << "\nArray is already sorted \n";
			break;
		}
	}
}

void printArray(int* arr , int n){
	for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
}

int main(){
	
	int size;
	cout << "Enter the size of Array : ";
	cin >> size;
	
	int* arr = new int[size];
	
	for(int i = 0 ; i < size ;i++){
		cout << "\nEnter element " << i+1 << " : ";
		cin >> arr[i];
	}
	
	bubbleSort(arr,size);
	cout << "\nSorted Array : ";
	printArray(arr,size);
	
	delete[] arr;
	
	return 0;
}