//============================================================================
// Name        : HW2.cpp
// Author      : Alex G and Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <time.h>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

int Lucas(int n);

vector<vector<int>> powerSet; // vector of combinations

int sum33(int n);
int comboSum(int maxSum);

int main() {
	string input;
	cout<<"Would you to do Lucas Number (LN) or Suribach's Magic Square (SMS)?:";
	cin>>input;
	if(input == "LN"){
		double start,end;
		double currTimeElapsed;
		double prevTimeElapsed;

		int input = 0;
		cout<<"How many Lucas Numbers do you want to print?:";
		cin >> input;
		for(int i = 0; i<=input; i++)
		{
			start = clock();
			cout<< "L(" << i <<"): "<< Lucas(i);
			end = clock();
			currTimeElapsed=(end-start)/CLOCKS_PER_SEC;
			cout<< ", time: " <<currTimeElapsed<<" seconds.";

			if(i>0){
				if(prevTimeElapsed!=0){
					cout<<", Ratio of successive calculations:"<<currTimeElapsed/prevTimeElapsed;
				}
			}
			cout<<"\n";

			prevTimeElapsed=currTimeElapsed;

		}
	}
	else if(input == "SMS"){
		int MagicSquare[16] = {1, 14, 14, 4, 11, 7, 6, 9, 8 , 10, 10, 5, 13, 2, 3, 15};
		cout<<"The Suribach's magic square is: \n";
		for(int i=0;i<16;i++){ // prints the magic square
			cout<<MagicSquare[i]<<" ";
			if ((i+1)%4==0){
				cout<<"\n";
			}
		}


		int N=pow(2,16);
		for(int i=0;i<N;i++){
			vector<int> subSet;
			for(int j=0;j<16;j++){
				if(i & (1<<j)){
					subSet.push_back(MagicSquare[j]);
				}
			}
			powerSet.push_back(subSet);
		}

		for(int i=1;i<=16;i++){
			cout<< "The combinations of "<<i<<" from Magic Square that add up to 33 is "<< sum33(i)<<"\n";
		}

		for(int i=0;i<=132;i++){
			cout<< "The combinations from Magic Square that add up to "<<i<<" is "<<comboSum(i)<<"\n";
		}







	}
}

int Lucas(int n){
	if(n == 0) {
		return 2;
	}
	else if(n == 1) {
		return 1;
	}
	else{
		return (Lucas(n-1) + Lucas(n-2));
	}
}

int sum33(int n){
	int count=0;
	int sum=0;
	int subSize;
	int size=powerSet.size();
	for(int i=0;i<size;i++){
		subSize=powerSet[i].size();
		if(subSize==n){
			sum=0;
			for(int j=0; j<subSize;j++){
				sum+=powerSet[i][j];
			}
			if(sum==33){
				count++;
			}
		}
	}

	return count;
}

int comboSum(int maxSum){
	int count=0;
	int sum=0;
	int subSize;
	int size=powerSet.size();
	for(int i=0;i<size;i++){
		subSize=powerSet[i].size();
		sum=0;
		for(int j=0;j<subSize;j++){
			sum+=powerSet[i][j];
		}
		if(sum==maxSum){
			count++;
		}
	}

	return count;
}





