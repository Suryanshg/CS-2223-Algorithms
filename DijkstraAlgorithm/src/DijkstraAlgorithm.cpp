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

string nodes[10]={"A","J","M","R","K","S","I","N","T","D"};




bool contains(vector<int> vector,int node);
int getIndex(string node);


bool contains(vector<int> vector,int node){
	bool found=false;
	for(int i=0;i<vector.size();i++){
		if(vector[i]==node){
			found=true;
			break;
		}
	}
	return found;
}


int main() {

	ifstream file;
	file.open("DijkstraExample.txt");
	int intMatrixSize;
	file >> intMatrixSize;
	cout << "Matrix size is " << intMatrixSize << endl;
	int x;
	int fileMatrix[intMatrixSize][intMatrixSize];
	for (int i = 0; i < intMatrixSize; i++) {
		for (int j = 0; j < intMatrixSize; j++) {
			file >> x;
			fileMatrix[i][j] = x;
		}
	}
	file.close();

	int size=sizeof(fileMatrix)/sizeof(fileMatrix[0]);
	string startNode;
	string endNode;
	cout<<"Enter start node: "<<endl;
	cin >> startNode;
	cout<<"Enter end node: "<<endl;
	cin >> endNode;

	int start=getIndex(startNode);
	int end=getIndex(endNode);


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			string space = ((fileMatrix[i][j] < 10) ? ("   ") :
							(fileMatrix[i][j] < 100) ? ("  ") : (" "));
			cout << fileMatrix[i][j] << space;
		}
		cout << endl;
	}

	int Q[size][3];
	for(int i=0;i<size;i++){ //setting up the queue

		Q[i][0]=-1; // setting penultimate vertex to -1 initially
		if(i==start){
			Q[i][1]=0; //setting distance 0 for src
		}
		else{
			Q[i][1]=INT_MAX; // setting initial distance to INT_MAX from src

		}
		Q[i][2]=0; // done with vertex or not
	}

	//for printing the Q
//	for(int i = 0; i < 10; i++){
//		for(int j = 0; j < 3; j++){
//			cout<<Q[i][j]<< " " ;
//		}
//		cout<<"\n";
//	}

	for(int i = 0; i<size; i++){

		//find min distance vertex
		int min=INT_MAX;
		int minIndex;
		for(int j=0;j<size;j++){ //go through all vertices which have Q[j][2]==0
			if(Q[j][2]==0){
				if(Q[j][1]<min){
					min=Q[j][1];
					minIndex=j;
				}
			}
		}
		Q[minIndex][2]=1; //done with the min

		//get adjacent node's index
		vector<int> adjacent; //array of adjacent indices
		for(int j=0;j<size;j++){
			if(fileMatrix[minIndex][j]>0){
				adjacent.push_back(j);
			}
		}







		int j=0;
		while(j<size){
			if(Q[j][2]==0 && contains(adjacent,j)){ // look into the adjacent and not-done nodes
				if(Q[minIndex][1]+fileMatrix[minIndex][j]<=Q[j][1]){
					Q[j][1]=Q[minIndex][1]+fileMatrix[minIndex][j];
					Q[j][0]=minIndex;
				}
			}

			j++;
		}


	}

	//for printing the Q
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			cout<<Q[i][j]<< " " ;
		}
		cout<<"\n";
	}

	return 0;
}





int getIndex(string node){
	int index;
	for(int i=0;i<10;i++){
		if(node==nodes[i]){
			index= i;
			break;
		}
	}
	return index;
}
///////////
