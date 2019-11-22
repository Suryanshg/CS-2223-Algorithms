//============================================================================
// Name        : HW4.cpp
// Author      : Suryansh Goyal and Alex Galvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void printMatrix(int B[][8], int n);
void determinePath(int A[][8], int n);
int maxCol(int B[][8], int i, int j);

int main() {
	int A[8][8] = { { 89, 70, 73, 83, 90, 22, 44, 92 },
					{ 46, 23, 99, 77, 10, 42,  1, 72 },
					{ 85, 52, 27,  5, 94, 91, 82, 62 },
					{ 22, 93, 68, 11, 56, 63, 49, 35 },
					{ 13, 78, 48, 19, 78, 11, 90, 94 },
					{ 31,  5, 63, 10, 32, 40, 14, 13 },
					{ 73, 38, 24, 49, 18,  6, 40, 74 },
					{ 79, 71, 18, 20, 34, 51, 93, 65 },};

	int n = sizeof(A) / sizeof(A[0]);

	determinePath(A, n);
	return 0;
}

/*
 *Intakes given square floor of room with 64 smaller squares(A[][]),
 *Intakes order or size of A[][]
 *Determines Bilbo's starting square
 *Determines Bilbo's path
 *Determines the total number of gems that Bilbo collects
 *Determines the vault number where the King secreted the Arkenstone
 */
void determinePath(int A[][8], int n) {
	int temp;
	int B[8][8];
	for(int colNum = 0; colNum < n; colNum++){//fills B's last row with A's last row
		B[n-1][colNum] = A[n-1][colNum];
	}
	for (int currRow = n - 1; currRow > 0; currRow--) { //Determines matrix with optimal gem collection
		for (int nextRow = currRow - 1; nextRow > currRow - 2; nextRow--) {
			for (int colNum = 0; colNum < n; colNum++) {
				B[nextRow][colNum] = A[nextRow][colNum] + B[currRow][colNum]; //adds from Row behind
			}
			for (int colNum = 0; colNum < n - 1; colNum++) {
				temp = A[nextRow][colNum] + B[currRow][colNum + 1];
				if (temp > B[nextRow][colNum]) { //replaces value if bottom right value is greater
					B[nextRow][colNum] = temp;
				}
			}
			for (int colNum = 1; colNum < n; colNum++) {
				temp = A[nextRow][colNum] + B[currRow][colNum - 1];
				if (temp > B[nextRow][colNum]) { //replaces value if bottom left value is greater
					B[nextRow][colNum] = temp;
				}
			}
		}
	}
	printMatrix(B, n);
	int maxVal = 0;
	int maxValj = 0; //maxVal's vault number
	for (int vaultNum = 0; vaultNum < n; vaultNum++) {
		if (maxVal < B[0][vaultNum]) {
			maxVal = B[0][vaultNum];
			maxValj = vaultNum;
		}
	}
	int currCol = maxValj;
	int path[8];
	path[0] = maxValj + 1;
	for (int rowNum = 0; rowNum < n; rowNum++) {
		currCol = maxCol(B, rowNum, currCol);
		path[rowNum + 1] = currCol + 1;
	}

	cout << "Bilbo's starting square is " << B[7][path[7] - 1] << endl;
	cout << "Bilbo's path is:\n";
	for (int i = 0; i < n; i++) {
		cout << "Row " << n - i << ", Vault " << path[i] << endl;
	}
	cout << "The number of gems Bilbo collects is: " << maxVal << endl;
	cout << "Current vault where king has secreted the Arkenstone is: " << maxValj << endl;

}

/*
 * Determine the next rows biggest adjacent value from determined matrix
 * Inputs B matrix, current positions, i(row) and j(vault) value
 * Outputs the next row's biggest corresponding j (vault) value
 */
int maxCol(int B[][8], int i, int j) {
	if (j == 7) { // Currently On Vault 8
		if (B[i + 1][j] > B[i + 1][j - 1]) {
			return j; //Vault 8
		}
		if (B[i + 1][j] < B[i + 1][j - 1]) {
			return j - 1; //Vault 7
		}
	}
	if (j == 0) { //Currently on Vault 1
		if (B[i + 1][j] >= B[i + 1][j + 1]) {
			return j; //Vault 1
		}

		else if (B[i + 1][j] >= B[i + 1][j + 1]) {
			return j + 1; //Vault 2
		}
	}
	//Not on Vault 1 or 8
	else if ((B[i + 1][j - 1] >= B[i + 1][j])
			&& (B[i + 1][j - 1] >= B[i + 1][j + 1])) { //left Vault has greatest value
		return j - 1;
	} else if ((B[i + 1][j] >= B[i + 1][j - 1])
			&& (B[i + 1][j] >= B[i + 1][j + 1])) { //mid Vault has greatest value
		return j;
	} else if ((B[i + 1][j + 1] >= B[i + 1][j - 1])
			&& (B[i + 1][j + 1] >= B[i + 1][j])) { //right Vault has greatest value
		return j + 1;
	}
	return -1;
}

/*
 *Intakes the matrix[][]
 *Intakes size of matrix
 *Outputs values within matrix
 */
void printMatrix(int A[][8], int n) {
	string space;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			space = ((A[i][j] > 99) ? (" ") : ("  "));
			cout << A[i][j] << space;
		}
		cout << "\n";
	}
}
