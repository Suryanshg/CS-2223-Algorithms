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
vector<int> SUCCESSOR(vector<int> board, int n);
int getNumOfQueens(vector<int> board);
bool noNegativeValue(vector<int> board, int n);
bool noExplosiveValues(vector<int> board, int n);
void printBoard(vector<int> board);

int main() {
	vector<int> board = { 1, 4, 0, 0, 0, 0 };
	int n = board.size();
	cout << "Initial board" << endl;
	printBoard(board);

	//Question1
	bool legPos = isLegalPosition(board, n);
	string result = (legPos == 1) ? "True" : "False";
	cout << "IsLegalPosition result is " << result << endl;

	//Question2
	vector<int> successorBoard = SUCCESSOR(board, n);
	cout << "Successor of board is  " << endl;
	printBoard(successorBoard);

	vector<int> nextLegalBoard = nextLegalPosition(board, n);
	cout << "Next legal board is  " << endl;
	printBoard(nextLegalBoard);

	//Question 3
	for (int i = 4; i <= 100; i++) {
		vector<int> newBoard;
		for (int j = 0; j < i; j++) {
			if (j == 0) {
				newBoard.push_back(1);
			} else {
				newBoard.push_back(0);
			}
		}
		int numOfQueens = getNumOfQueens(newBoard);
		while (numOfQueens != i) {
			newBoard = nextLegalPosition(newBoard, i);
			numOfQueens = getNumOfQueens(newBoard);
		}
		cout << "First board solution n = " << i << " is " << endl;
		printBoard(newBoard);
	}
}

/*
 * Determines whether the board and the number of queens passed is a legal position where no queens are attacking each other
 * If a queen can attack another queen return false. Else, return true.
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
 *Determines the next legal position based on the input board
 *Inputs board and number of queens and returns a board with its
 *next legal position
 */
vector<int> nextLegalPosition(vector<int> board, int n) {
	vector<int> successor;
	int size = board.size();
	//works
	if (!isLegalPosition(board, n)) { // board is illegal, make last queen legal
		successor = SUCCESSOR(board, n);
		while (!(isLegalPosition(successor, n))) { //until i get the legal successor
			successor = SUCCESSOR(successor, n);
		}
	} else if ((isLegalPosition(board, n)) && (getNumOfQueens(board) == n)) { //board is fully solved
		successor = board;
		successor.pop_back();
		successor = SUCCESSOR(successor, n);
		while (!isLegalPosition(successor, n)) {
			successor = SUCCESSOR(successor, n);
		}
		//works well
	} else if (isLegalPosition(board, n)) { //board is legal
		for (int i = 0; i < size; i++) {
			if (board[i] != 0) {
				successor.push_back(board[i]);
			} else if (board[i] == 0) {
				successor.push_back(1);
				break;
			}
		}
		while (successor.size() != n) {
			successor.push_back(0);
		}
		while (!(isLegalPosition(successor, n))) {
			successor = SUCCESSOR(successor, n);
		}
	}
	return successor;
}

/*
 * returns the number of queens that are within a board
 */
int getNumOfQueens(vector<int> board) {
	int size = board.size();
	int numOfQueens = 0;
	for (int i = 0; i < size; i++) {
		if (board[i] != 0) {
			numOfQueens++;
		} else if (board[i] == 0) {
			break;
		}
	}
	return numOfQueens;
}

/*
 *Determines the next position of the board
 *Inputs a board and the number of queens
 */
vector<int> SUCCESSOR(vector<int> board, int n) {
	vector<int> successor;
	int lastQueenRow;
	int lastQueenCol;
	for (int i = n - 1; i >= 0; i--) { //gets the position of the last queen
		if (board[i] != 0) {
			lastQueenRow = i;
			lastQueenCol = board[i];
			break;
		}
	}

	for (int i = 0; i < n; i++) { // copy the contents before last queen
		if (i < lastQueenRow) {
			successor.push_back(board[i]);
		} else {
			successor.push_back(0);
		}
	}

	if (lastQueenRow == 0 && lastQueenCol == n) { // if on row1,col8 then return (0,0....0)
		for (int i = 0; i < n; i++) {
			successor[i] = 0;
		}
	} else if (lastQueenCol == n) {
		successor = SUCCESSOR(successor, n);
	} else {
		successor[lastQueenRow] = lastQueenCol + 1;
	}
	return successor;
}

/*
 * Inputs a board and determines whether queens share the same column
 * If more than one queen share a column, return true. Else, return false.
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
 *Inputs a board and determines if more than one queen share a diagonal. If a queen share a
 *diagonal, return true. Else, return false.
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
 * Make sure that the values produced within the board do not have negative numbers.
 * If a board has a negative number within the board, return true. Else, return false
 */
bool noNegativeValue(vector<int> board, int n) {
	bool result = true;
	for (int i = 0; i < n; i++) {
		if (board[i] < 0) {
			result = false;
			break;
		}
	}
	return result;
}

/*
 * Make sure that the values produced within the board do not have numbers bigger than a million.
 * If there are no huge numbers, return true. Else, return false
 */
bool noExplosiveValues(vector<int> board, int n) {
	bool result = true;
	for (int i = 0; i < n; i++) {
		if (board[i] > 99999) {
			result = false;
			break;
		}
	}
	return result;
}

/*
 *Prints out the board produced
 */
void printBoard(vector<int> board) {
	int boardSize = board.size();
	for (int i = 0; i < boardSize; i++) {
		cout << board[i] << " ";
	}
	cout << endl;
}
