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

void betterForwardElimination(double A[][9],double b[],int n);
void printMatrix(double A[][9],int n);

int main() {
	double A[8][9]={
			{1,1,1,1,1,1,1,1},
			{1,2,1,1,1,1,2,1},
			{1,1,3,1,1,3,1,1},
			{1,1,1,4,4,1,1,1},
			{11,1,1,1,1,1,1,1},
			{1,1,1,1,-1,-1,-1,-1},
			{1,2,3,4,5,6,7,8},
			{1,-1,1,-1,1,-1,1,-1},
	};

	double b[8]={0,0,0,0,20,34,-51,-6};
	int n=sizeof(A)/sizeof(A[0]);
	//cout<<n;

	betterForwardElimination(A,b,n);


	double pivotVal;
	for(int i=0;i<n;i++){ //scaling the rows by pivot values
		pivotVal=A[i][i];
		for(int j=i;j<n+1;j++){
			A[i][j]=A[i][j]/pivotVal;
		}
	}

	printMatrix(A,n);
}

/*
 * n is the order of the matrix A
 */
void betterForwardElimination(double A[][9],double b[],int n){
	int pivotRow;
	double temp;
	for(int i=0;i<n;i++){ //Augments the matrix b to A
		A[i][n]=b[i];
	}

	//printMatrix(A,n);
	for(int i=0 ; i<n-1 ; i++){
		pivotRow=i;
		for(int j=i+1 ; j<n ; j++){
			if(abs(A[j][i])>abs(A[pivotRow][i])){
				pivotRow=j;
			}
		}
		for(int k=i;k<n+1;k++){
			swap(A[i][k],A[pivotRow][k]); // write a helper if doesn't work
		}
		for(int j=i+1; j<n ; j++){
			temp=A[j][i]/A[i][i];
			for(int k=i ;k<n+1;k++){
				A[j][k]=round((A[j][k]-A[i][k]*temp)*100)/100;
			}
		}
	}
	//printMatrix(A,n);


}

/*
 *
 */
void printMatrix(double A[][9],int n){
	for(int i=0; i<n;i++){
		for(int j=0; j<n+1;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
}
