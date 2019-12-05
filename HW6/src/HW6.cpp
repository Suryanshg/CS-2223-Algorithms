//============================================================================
// Name        : HW6.cpp
// Author      : Alex Galvan && Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

bool isLegalPosition(vector<int> board, int n);
bool hasDuplicate(vector<int> board);
bool intersectDiagonally(vector<int> board);
void printBoard(vector<int> board);

int main() {
	vector<int> board = { 1, 6, 8, 3, 5, 0, 0, 0 }; // { 1, 6, 8, 3, 7, 0, 0, 0 }; // { 1, 6, 8, 3, 5, 0, 0, 0 }; //{ 1, 6, 8, 3, 7, 4, 2, 5 }; //{ 1, 6, 8, 3, 7, 0, 0, 0}
	int n = 8;
	printBoard(board);
	bool legPos = isLegalPosition(board, n);
	//1 is true, 0 is false
	cout << "Is legal position result is " << legPos << endl;
	return 0;
}

bool isLegalPosition(vector<int> board, int n) {
	bool result = true;
	int arraySize = board.size();
	bool duplicateCol = hasDuplicate(board);
	bool intersectDiag = intersectDiagonally(board);
	if (arraySize < n) {
		result = false;
	} else if (duplicateCol) {
		result = false;
	} else if (intersectDiag) {
		result = false;
	}
	return result;
}

bool hasDuplicate(vector<int> board) {
	bool result = false;
	int size = board.size();
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((board[i] == board[j]) && (board[i] != 0)) {
				result = true;
				break;
			}
		}
	}
	return result;
}

bool intersectDiagonally(vector<int> board) {
	bool intersect = false;
	int size = board.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (board[j] != 0) {
				if (abs(board[i] - board[j]) == abs(i - j)) { //is a diagonal value
					intersect = true;
					break;
				}
			}
		}
	}
	return intersect;
}

void printBoard(vector<int> board) {
	int boardSize = board.size(); //sizeof(board) / sizeof(board[0]);
	cout << "Board size is " << boardSize << endl;
	cout << "board looks like" << endl;
	for (int i = 0; i < boardSize; i++) {
		cout << board[i] << " ";
	}
	cout << endl;
}

