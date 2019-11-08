//============================================================================
// Name        : palindromecheck.cpp
// Author      : Suryansh Goyal and Alex Galvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string processString(string input);

int main() {

	string input;
	cout << "Input String:";
	getline(cin, input); //  removes spaces from string and stores it in input
	bool isPal = true;
	string processedInput = processString(input);
	int len = processedInput.length();
	cout << processedInput << endl;
	int mid = len / 2;
	for (int i = 0; i < mid; i++) {
		if (processedInput[i] != processedInput[len - 1 - i]) {
			isPal = false;
			break;
		}
	}

	if (isPal) {
		cout << "Yay! It's a Palindrome.\n";
	} else {
		cout << "No! It's not a Palindrome.\n";
	}

	return 0;
}

/*
 * Processes a string by removing special characters and lowercasing the uppercase letters
 */
string processString(string input) {
	string result;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		if (isalpha(input[i]) != 0) {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				result.push_back(input[i] + 32);
			} else {
				result.push_back((input[i]));
			}
		}
	}
	return result;
}
