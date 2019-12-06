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
#include<vector>

using namespace std;

string nodes[10] = { "A", "J", "M", "R", "K", "S", "I", "N", "T", "D" };

int determineMatrixSize();
int** determineMatrix(int size);
void determineInfo(string *startNode, string *endNode, int size);
int** performDijkstra(string startNode, string endNode, int **fileMatrix,
		int size);
bool contains(vector<int> vector, int node);
int getIndex(string node);
void produceResults(int **dijkstraGraph, string startNode, string endNode,
		int size);
void printMatrix(int **matrix, int size);

int main() {
	int size = determineMatrixSize();
	int **fileMatrix = determineMatrix(size);
	string startNode, endNode;
	determineInfo(&startNode, &endNode, size);
	int **dijkstraGraph = performDijkstra(startNode, endNode, fileMatrix, size);
	produceResults(dijkstraGraph, startNode, endNode, size);
}

/*
 * Determines the size of the matrix and return it as an int
 */
int determineMatrixSize() {
	ifstream file;
	file.open("DijkstraExample.txt");
	int intMatrixSize;
	file >> intMatrixSize;
	file.close();
	return intMatrixSize;
}

/*
 * a 2D matrix is produced based on the passed in file containing matrix
 * returns the 2D matrix
 */
int** determineMatrix(int size) {
	ifstream file;
	file.open("DijkstraExample.txt");
	int intMatrixSize;
	file >> intMatrixSize;
	int x;
	int **fileMatrix = 0;
	fileMatrix = new int*[size];
	for (int i = 0; i < size; i++) {
		fileMatrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			file >> x;
			fileMatrix[i][j] = x;
		}
	}
	file.close();
	return fileMatrix;
}

/*
 * Determines the start node and end node desired
 * stores startNode and endNode
 */
void determineInfo(string *startNode, string *endNode, int size) {
	cout << "Enter start node: " << endl;
	bool startNodeValid = false;
	while (!startNodeValid) {
		cin >> *startNode;
		for (int i = 0; i < size; i++) {
			if (*startNode == nodes[i]) {
				startNodeValid = true;
			}
		}
		if (!startNodeValid) {
			cout << "This node is not valid. Try again" << endl;
		}
	}
	cout << "Enter end node: " << endl;
	bool endNodeValid = false;
	while (!endNodeValid) {
		cin >> *endNode;
		for (int i = 0; i < size; i++) {
			if (*endNode == nodes[i]) {
				endNodeValid = true;
			}
		}
		if (!endNodeValid) {
			cout << "This node is not valid. Try again" << endl;
		}
	}
}

/*
 * Based on the inserted file, Dijkstra is performed, producing a graph of
 * the distance, source, and visited
 * Returns graph
 */
int** performDijkstra(string startNode, string endNode, int **fileMatrix,
		int size) {
	int start = getIndex(startNode);

	int **Q = 0;
	Q = new int*[size];
	for (int i = 0; i < size; i++) { //setting up the queue
		Q[i] = new int[3];
		Q[i][0] = -1; // setting penultimate vertex to -1 initially
		if (i == start) {
			Q[i][1] = 0; //setting distance 0 for src
		} else {
			Q[i][1] = INT_MAX; // setting initial distance to INT_MAX from src

		}
		Q[i][2] = 0; // done with vertex or not
	}

	//for printing the Q
	//	for(int i = 0; i < 10; i++){
	//		for(int j = 0; j < 3; j++){
	//			cout<<Q[i][j]<< " " ;
	//		}
	//		cout<<"\n";
	//	}

	for (int i = 0; i < size; i++) {

		//find min distance vertex
		int min = INT_MAX;
		int minIndex;
		for (int j = 0; j < size; j++) { //go through all vertices which have Q[j][2]==0
			if (Q[j][2] == 0) {
				if (Q[j][1] < min) {
					min = Q[j][1];
					minIndex = j;
				}
			}
		}
		Q[minIndex][2] = 1; //done with the min

		//get adjacent node's index
		vector<int> adjacent; //array of adjacent indices
		for (int j = 0; j < size; j++) {
			if (fileMatrix[minIndex][j] > 0) {
				adjacent.push_back(j);
			}
		}

		int j = 0;
		while (j < size) {
			if (Q[j][2] == 0 && contains(adjacent, j)) { // look into the adjacent and not-done nodes
				if (Q[minIndex][1] + fileMatrix[minIndex][j] <= Q[j][1]) {
					Q[j][1] = Q[minIndex][1] + fileMatrix[minIndex][j];
					Q[j][0] = minIndex;
				}
			}

			j++;
		}

	}

	//	//for printing the Q
	//	for (int i = 0; i < 10; i++) {
	//		for (int j = 0; j < 3; j++) {
	//			cout << Q[i][j] << " ";
	//		}
	//		cout << "\n";
	//	}
	return Q;
}

/*
 * Determines the corresponding node's index found in nodes[]
 * Returns index
 */
int getIndex(string node) {
	int index;
	for (int i = 0; i < 10; i++) {
		if (node == nodes[i]) {
			index = i;
			break;
		}
	}
	return index;
}

/*
 * Determines whether the node adjacent and determines whether it is in the vector
 * return true if the node is in the vector
 * return false if otherwise
 */
bool contains(vector<int> vector, int node) {
	bool found = false;
	int size = vector.size();
	for (int i = 0; i < size; i++) {
		if (vector[i] == node) {
			found = true;
			break;
		}
	}
	return found;
}

/*
 * Produce the shortest distance from one node to another
 * Also produces the node route from starting node to end node
 */
void produceResults(int **dijkstraGraph, string startNode, string endNode,
		int size) {
	//Length of desired path
	//Quickest route to endNode
	int end = getIndex(endNode);
	cout << "The shortest distance between " << startNode << " to " << endNode
			<< " is " << dijkstraGraph[end][1] << endl;
	cout << "Shortest Path from " << startNode << " to " << endNode << " is:"
			<< endl;
	vector<int> path;
	path.push_back(end);
	while (endNode != startNode) {
		int index = getIndex(endNode);
		path.push_back(dijkstraGraph[index][0]);
		endNode = nodes[dijkstraGraph[index][0]];
	}
	size = path.size();
	for (int i = size - 1; i >= 0; i--) {
		string arrow = (i == 0) ? "" : " -> ";
		cout << nodes[path[i]] << arrow;
	}
	cout << endl;
}

//Printing the Weighted Graph Matrix
void printMatrix(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			string space = ((matrix[i][j] < 10) ? ("   ") :
							(matrix[i][j] < 100) ? ("  ") : (" "));
			cout << matrix[i][j] << space;
		}
		cout << endl;
	}
}

