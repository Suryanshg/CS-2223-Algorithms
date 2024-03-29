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
#include <time.h>

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
	srand(time(NULL));
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

/*
 * The board gets printed out to the Console
 */
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

/*
 * First phase of the game where the user specifies who moves
 * first.
 */
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

/*
 * Phase of the game where the user decides what color to remove and how many colors to remove
 */
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
/*
 * Phase of the game where the CPU decides what color to remove and how many. If player makes
 * a winning move, the CPU moves randomly; Otherwise, the CPU plays the winning
 * move with the correct color.
 */
enum screen cpuPhase()
{
	int valid=0;
	int num;
	int colorCode;  // 0- Green, 1- Yellow, 2- Orange
	cout << "CPU's turn" << endl;

	if((countGreen^countYellow^countOrange)==0){ // the player played the winning move!
		while(!valid){
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
	}

	else{ // make a winning move
		if((countGreen^countYellow) < countOrange){ // remove from Orange pile

			cout << "CPU chooses Orange color" << endl;
			cout << "CPU removes " << countOrange-(countGreen^countYellow) << endl;
			countOrange=countGreen^countYellow;
		}
		else if((countGreen^countOrange) < countYellow){ // remove from Yellow pile

			cout << "CPU chooses Yellow color" << endl;
			cout << "CPU removes " << countYellow-(countGreen^countOrange) << endl;
			countYellow=countGreen^countOrange;
		}
		else if((countOrange^countYellow) < countGreen){ // remove from Green pile

			cout << "CPU chooses Green color" << endl;
			cout << "CPU removes " << countGreen-(countOrange^countYellow) << endl;
			countGreen=countOrange^countYellow;
		}
	}
	printBoard();
	state = PLAYER;
	return state;
}
/*
 * Display the result of the game. If the User picks the last color, the user wins; Otherwise,
 * the CPU wins.
 */
enum screen resultsPhase(bool res)
{
	if(res == false){
		cout << "CPU WINS!!!" << endl;
	}
	else if (res == true){
		cout << "PLAYER WINS!!!" << endl;
	}
	state = RESULTS;
	return state;
}
/*
 * chose a random number in the range from 1 to the max number
 */
int randint(int max){
	return (rand() % max) + 1;
}
