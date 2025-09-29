#include <iostream>
#include <algorithm>
using namespace std;

/*

	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028

*/

int binarySearch(int arr[],int size , int target);

int main(){
	
	int size;
	
	cout << "Enter the size of Array : " ;
	cin >> size;
	
	int* arr = new int[size];
	
	cout << "\n";
	
	for(int i = 0 ; i < size ; i++){
		cout << "Enter element " << i+1 << " : ";
		cin >> arr[i]; 
	}
	
	sort(arr,arr+size);
	
	cout << "\nThe Array in sorted order is : \n" ;
	
	for(int i = 0 ; i < size ; i++){
		cout << "arr[" << i << "] : " << arr[i] << "\n";
	}

	
	cout << "\n";
	
	int target;
	cout << "Enter the target to search in the Array : " ;
	cin >> target;
	
	int index = binarySearch(arr,size,target);
	
	if(index == -1){
		cout << "\nTarget not found in the Array. ";
	}else{
		cout << "\n" << target << " is found at index " << index;
	}
	
	
	delete[] arr;
	
	
	return 0;
}

int binarySearch(int arr[],int size , int target){
	int start = 0 , end = size-1;
	
	while(start<=end){
		int mid = start + (end-start)/2;
		
		if(arr[mid] == target) return mid;
		
		if(arr[mid] < target) start = mid+1;
		else end = mid - 1;
	}
	
	return -1;
}