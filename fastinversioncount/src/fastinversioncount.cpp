//============================================================================
// Name        : fastinversioncount.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

int count = 0;
void merge(int arr[], int leftIndex, int midIndex, int rightIndex);
void mergeSort(int arr[], int leftIndex, int rightIndex);


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

	mergeSort(arr,0,inputSize-1);
	cout<<"\nNumber of Inversions: "<<count<<endl;

}



/*
 * performs the mergesort on the given array/sub array
 */
void mergeSort(int arr[], int leftIndex, int rightIndex){
	if(leftIndex < rightIndex){
		int midIndex = (rightIndex+leftIndex)/2; //for dividing the array into two sub arrays
		mergeSort(arr, leftIndex, midIndex); //sort left array
		mergeSort(arr, midIndex+1, rightIndex); //sort right array
		merge(arr, leftIndex, midIndex, rightIndex); //merge the sorted arrays
	}
}

/*
 *merges two already sorted sub arrays and make sure the result is also sorted.
 *Also counts the number of inversions.
 */
void merge(int arr[], int leftIndex, int midIndex, int rightIndex){
	int lenL = midIndex - leftIndex + 1; //length of left sub array
	int lenR =  rightIndex - midIndex; // length of right sub array

	int arrL[lenL]; // left sub array
	for(int i=0;i<lenL;i++){ // set up the left sub array
		arrL[i] = arr[leftIndex + i];

	}

	int arrR[lenR]; // right sub array
	for(int i=0;i<lenR;i++){ //set up the right sub array
		arrR[i] = arr[midIndex + 1+ i];
	}
	int indexL = 0; // index of left sub array
	int indexR = 0; // index of right sub array
	int index = leftIndex; // index of merged sub array
	while ((indexL < lenL) && (indexR < lenR)){
		if (arrL[indexL] <= arrR[indexR]){
			arr[index] = arrL[indexL];
			indexL++;
		}
		else{ // count inversions here!
			arr[index] = arrR[indexR];
			count+=lenL-indexL; // counting inversions
			indexR++;
		}
		index++;
	}

	//fill up the array with left overs!
	while (indexR < lenR){
		arr[index] = arrR[indexR];
		indexR++;
		index++;
	}
	while (indexL < lenL){
		arr[index] = arrL[indexL];
		indexL++;
		index++;
	}
}
