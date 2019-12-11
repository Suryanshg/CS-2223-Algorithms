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
void printBoard(vector<int> board);

int main() {
	vector<int> board = { 1, 6, 8, 3, 7, 0, 0, 0 };//{8,8,0,0,0,0,0,0};//{ 1, 6, 8, 3, 7, 4, 2, 5 }; // { 1, 6, 8, 3, 7, 0, 0, 0 }; // works{ 1, 6, 8, 3, 5, 0, 0, 0 };
	int n = board.size();
	cout << "Initial board" << endl;
	printBoard(board);
	//PART1
	bool legPos = isLegalPosition(board, n);
	string result = (legPos == 1) ? "True" : "False";
	cout << "IsLegalPosition result is " << result << endl;

	//PART2
	vector<int> successorBoard = SUCCESSOR(board, n);
	cout << "Successor of board is  " << endl;
	printBoard(successorBoard);

	vector<int> nextLegalBoard = nextLegalPosition(board, n);
	cout << "Next legal board is  " << endl;
	printBoard(nextLegalBoard);

	//PART3
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
	int size = board.size();
	 //works
	if (!isLegalPosition(board, n)) { // board is illegal, make last queen legal
		successor = SUCCESSOR(board, n);
		while(!(isLegalPosition(successor,n))){ //until i get the legal successor
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
//		successor=board;
//		successor.push_back(1);
//		while(!(isLegalPosition(board,n))){
//			successor=SUCCESSOR(successor,n);
//		}
		for(int i = 0; i < size; i++){
			if(board[i] != 0){
				successor.push_back(board[i]);
			} else if (board[i] == 0){
				successor.push_back(1);
				break;
			}
		}
		while(successor.size() != n){
			successor.push_back(0);
		}
		cout<<"Think this condition is fixed"<<endl;
		printBoard(successor);
		while (!(isLegalPosition(successor, n))) {
			successor = SUCCESSOR(successor, n);
			printBoard(successor);
		}
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
	int lastQueenRow;
	int lastQueenCol;
	for (int i = n - 1; i >= 0; i--) { //gets the position of the last queen
		if (board[i] != 0) {
			lastQueenRow = i;
			lastQueenCol = board[i];
			break;
		}
	}

	cout<<lastQueenRow<<endl;
	cout<<lastQueenCol<<endl;

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
		successor=SUCCESSOR(successor,n);
	} else {
		successor[lastQueenRow] = lastQueenCol + 1;
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
void printBoard(vector<int> board) {
	int boardSize = board.size();
//	cout << "Board size is " << boardSize << endl;
//	cout << "board looks like" << endl;
	for (int i = 0; i < boardSize; i++) {
		cout << board[i] << " ";
	}
	cout << endl;
}
