//============================================================================
// Name        : HW5.cpp
// Author      : Alex Galvan && Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

string* determineCloseHashing(int size);
void determinePartA(string *hashTable, int size);
void determinePartB(string *hashTable, int size);
void determinePartC(string *hashTable, int size);
void determinePartD(string *hashTable, int size);
void determinePartE(string *hashTable, int size);
int calcHashWord(string word, int size);
string processString(string input);
void processWord(string *ravenMap, string word, int h, int size);
void printHashTable(string *hashTable, int size);

int main() {
	int size = 1000;
	string *closeHashTable = determineCloseHashing(size);
	printHashTable(closeHashTable, size);
	determinePartA(closeHashTable, size); //Question 3 part a
	determinePartB(closeHashTable, size); //Question 3 part b
	determinePartC(closeHashTable, size); //Question 3 part c
	determinePartD(closeHashTable, size); //Question 3 part d
	determinePartE(closeHashTable, size); //Question 3 part e
	return 0;
}

/*
 * Takes a word within file and determines
 * the word's hash value
 */
string* determineCloseHashing(int size) {
	int h;
	ifstream file;
	file.open("Raven.txt");
//  file.open("GettysburgAddress.txt");
	string *ravenMap = new string[size];
	string word;
	word.clear();
	if (file.is_open()) {
		while (!file.eof()) {
			file >> word;
			string listOfWords = word;
			size_t pos = 0;
			string token;
			while ((pos = listOfWords.find('-')) != string::npos) {
				token = listOfWords.substr(0, pos);
				token = processString(token);
				if (token != "") { //hash the words
					//Levitin process
					h = calcHashWord(token, size);
					processWord(ravenMap, token, h, size);
					token.clear();
				}
				listOfWords.erase(0, pos + 1);
			}
			listOfWords = processString(listOfWords);
			if (listOfWords != "") { //hash the words
				//Levitin process
				h = calcHashWord(listOfWords, size);
				processWord(ravenMap, listOfWords, h, size);
				listOfWords.clear();
			}
		}
	}
	file.close();
	cout << endl;
	return ravenMap;
}

/*
 * determines the number of non-empty addresses in the table
 */
void determinePartA(string *hashTable, int size) {
	double nonEmptyAddress = 0;
	for (int i = 0; i < size; i++) {
		if (hashTable[i] != "") {
			nonEmptyAddress++;
		}
	}
	cout << "Part a" << endl;
	cout << "Number of non-empty addresses in table is " << nonEmptyAddress
			<< endl;
	cout << "Load Factor is " << nonEmptyAddress / size << endl;
}

/*
 * determines the longest empty array within table
 */
void determinePartB(string *hashTable, int size) {
	int cStart = 0, cEnd = 0, maxStart = 0, maxEnd = 0, clen = 0, maxlen = 0;
	for (int i = 0; i < size; i++) {
		if (hashTable[i] == "") {
			cStart = i;
			//determines the number of consecutive empty spaces in array
			while (hashTable[i] == "") {
				i++;
			}
			cEnd = i - 1;
			clen = cEnd - cStart + 1;
			if (clen > maxlen) {
				maxEnd = cEnd;
				maxStart = cStart;
				maxlen = clen;
			}
		}
	}
	clen = 0;
	cStart = 0;

	//checking the circular index condition
	if (hashTable[size - 1] == "") {
		int i = size - 1;
		while (hashTable[i] == "") {
			i--;
		}
		cEnd = i + 1;
		i = 0;
		while (hashTable[i] == "") {
			i++;
		}
		cout << "cEnd is " << cEnd << endl;
		cStart = i - 1;
		cout << "cStart is " << cStart << endl;
		clen = (size - cEnd) + cStart + 1;
		if (clen > maxlen) {
			maxEnd = cEnd;
			maxStart = cStart;
			maxlen = clen;
		}
	}

	cout << "Part b " << endl;
	cout << " Longest Empty area starts at: " << maxStart << endl;
	cout << " Longest Empty area ends at: " << maxEnd << endl;
	cout << " Length of Longest Empty area is:" << maxlen << endl;

}

/*
 *determines the largest cluster within hashTable
 */
