#include <iostream>
#include <algorithm>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

int maxToysCount(int* arr , int n , int k){
	int idx = 0 , count = 0;
	
	while(idx < n and k >= arr[idx]){
			k-=arr[idx];
			idx++;
			count++;
	}
	
	return count;
}

int main(){
	
	int k ;
	cout << "Enter the value of k : ";
	cin >> k;
	
	int size;
	cout << "\nEnter the size of Array for Toys : ";
	cin >> size;
	
	int* arr = new int[size];
	
	for(int i = 0 ; i < size ;i++){
		cout << "\nEnter toy " << i+1 << " : ";
		cin >> arr[i];
	}
	
	sort(arr,arr+size);
	
	int count = maxToysCount(arr,size,k);
	
	cout << "\nThe maximum number of toys you can buy with " << k << " rupees are " << count ;
	
	delete[] arr;
	
	return 0;
}