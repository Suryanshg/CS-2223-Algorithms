//============================================================================
// Name        : palindromecheck.cpp
// Author      : Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

string processString (string input);
string lower(string input);

int main() {

	string input;
	cout<<"Input String:";
	cin>>input;
	bool isPal=true;
//	string processedInput=processString(input);
//	cout<<processedInput<<endl;
	int len=input.length();
	int mid=len/2;
	for(int i=0;i<mid;i++){
		if(input[i]!=input[len-1-i]){
			isPal=false;
			break;
		}
	}

	if(isPal){
		cout<<"Yay! It's a Palindrome.\n";
	}
	else{
		cout<<"No! It's not a Palindrome.\n";
	}

	return 0;
}


/*
 * Processes a string by removing whitespace and extra special characters
 */
string processString(string input){
	string result;
	//input=lower(input);
	int len=input.length();
	for(int i=0;i<len;i++){
		if(isalpha(input[i])!=0){
			result.push_back(input[i]);
		}
	}
	return result;
}

/*
 *converts a string to lowercase
 */
string lower(string input){
	string result;
	int len=input.length();
	for(int i=0;i<len;i++){
		if(input[i]>='A' && input[i]<='Z'){
			result.push_back(input[i]-32);
		}
		else{
			result.push_back((input[i]));
		}
	}
	return result;
}