void determinePartC(string *hashTable, int size) {
	cout << "Part c " << endl;
	int cStart = 0;
	int cEnd = 0;
	int maxStart = 0;
	int maxEnd = 0;
	int clen = 0;
	int maxlen = 0;

	for (int i = 0; i < size; i++) {
		if (hashTable[i] != "") {
			cStart = i;

			while (hashTable[i] != "") {
				i++;
			}
			cEnd = i - 1;
			clen = cEnd - cStart + 1;

			if (clen > maxlen) {
				maxEnd = cEnd;
				maxStart = cStart;
				maxlen = clen;
			}
		}
	}

	//checking the circular index position
	if (hashTable[size - 1] != "") {
		int i = size - 1;
		while (hashTable[i] != "") {
			i--;
		}
		cEnd = i + 1;
		i = 0;
		while (hashTable[i] != "") {
			i++;
		}
		cStart = i - 1;
		clen = (size - cEnd) + cStart + 1;
		if (clen > maxlen) {
			maxEnd = cEnd;
			maxStart = cStart;
			maxlen = clen;
		}
	}

	cout << " Largest cluster starts at: " << maxStart << endl;
	cout << " Largest cluster ends at: " << maxEnd << endl;
	cout << " Length of Largest cluster is:" << maxlen << endl;
}

/*
 * Determines what hash address produces the greatest
 * number of distinct words and how many words that have that address
 */
void determinePartD(string *hashTable, int size) {
	cout << "Part d" << endl;
	int maxNum = 0, maxHash = 0, hash;
	for (int i = 0; i < size; i++) {
		if (hashTable[i] != "") {
			hash = calcHashWord(hashTable[i], size);
			int curNum = 0;
			for (int j = 0; j < size; j++) {
				if (calcHashWord(hashTable[j], size) == hash) {
					curNum++;
				}
			}
			if (curNum > maxNum) {
				maxNum = curNum;
				maxHash = hash;
			}
		}
	}

	cout << "Hash Address: " << maxHash
			<< " results in greatest number of distinct " << maxNum << " words"
			<< endl;
}

/*
 *determines the word that is farthest away from its actual hash address
 *and the distance it is from the hash address
 */
void determinePartE(string *hashTable, int size) {
	cout << "Part e" << endl;
	int maxDist = 0, maxHash = 0, hash = 0;
	for (int i = 0; i < size; i++) {
		int curDist = 0;
		if (hashTable[i] != "") {
			hash = calcHashWord(hashTable[i], size);
			if (hash <= i) {
				curDist = i - hash;
			} else { // overlooped array
				curDist = i - hash + size;
			}
			if (curDist > maxDist) {
				maxHash = i;
				maxDist = curDist;
			}
		}
	}
	cout << hashTable[maxHash] << " drifted more than any other word, " << endl;
	cout << maxDist << " places from hash address "
			<< calcHashWord(hashTable[maxHash], size)
			<< " all the way to position " << maxHash << endl;
}

/*
 * computes the hash for a given word
 */
int calcHashWord(string word, int size) {
	int h = 0;
	const int C = 123;
	const int m = size;
	int s = word.size();
	if (word == "") {
		h = -1;
	} else {
		for (int i = 0; i < s; i++) {
			h = (h * C + word[i]) % m;
		}
	}
	return h;
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

/*
 * takes in an array, word, hash value, and size of matrix
 * if the word is in the array, nothing happens
 */
void processWord(string *ravenMap, string word, int h, int size) {
	if (ravenMap[h] == word) { //word is in map
	} else if (ravenMap[h] == "") {	//word isn't in hashmap
		ravenMap[h] = word;
	} else if (ravenMap[h] != word) { // word collision
		while (ravenMap[h] != "") {
			if (ravenMap[h] == word) { //word is already in hashmap
				break;
			}
			if (h == size - 1) { //overloops array
				h = 0;
			} else {
				h++;
			}
		}
		if (ravenMap[h] == "") { //puts word within empty spot in array
			ravenMap[h] = word;
		}
	}
}

/*
 * prints out the hash table
 */
void printHashTable(string *hashTable, int size) {
	for (int i = 0; i < size; i++) {
		cout << i << "   " << hashTable[i] << "   "
				<< calcHashWord(hashTable[i], size) << endl;
	}
}
