//============================================================================
// Name        : HW2.cpp
// Author      : Alex G and Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <time.h>

using namespace std;

int Lucas(int n);
//void Combination(int a[], int reqLen, int start, int currLen, bool check[], int len);

int main() {

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




