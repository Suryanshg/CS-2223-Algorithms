//============================================================================
// Name        : HW1.cpp
// Author      : Alex Galvan and Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

enum screen
{
	BEGINNING = 0,
	PLAYER = 1,
	CPU = 2,
	RESULTS = 3,
} state;

enum screen beginningPhase();
enum screen playerPhase();
enum screen cpuPhase();
enum screen resultsPhase(bool res);
void printBoard();
int randint(int max);
int countGreen=3,countYellow=7,countOrange=5;
string colors[3] = {"Green","Yellow","Orange"};

int main() {
	bool result = false; // false is lose, true is win for player 1

	printBoard();

	state = BEGINNING;
	while(1)
	{
		switch(state)
		{
		case BEGINNING:
			state = beginningPhase();
			break;

		case PLAYER:
			state = playerPhase();
			if((countGreen == 0) && (countYellow == 0) && (countOrange == 0)){
				result = true;
				state = RESULTS;
			}
			break;
		case CPU:
			state = cpuPhase();
			if((countGreen == 0) && (countYellow == 0) && (countOrange == 0)){
				result = false;
				state = RESULTS;
			}
			break;
		case RESULTS:
			state = resultsPhase(result);
			exit(0);
		}
	}
}

void printBoard(){
	int i;
	for(i=0;i<countGreen;i++){
		cout<<"G";
	}
	cout<<"\n";
	for(i=0;i<countYellow;i++){
		cout<<"Y";
	}
	cout<<"\n";
	for(i=0;i<countOrange;i++){
		cout<<"O";
	}
	cout<<"\n";

}
enum screen beginningPhase()
{

	string choice; //determine who goes first
	cout<<"Do you want to go first?(y/n): ";
	cin>>choice;
	cout<<"\n";
	if(choice=="y"){
		state = PLAYER;
	}
	else{
		state = CPU;
	}
	return state;
}
enum screen playerPhase()
{
	string color;
	int num;
	int valid=0;
	cout << "Player's turn" << endl;
	while(!valid){
		cout << "Which group you'd like to choose(G/Y/O):"; //choose color
		cin >> color;
		cout << "\n";


		cout << "Select how many colors to remove:"; //choose number
		cin >> num;
		cout << "\n";

		if(color=="G" && countGreen>0){
			if((num <= countGreen) && (num > 0)){
				countGreen=countGreen-num;
				valid=1;
			}
		}
		if(color=="Y" && countYellow>0){
			if((num <= countYellow) && (num > 0)){
				countYellow=countYellow-num;
				valid=1;
			}
		}
		if(color=="O" && countOrange>0){
			if((num <= countOrange) && (num > 0)){
				countOrange=countOrange-num;
				valid=1;
			}
		}

		if(!valid){
			cout<<"Invalid Input! Please Try Again!\n";
		}

	}

	printBoard();


	state = CPU;
	return state;
}
enum screen cpuPhase()
{
	int valid=0;
	int num;
	int colorCode;  // 0- Green, 1- Yellow, 2- Orange
	while(!valid){
		cout << "CPU's turn" << endl;
		colorCode=randint(3)-1;
		if(colorCode==0 && countGreen>0){ //it's green
			num=randint(countGreen);
			countGreen=countGreen-num;
			valid=1;
		}
		if(colorCode==1 && countYellow>0){ //it's yellow
			num=randint(countYellow);
			countYellow=countYellow-num;
			valid=1;
		}
		if(colorCode==2 && countOrange>0){ //it's Orange
			num=randint(countOrange);
			countOrange=countOrange-num;
			valid=1;
		}
	}
	cout << "CPU chooses "<< colors[colorCode] <<" color" << endl;
	cout << "CPU removes " << num << endl;
	state = PLAYER;
	return state;
}
enum screen resultsPhase(bool res)
{
	if(res == false){
		cout << "You Lose" << endl;
	}
	else if (res == true){
		cout << "You Win" << endl;
	}
	state = RESULTS;
	return state;
}
int randint(int max){
	return (rand() % max) + 1;
}
