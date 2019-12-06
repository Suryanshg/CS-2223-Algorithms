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
vector<int> nextLegalPosition(vector<int> board, int n);
bool hasDuplicate(vector<int> board);
bool intersectDiagonally(vector<int> board);
bool perfectSituation(vector<int> board, int n);
bool fullySolved(vector<int> board, int n);
vector<int> emptyBoard(vector<int> board, int n);
vector<int> nextFullSolvedBoard(vector<int> board, int n);
vector<int> fillBoard(vector<int> board, int n);
vector<int> correctIllegalBoard(vector<int> board, int n);
void printBoard(vector<int> board);

int main() {
	vector<int> board = { 1, 6, 8, 3, 5, 0, 0, 0 }; // { 1, 6, 8, 3, 7, 0, 0, 0 }; // { 1, 6, 8, 3, 5, 0, 0, 0 }; //{ 1, 6, 8, 3, 7, 4, 2, 5 }; //{ 1, 6, 8, 3, 7, 0, 0, 0}
	int n = 8;
	printBoard(board);
	bool legPos = isLegalPosition(board, n);
	board = nextLegalPosition(board, n);
	//1 is true, 0 is false
	cout << "Is legal position result is " << legPos << endl;
	return 0;
}

/*
 *
 */
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

/*
 *
 */
vector<int> nextLegalPosition(vector<int> board, int n) {
	bool fulSolved = fullySolved(board, n);
	bool perfSit = perfectSituation(board, n);
	bool isLegPos = isLegalPosition(board, n);
	if (fulSolved) {
		board = emptyBoard(board, n);
	} else if (perfSit) {
		board = nextFullSolvedBoard(board, n);
	} else if (isLegPos) {
		board = fillBoard(board, n);
	} else {
		board = correctIllegalBoard(board, n);
	}
	return board;
}

/*
 *
 */
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

/*
 *
 */
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

/*
 *
 */
bool perfectSituation(vector<int> board, int n) {
	bool result = false;
	return result;
}

/*
 *
 */
bool fullySolved(vector<int> board, int n) {
	bool result = false;
	return result;
}

/*
 *
 */
vector<int> emptyBoard(vector<int> board, int n) {
	vector<int> emptyBoard;
	int boardSize = board.size();
	for (int i = 0; i < boardSize; i++) {
		emptyBoard.insert(emptyBoard.begin(), 0);
	}
	return board;
}

/*
 *
 */
vector<int> nextFullSolvedBoard(vector<int> board, int n) {
	return board;
}

/*
 *
 */
vector<int> fillBoard(vector<int> board, int n) {
	return board;
}

/*
 *
 */
vector<int> correctIllegalBoard(vector<int> board, int n) {
	return board;
}

/*
 *
 */
void printBoard(vector<int> board) {
	int boardSize = board.size();
	cout << "Board size is " << boardSize << endl;
	cout << "board looks like" << endl;
	for (int i = 0; i < boardSize; i++) {
		cout << board[i] << " ";
	}
	cout << endl;
}
