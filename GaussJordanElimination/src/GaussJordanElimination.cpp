//============================================================================
// Name        : GaussJordanElimination.cpp
// Author      : Suryansh Goyal and Alex Galvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

void gaussJordanElimination(double A[][9], double b[], int n);
void printMatrix(double A[][9], int n);

int main() {
	double A[8][9] = {{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },
			{ 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0 },
			{ 1.0, 1.0, 3.0, 1.0, 1.0, 3.0, 1.0, 1.0 },
			{ 1.0, 1.0, 1.0, 4.0, 4.0, 1.0, 1.0, 1.0 },
			{11.0, 1.0, 1.0, 1.0,	1.0, 1.0, 1.0, 1.0 },
			{ 1.0, 1.0, 1.0, 1.0,-1.0,-1.0,-1.0,-1.0 },
			{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },
			{ 1.0,-1.0, 1.0,-1.0, 1.0,-1.0, 1.0,-1.0 },};

	double b[8] = { 0.0, 0.0, 0.0, 0.0, 20.0, 34.0, -51.0, -6.0 };
	int n = sizeof(A) / sizeof(A[0]);
	//cout<<n;

	//betterForwardElimination(A, b, n);
	gaussJordanElimination(A, b, n);
	//printMatrix(A, n);

	cout << "Result of Guass-Jordan Elimination Algorithm on the provided matrix is" << endl;
	printMatrix(A, n);
	cout << endl;
}


/*
 *Performs Gaussian Elimination on the provided matrix. Then performs Gauss-Jordan
 *elimination
 */
void gaussJordanElimination(double A[][9], double b[], int n) {
	int pivotRow;
	double pivotVal;
	double temp;
	for (int i = 0; i < n; i++) { //Augments the matrix b to A
		A[i][n] = b[i];
	}

	for (int i = 0; i < n; i++) {
		pivotRow = i;
		for (int j = i + 1; j < n; j++) {
			if (abs(A[j][i]) > abs(A[pivotRow][i])) {
				pivotRow = j;
			}
		}
		for (int k = i; k < n + 1; k++) {
			swap(A[i][k], A[pivotRow][k]);
		}
		for (int j = i + 1; j < n; j++) {
			temp = A[j][i] / A[i][i];
			for (int k = i; k < n + 1; k++) {
				A[j][k] = round((A[j][k] - A[i][k] * temp) * 10000) / 10000;
				//				A[j][k] = A[j][k] - A[i][k] * temp;
			}
		}
		pivotVal = A[i][i];// scaling all rows by the pivot value
		for (int k = i; k < n + 1; k++) {
			A[i][k] = A[i][k]/pivotVal;
		}
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			temp=A[j][i]/A[i][i];
			for(int k=i;k<n+1;k++){
				//A[j][k]=round((A[j][k] - A[i][k]*temp) *1000)/1000;
				A[j][k]=A[j][k] - A[i][k]*temp;
			}
		}

	}

}

/*
 *
 */
void printMatrix(double A[][9], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}


