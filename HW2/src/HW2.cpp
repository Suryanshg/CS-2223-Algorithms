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

using namespace std;

int Lucas(int n);
//void Combination(int a[], int reqLen, int start, int currLen, bool check[], int len);

int main() {
	char strInput[5];
	cout<<"Would you to do Lucas Number (LN) or Suribach's Magic Square (SMS)?";
	cin>>strInput;
	if(strcmp(strInput, "LN") == 0){
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
	else if(strcmp(strInput, "SMS") == 0){
		int i = 0;
		int j = 0;
		int k = 0;
		int l = 0;
		int count = 0;
		int combinations = 0;
		int SurySquare[16] = {1, 14, 14, 4, 11, 7, 6, 9, 8 , 10, 10, 5, 13, 2, 3, 15};
		for(i = 0; i<=12; i++){
			for((j = (i+1)); j<=13; j++){
				for((k = (j+1)); k<=14; k++){
					for((l = (k+1)); l<=15; l++){
						combinations++;
						if((SurySquare[i] + SurySquare[j] + SurySquare[k] + SurySquare[l]) == 33){
							count++;
						}
					}
				}
			}
		}
		cout<<"combinations: "<<combinations;
		cout<<"the number of 4 sum combinations for 33 is :"<<count;
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




