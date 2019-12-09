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
bool noLegalPosition(vector<int> board, int n);
vector<int> SUCCESSOR(vector<int> board, int n);
vector<int> emptyBoard(vector<int> board, int n);
vector<int> nextFullSolvedBoard(vector<int> board, int n);
vector<int> fillBoard(vector<int> board, int n);
vector<int> correctIllegalBoard(vector<int> board, int n);
int getNumOfQueens(vector<int> board);
void printBoard(vector<int> board);

int main() {
	vector<int> board = { 1, 6, 8, 3, 7, 4, 2, 5 };//{ 1, 6, 8, 3, 5, 0, 0, 0 }; // works well { 1, 6, 8, 3, 7, 0, 0, 0 }; // works well  //{ 1, 6, 8, 3, 7, 4, 2, 5 };
	int n = board.size();
	cout << "Initial board" << endl;
	printBoard(board);
	bool legPos = isLegalPosition(board, n);
//	board = SUCCESSOR(board, n);
	board = nextLegalPosition(board, n);
	cout << "IsLegalPosition result is " << legPos << endl;
	cout << "Next Legal Position is" << endl;
//	cout << "SUCCESSOR IS" << endl;
	printBoard(board);
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
	vector<int> successor;
	//works well
	successor = SUCCESSOR(board, n);
	while(!isLegalPosition(successor, n)){
		successor = SUCCESSOR(successor, n);
	}
	return successor;
}

int getNumOfQueens(vector<int> board) {
	int boardSize = board.size();
	int counter = 0;
	for (int i = 0; i < boardSize; i++) {
		if (board[i] != 0) {
			counter++;
		}
	}
	return counter;
}

/*
 *
 */
vector<int> SUCCESSOR(vector<int> board, int n) {
	vector<int> successor;
	int lastQueenRow = 0;
	int lastQueenCol = 0;
	for (int i = n; i > 0; i--) { //gets the position of the last queen
		if (board[i - 1] != 0) {
			lastQueenRow = i;
			lastQueenCol = board[i - 1];
			break;
		}
	}

	for (int i = 0; i < n; i++) { // copy the contents before last queen
		if (i <= lastQueenRow - 1) {
			successor.push_back(board[i]);
		} else {
			successor.push_back(0);
		}
	}

	int notFullRow;
	int notFullCol;
	if ((lastQueenCol == n) && (lastQueenRow == n)) {
		for (int i = n; i > 0; i--) { //gets the position of the last queen that is not n value
			if (board[i - 1] != n) {
				notFullRow = i;
				notFullCol = board[i - 1];
				break;
			} else {
				successor.pop_back();
			}
		}
		for (int i = notFullRow - 1; i < n; i++) { // copy the contents before last queen
			if (i == (notFullRow - 1)) {
				successor[notFullRow - 1] = notFullCol + 1;
			} else {
				successor.push_back(0);
			}
		}
//		cout << "notFullRow is " << notFullRow << endl;
//		cout << "notFullCol is " << notFullCol << endl;
	} else if (lastQueenRow == n) {
		//	cout << "lastQueenRow is " << lastQueenRow << endl;
		//	cout << "lastQueenCol is " << lastQueenCol << endl;
		successor[lastQueenRow - 1] = lastQueenCol + 1;
	} else {
		successor[lastQueenRow] = 1;
	}
	return successor;
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
bool noLegalPosition(vector<int> board, int n) {
	bool result = false;
	return result;
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
//	cout << "Board size is " << boardSize << endl;
//	cout << "board looks like" << endl;
	for (int i = 0; i < boardSize; i++) {
		cout << board[i] << " ";
	}
	cout << endl;
}
