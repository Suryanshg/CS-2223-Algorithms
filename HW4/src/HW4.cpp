//============================================================================
// Name        : HW4.cpp
// Author      : Suryansh Goyal and Alex Galvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void printMatrix(int B[][8], int n);
void determinePath(int A[][8], int B[][8], int n);
int maxCol(int B[][8],int i, int j);

int main() {
	int A[8][8] = { { 89, 70, 73, 83, 90, 22, 44, 92 }, { 46, 23, 99, 77, 10,
			42, 1, 72 }, { 85, 52, 27, 5, 94, 91, 82, 62 }, { 22, 93, 68, 11,
					56, 63, 49, 35 }, { 13, 78, 48, 19, 78, 11, 90, 94 }, { 31, 5, 63,
							10, 32, 40, 14, 13 }, { 73, 38, 24, 49, 18, 6, 40, 74 }, { 79, 71,
									18, 20, 34, 51, 93, 65 }, };

	int B[8][8] = { { }, { }, { }, { }, { }, { }, { }, { 79, 71, 18, 20, 34, 51,
			93, 65 }, };

	int n = sizeof(A) / sizeof(A[0]);

	determinePath(A, B, n);
	return 0;
}

/*
 *Intakes given square floor of room with 64 smaller squares(A[][]),
 *Intakes paths with optimal values Bilbo can have with path (B[][])
 *Intakes order or size of A[][]
 *Determines Bilbo's starting square
 *Determines Bilbo's path
 *Determines the total number of gems that Bilbo collects
 *Determines the vault number where the King secreted the Arkenstone
 */
void determinePath(int A[][8], int B[][8], int n) {
	int temp;
	for (int i = n - 1; i > 0; i--) { //Starts at Row 1 and goes up to Row 7 (repeats 7 times)
		for (int j = i - 1; j > i - 2; j--) { //Starts at Row 1 + i and goes up just one Row (repeats 1 time)
			for (int k = 0; k < n; k++) { //Starts at Vault 1 and goes to Vault 8
				B[j][k] = A[j][k] + B[i][k];//stores the corresponding Vault path by adding previous Vault's Row
			}
			for (int k = 0; k < n - 1; k++) {//Checks values produced from bottom right value and see if it's bigger than previously stored value
				temp = A[j][k] + B[i][k + 1];
				if (temp > B[j][k]) {
					B[j][k] = temp;
				}
			}
			for (int k = 1; k < n; k++) {//Checks values produced from bottom left value and see if it's bigger than previously stored value
				temp = A[j][k] + B[i][k - 1];
				if (temp > B[j][k]) {
					B[j][k] = temp;
				}
			}
		}
	}
	int maxVal=0;
	int maxValj=0; //maxVal's vault number
	for (int j = 0; j < n; j++) {
		if (maxVal < B[0][j]) {
			maxVal = B[0][j];
			maxValj=j;
		}
	}
	// needs to find adjacent
	//incorrect from here, needs to be fixed
	printMatrix(B, n);
	cout<<"The number of gems collected on the way is: "<<maxVal<<endl;
	//int max=maxVal;
	//int next;
	int currCol=maxValj;
	//int currRow=0;
	int path[8];
	path[0]=maxValj+1;
	for (int i = 0; i < n; i++) {
//		if(i<n-1 && currCol>0 && currCol<7){
		currCol = maxCol(B, i, currCol);
		path[i + 1] = currCol + 1;
//		}
	}
	cout<<"Path is:\n";
	for(int i=0; i<n;i++){
		cout<<path[i]<<endl;
	}
}

int maxCol(int B[][8],int i, int j){
	if(j == 7){//right side
		if(B[i+1][j]>B[i+1][j-1]){ //right one is the greater
			return j;
		}
		if(B[i+1][j]<B[i+1][j-1]){ //left one is the greater
			return j-1;
		}
	}
	if(j == 0){//left side
		if(B[i+1][j]>B[i+1][j+1]){ //left one is the greater
			return j;
		}

		else if(B[i+1][j]>B[i+1][j+1]){ //right one is the greater
			return j+1;
		}
	}
	else if((B[i+1][j-1]>B[i+1][j]) &&(B[i+1][j-1]>B[i+1][j+1])){ //left one is the greater
		return j-1;
	}
	else if((B[i+1][j]>B[i+1][j-1]) &&(B[i+1][j]>B[i+1][j+1])){ //mid one is the greater
		return j;
	}
	else if((B[i+1][j+1]>B[i+1][j-1]) &&(B[i+1][j+1]>B[i+1][j])){ //right one is the greater
		return j+1;
	}
	return -1;
}

/*
 *
 */
void printMatrix(int A[][8], int n) {
	string space;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			space = ((A[i][j] > 99) ? (" ") : ("  "));
			cout << A[i][j] << space;
		}
		cout << "\n";
	}
}
