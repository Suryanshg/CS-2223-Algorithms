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
bool isLegalPosition2(vector<int> board, int n);
vector<int> nextLegalPosition(vector<int> board, int n);
vector<int> nextLegalPosition2(vector<int> board, int n);
bool hasDuplicate(vector<int> board);
bool intersectDiagonally(vector<int> board);
bool hasDuplicate2(vector<int> board);
bool intersectDiagonally2(vector<int> board);
vector<int> SUCCESSOR(vector<int> board, int n);
bool emptyRow(vector<int> board, int n);
void printBoard(vector<int> board);

int main() {
	vector<int> board = { 1, 6, 8, 3, 7, 4, 2, 5 }; //{ 1, 6, 8, 3, 5, 0, 0, 0 }; // works well { 1, 6, 8, 3, 7, 0, 0, 0 }; // works well  //{ 1, 6, 8, 3, 7, 4, 2, 5 };
	int n = board.size();
	cout << "Initial board" << endl;
	printBoard(board);
	bool legPos = isLegalPosition(board, n);
//	board = SUCCESSOR(board, n);
	board = nextLegalPosition(board, n);
	cout << "IsLegalPosition result is " << legPos << endl;
	cout << "Next Legal Position is" << endl;
	printBoard(board);
//	cout << "SUCCESSOR IS" << endl;
	for (int i = 4; i <= 100; i++) {
		vector<int> newBoard;
		for (int j = 0; j < i; j++) {
			if (j == 0) {
				newBoard.push_back(1);
			} else {
				newBoard.push_back(0);
			}
		}
		bool newBoardLegal = isLegalPosition2(newBoard, i);
		bool zeroRow = emptyRow(newBoard, i);
		while (!(newBoardLegal && !zeroRow)) {
			newBoard = nextLegalPosition2(newBoard, i);
			newBoardLegal = isLegalPosition2(newBoard, i);
			zeroRow = emptyRow(newBoard, i);
		}
		cout << "First board solution n = " << i << " is " << endl;
		printBoard(newBoard);
		newBoard.clear();
	}
}

/*
 *
 */
bool isLegalPosition(vector<int> board, int n) {
	bool result = true;

	bool duplicateCol = hasDuplicate(board); // only checks if last queen is repeated or not
	bool intersectDiag = intersectDiagonally(board);

	if (duplicateCol) {
		result = false;
	} else if (intersectDiag) {
		result = false;
	}
	return result;
}

/*
 *
 */
bool isLegalPosition2(vector<int> board, int n) {
	bool result = true;

	bool duplicateCol = hasDuplicate2(board); // only checks if last queen is repeated or not
	bool intersectDiag = intersectDiagonally2(board);

	if (duplicateCol) {
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
	successor = SUCCESSOR(board, n);
	while (!isLegalPosition(successor, n)) {
		successor = SUCCESSOR(successor, n);
	}
	return successor;
}

/*
 *
 */
vector<int> nextLegalPosition2(vector<int> board, int n) {
	vector<int> successor;
	successor = SUCCESSOR(board, n);
	while (!isLegalPosition2(successor, n)) {
		successor = SUCCESSOR(successor, n);
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

int getLastQueenRow(vector<int> board) { //gets the last queens row
	int lastQueenRow = 0;
	int size = board.size();
	for (int i = size; i > 0; i--) { //gets the position of the last queen
		if (board[i] != 0) {
			lastQueenRow = i;
			break;
		}
	}
	return lastQueenRow;
}

/*
 *
 */
bool hasDuplicate2(vector<int> board) { //only checks last queen
	bool result = false;
	int lastQueenRow = getLastQueenRow(board);
	for (int i = 0; i < lastQueenRow - 1; i++) {
		if (board[i] == board[lastQueenRow]) {
			result = true;
			break;
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

bool intersectDiagonally2(vector<int> board) { //only checks last queen
	bool intersect = false;
	int lastQueenRow = getLastQueenRow(board);
	for (int i = 0; i < lastQueenRow - 1; i++) {
		if (abs(board[i] - board[lastQueenRow]) == abs(i - lastQueenRow)) { //is a diagonal value
			intersect = true;
			break;
		}
	}
	return intersect;
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
bool emptyRow(vector<int> board, int n) {
	bool emptyRow = false;
	int boardSize = board.size();
	for (int i = 0; i < boardSize; i++) {
		if (board[i] == 0) {
			emptyRow = true;
			break;
		}
	}
	return emptyRow;
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
