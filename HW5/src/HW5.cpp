//============================================================================
// Name        : HW5.cpp
// Author      : Alex Galvan && Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<iterator>
#include<fstream>
#include<string.h>
using namespace std;

void hashFile();
string processString(string input);

int C = 123;
int m = 1000;

int main() {
	hashFile();
	return 0;
}

/*
 * Takes a word within file and determines
 * the word's hash value
 */
void hashFile() {
	ifstream file;
	file.open("Raven.txt");
	string ravenmap[1000];
	string word;
	char x;
	word.clear();

	while (!file.eof()) {
		x = file.get();

		while (x != ' ') {
			word = word + x;
			x = file.get();
		}

		word = processString(word);
		if (word != "") { //hash the words
			//Levitin process

			int h = 0;
			int s = word.size();
			for (int i = 0; i < s; i++) {
				h = (h * C + word[i]) % m;
			}
			cout << word << ":  h value = " << h;
			if (ravenmap[h]!= word) {	//word isn't in hashmap
				ravenmap[h]=word;
				cout << " " << word << " has been added to the hashmap" << endl;
			} else { //word is in map

				cout << " " << word << " is already in the hashmap" << endl;
			}
			word.clear();
		}
	}
}

/*
 * Processes a string by accepting only a,..z,A,..Z,'
 */
string processString(string input) {
	string result;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		if (isalpha(input[i]) != 0) {
			result.push_back((input[i]));
		} else if (input[i] == '\'') {
			result.push_back((input[i]));
		}
	}
	return result;
}
