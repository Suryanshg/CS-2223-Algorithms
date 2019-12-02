/*
//////////////////////////////////////////
little more clean
//////////////////////////////////////////
//============================================================================
// Name        : DijkstraAlgorithm.cpp
// Author      : Alex Galvan && Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<fstream>
#include<string.h>
#include <sstream>
using namespace std;

int main() {
	ifstream file;
	file.open("DijkstraExample.txt");
	int intMatrixSize;
	file >> intMatrixSize;
	cout << "Matrix size is " << intMatrixSize << endl;
	int x;
	int fileMatrix[intMatrixSize][intMatrixSize];
	for (int i = 0; i < intMatrixSize; i++) {
		for (int j = 0; j < intMatrixSize; j++) {
			file >> x;
			fileMatrix[i][j] = x;
		}
	}
	for (int i = 0; i < intMatrixSize; i++) {
		for (int j = 0; j < intMatrixSize; j++) {
			string space = ((fileMatrix[i][j] < 10) ? ("   ") :
							(fileMatrix[i][j] < 100) ? ("  ") : (" "));
			cout << fileMatrix[i][j] << space;
		}
		cout << endl;
	}

	return 0;
}
 */


//////////////////////////////////////////
//lot more cleaner
//////////////////////////////////////////
//============================================================================
// Name        : DijkstraAlgorithm.cpp
// Author      : Alex Galvan && Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<fstream>
#include<string.h>
#include <sstream>
using namespace std;

int** determineMatrix();
void printMatrix(int **matrix);

int main() {
	int **matrix = determineMatrix();
	printMatrix(matrix);
	return 0;
}

int** determineMatrix() {
	ifstream file;
	file.open("DijkstraExample.txt");
	int intMatrixSize;
	file >> intMatrixSize;
	cout << "Matrix size is " << intMatrixSize << endl;
	int x;
	int **fileMatrix = 0;
	fileMatrix = new int*[intMatrixSize];
	for (int i = 0; i < intMatrixSize; i++) {
		fileMatrix[i] = new int[intMatrixSize];
		for (int j = 0; j < intMatrixSize; j++) {
			file >> x;
			fileMatrix[i][j] = x;
		}
	}
	file.close();
	return fileMatrix;
}

void printMatrix(int **matrix) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			string space = ((matrix[i][j] < 10) ? ("   ") :
							(matrix[i][j] < 100) ? ("  ") : (" "));
			cout << matrix[i][j] << space;
		}
		cout << endl;
	}
}
///////////
