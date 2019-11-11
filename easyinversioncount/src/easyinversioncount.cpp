//============================================================================
// Name        : easyinversioncount.cpp
// Author      : Suryansh Goyal && Alex Galvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

int main() {
	int inputSize;
	cout<<"Enter the size of the array you want to build:";
	cin>>inputSize;
	int arr[inputSize];
	int input;
	bool validInput=false;
	cout<<"\nLet's make the array. Please don't enter a negative value.\n";
	for(int i=0;i<inputSize;i++){
		while(!validInput){
			cout<<"Enter an integer:";
			cin>>input;

			if(input>=0){
				validInput=true;
			}
			else{
				cout<<"Invalid Input! Please try again.";
			}
			cout<<"\n";
		}
		arr[i]=input;
		validInput=false;

	}
	cout<<"Your array is:\n";
	for(int i=0;i<inputSize;i++){
		cout<<arr[i]<<" ";
	}
	int count = 0;


	for (int i = 0; i < inputSize; i++) {
		for (int j = i + 1; j < inputSize; j++) {
			if (arr[i] > arr[j]){
				count++;
			}
		}
	}
	cout << "Number of Inversions: "<<count<<endl;
}
