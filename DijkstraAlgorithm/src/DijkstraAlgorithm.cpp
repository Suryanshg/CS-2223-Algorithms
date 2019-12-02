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
	file>>intMatrixSize;
	cout << "Matrix size is " << intMatrixSize << endl;
	int fileMatrix[intMatrixSize][intMatrixSize];
	for (int i = 0; i < intMatrixSize; i++) {
		for (int j = 0; j < intMatrixSize; j++) {
			int x;
			file >> x;
			fileMatrix[i][j] = x;
		}
	}
	for (int i = 0; i < intMatrixSize; i++) {
		for (int j = 0; j < intMatrixSize; j++) {
			string space = ((fileMatrix[i][j] < 10) ? ("   ") : ("  "));
			if(fileMatrix[i][j] > 99){
				space = " ";
			}
			cout << fileMatrix[i][j]<< space;
		}
		cout << endl;
	}

	return 0;
}
/*
 * //		int tempRow[intMatrixSize];
 //		for (int i = 0; i < intMatrixSize; i++) {
 //			getline(file, stringMatrixSize);
 //			istringstream(stringMatrixSize) >> tempRow; //each row in matrix being written here
 //			fileMatrix[i] = tempRow;
 //		}
 */
