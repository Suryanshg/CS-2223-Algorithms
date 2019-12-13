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
vector<int> SUCCESSOR(vector<int> board, int n);
bool hasDuplicate(vector<int> board);
bool intersectDiagonally(vector<int> board);
int getNumOfQueens(vector<int> board);
void printBoard(vector<int> board);

int main() {
	vector<int> board = { 2, 4, 6, 1, 3, 5 };
	int n = board.size();

	//Question 1
	bool legPos = isLegalPosition(board, n);
	string result = (legPos == 1) ? "True" : "False";
	cout << "IsLegalPosition result is " << result << endl;

	//Question 2

	vector<int> nextLegalBoard = nextLegalPosition(board, n);
	cout << "Next legal board is  " << endl;
	printBoard(nextLegalBoard);

	//Question 3
//	for (int i = 4; i <= 100; i++) {
//		vector<int> newBoard;
//		for (int j = 0; j < i; j++) {
//			newBoard.push_back(0);
//		}
//		int numOfQueens = getNumOfQueens(newBoard);
//		while (numOfQueens != i) {
//			newBoard = nextLegalPosition(newBoard, i);
//			numOfQueens = getNumOfQueens(newBoard);
//		}
//		cout << "First board solution n = " << i << " is " << endl;
//		printBoard(newBoard);
//	}
	//Question 4
	for (int i = 4; i <= 20; i++) {
		vector<int> newBoard;
		vector<int> emptyBoard;
		int counter = 0;
		emptyBoard.assign(i, 0);
		for (int j = 0; j < i; j++) {
			if (j == 0) {
				newBoard.push_back(1);
			} else if (j != 0) {
				newBoard.push_back(0);
			}
		}
		int numOfQueens = getNumOfQueens(newBoard);
		while (newBoard != emptyBoard) {
			newBoard = nextLegalPosition(newBoard, i);
			numOfQueens = getNumOfQueens(newBoard);
//			printBoard(newBoard);
			if (numOfQueens == i) {
				counter++;
				//	printBoard(newBoard);
			}
		}
		cout << "Number of solutions to " << i << " boards is " << counter
				<< endl;
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
 *Determined
 */
vector<int> nextLegalPosition(vector<int> board, int n) {
	vector<int> successor = SUCCESSOR(board, n);
	while (!isLegalPosition(successor, n)) {
		successor = SUCCESSOR(successor, n);
	}
	return successor;
}

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
 *
 */
vector<int> SUCCESSOR(vector<int> board, int n) {
	vector<int> successor;
	int lastQueenRow = 0;
	int lastQueenCol = 0;
	for (int i = n - 1; i >= 0; i--) { //gets the position of the last queen
		if (board[i] != 0) {
			lastQueenRow = i + 1; //correct for indexing
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

	//last row is at its highest value
	if (lastQueenRow == n && lastQueenCol == n) {
		int lastNonfullRow;
		int lastNonfullCol;
		for (int i = n - 1; i >= 0; i--) { //gets the position of the last queen that isn't at its highest peak
			if (board[i] != n) {
				lastNonfullRow = i + 1;
				lastNonfullCol = successor[i];
				break;
			}
		}

		//increase counter for lastNonfullCol and trail by zeroes
		successor.clear();
		for (int i = 0; i < n; i++) {
			if (i < (lastNonfullRow - 1)) {
				successor.push_back(board[i]);
			} else if (i == (lastNonfullRow - 1)) {
				int newColNum = lastNonfullCol + 1;
				successor.push_back(newColNum);
			} else if (i > (lastNonfullRow - 1)) {
				successor.push_back(0);
			}
		}
	}

	// last row is not highest value
	else if (lastQueenRow == n && lastQueenCol != n) {
		successor[lastQueenRow - 1] = lastQueenCol + 1;
	}

	// board is not full of queens
	else if (lastQueenRow != n) {
		if (!isLegalPosition(successor, n)) {
			if (successor[lastQueenRow - 1] == n) {
				int lastNonfullRow;
				int lastNonfullCol;
				for (int i = n - 1; i >= 0; i--) { //gets the position of the last queen that isn't at its highest peak
					if (board[i] != n) {
						lastNonfullRow = i + 1; //correct for indexing
						lastNonfullCol = successor[i];
						break;
					}
				}
				//increase counter for lastNonfullCol and trail by zeroes
				successor.clear();
				for (int i = 0; i < n; i++) {
					if (i < (lastNonfullRow - 1)) {
						successor.push_back(board[i]);
					} else if (i == (lastNonfullRow - 1)) {
						int newColNum = lastNonfullCol + 1;
						successor.push_back(newColNum);
					} else if (i > (lastNonfullRow - 1)) {
						successor.push_back(0);
					}
				}
			} else if (successor[lastQueenRow - 1] != n) {
				successor[lastQueenRow - 1] += 1;
			}
		} else if (isLegalPosition(successor, n)) {
			successor[lastQueenRow] += 1;
		}
	}
	return successor;
}

/*
 *
 */
void printBoard(vector<int> board) {
	int boardSize = board.size();
	for (int i = 0; i < boardSize; i++) {
		cout << board[i] << " ";
	}
	cout << endl;
}
