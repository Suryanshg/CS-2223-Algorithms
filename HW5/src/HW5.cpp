//old code
////============================================================================
//// Name        : HW5.cpp
//// Author      : Alex Galvan && Suryansh Goyal
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include<iostream>
//#include<fstream>
//#include<string.h>
//using namespace std;
//
//void hashFile();
//string processString(string input);
//int myHash(string word);
//
//int C = 123;
//int m = 1000;
//
//int main() {
//	hashFile();
//	return 0;
//}
//
///*
// * computes the hash for a given word
// */
//int myHash(string word) {
//	int h = 0;
//	int s = word.size();
//	for (int i = 0; i < s; i++) {
//		h = (h * C + word[i]) % m;
//	}
//	return h;
//}
//
///*
// * Takes a word within file and determines
// * the word's hash value
// */
//void hashFile() {
//	ifstream file;
//	file.open("Raven.txt");
//	string ravenMap[1000];
//	string word;
//	word.clear();
//	int h;
//	if (file.is_open()) {
//		while (!file.eof()) {
//			file >> word;
//			word = processString(word);
//			if (word != "") { //hash the words
//				//Levitin process
//
//				h = myHash(word);
//				cout << word << ":  h value = " << h << " ";
//
//				if (ravenMap[h] == word) { //word is in map
//
//					cout << " " << word << " is already in the hashmap" << endl;
//				}
//
//				else if (ravenMap[h] == "") {	//word isn't in hashmap
//					ravenMap[h] = word;
//					cout << " " << word << " has been added to the hashmap"
//							<< endl;
//				}
//
//				else if (ravenMap[h] != word) { // already occupied by some other word, collision
//					int count = 0;
//					while (ravenMap[h] != "") {
//						if (ravenMap[h] == word) {
//							cout << " " << word << " is already in the hashmap1"
//									<< endl;
//							break;
//						} else if (h == 999) {
//							h = 0;
//							count++;
//						} else {
//							h++;
//							count++;
//						}
//					}
//					if (ravenMap[h] == "") {
//						ravenMap[h] = word;
//						cout << " " << word
//								<< " has been added but at a different hash address"
//								<< endl;
//					}
//				}
//				word.clear();
//			}
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < 1000; i++) {
//		cout << "index :" << i << " ravenMap[" << i << "]: " << ravenMap[i]
//				<< endl;
//	}
//
//	// Question 3
//	// part a /////////////////////////////////////////////////
//	double nonEmptyAddress = 0;
//	for (int i = 0; i < 1000; i++) {
//		if (ravenMap[i] != "") {
//			nonEmptyAddress++;
//		}
//	}
//	cout << "part a" << endl;
//	cout << "Number of non-empty addresses in table is " << nonEmptyAddress
//			<< endl;
//	cout << "Load Factor is " << nonEmptyAddress / 1000 << endl;
//
//	//part b /////////////////////////////////////////////////
//	cout << "Part b " << endl;
//	int cStart = 0, cEnd = 0, maxStart = 0, maxEnd = 0;
//	int clen = 0, maxlen = 0;
//	int size = sizeof(ravenMap) / sizeof(ravenMap[0]);
//	for (int i = 0; i < size; i++) {
//		if (ravenMap[i] == "") {
//			cStart = i;
//			while (ravenMap[i] == "") {
//				i++;
//			}
//			cEnd = i - 1;
//			clen = cEnd - cStart + 1;
//
//			if (clen > maxlen) {
//				maxEnd = cEnd;
//				maxStart = cStart;
//				maxlen = clen;
//			}
//		}
//	}
//	clen = 0;
//	cStart = 0;
//
//	//checking the circular index position
//	if (ravenMap[size - 1] == "") {
//		int i = size - 1;
//		while (ravenMap[i] == "") {
//			i--;
//		}
//		cEnd = i + 1;
//		//cout << "cEnd is " << cEnd << endl;
//
//		i = 0;
//		while (ravenMap[i] == "") {
//			i++;
//		}
//		cStart = i - 1;
//		clen = cStart + cEnd - size + 2;
//		//cout << "cStart is " << cStart << endl;
//		//cout << "clen is " << clen << endl;
//		if (clen > maxlen) {
//			maxEnd = cEnd;
//			maxStart = cStart;
//			maxlen = clen;
//		}
//	}
//
//	cout << " Longest Empty area starts at: " << maxStart << endl;
//	cout << " Longest Empty area ends at: " << maxEnd << endl;
//	cout << " Length of Longest Empty area is:" << maxlen << endl;
//
//	//part c   /////////////////////////////////////////////////
//	cout << "Part c " << endl;
//	cStart = 0;
//	cEnd = 0;
//	maxStart = 0;
//	maxEnd = 0;
//	clen = 0;
//	maxlen = 0;
//
//	for (int i = 0; i < size; i++) {
//		if (ravenMap[i] != "") {
//			cStart = i;
//
//			while (ravenMap[i] != "") {
//				i++;
//			}
//			cEnd = i - 1;
//			clen = cEnd - cStart + 1;
//
//			if (clen > maxlen) {
//				maxEnd = cEnd;
//				maxStart = cStart;
//				maxlen = clen;
//			}
//		}
//	}
//
//	//checking the circular index position
//	if (ravenMap[size - 1] != "") {
//		int i = size - 1;
//		while (ravenMap[i] != "") {
//			i--;
//		}
//		cEnd = i + 1;
//		//cout << "cEnd is (should be 999)" << cEnd << endl;
//
//		i = 0;
//		while (ravenMap[i] != "") {
//			i++;
//		}
//		cStart = i - 1;
//		clen = cStart + cEnd - size + 2;
//		//cout << "cStart is (should be 0)" << cStart << endl;
//		//cout << "clen is (should be 1)" << clen << endl;
//		if (clen > maxlen) {
//			maxEnd = cEnd;
//			maxStart = cStart;
//			maxlen = clen;
//		}
//	}
//
//	cout << " Largest cluster starts at: " << maxStart << endl;
//	cout << " Largest cluster ends at: " << maxEnd << endl;
//	cout << " Length of Largest cluster is:" << maxlen << endl;
//
//	//part d //
//	cout << "Part d" << endl;
//	int maxNum = 0;
//	int maxHash = 0, hash;
//	for (int i = 0; i < size; i++) {
//		if (ravenMap[i] != "") {
//			hash = myHash(ravenMap[i]);
//			int curNum = 0;
//			for (int j = 0; j < size; j++) {
//				if (myHash(ravenMap[j]) == hash) {
//					curNum++;
//				}
//			}
//			if (curNum > maxNum) {
//				maxNum = curNum;
//				maxHash = hash;
//			}
//		}
//	}
//
//	cout << "Hash Address: " << maxHash
//			<< " results in greatest number of distinct " << maxNum << " words"
//			<< endl;
//
//	//test case
////	int count0 = 0;
////	for (int i = 0; i < size; i++) {
////		if (myHash(ravenMap[i]) == 0) {
////			count0++;
////		}
////	}
////
////	cout << "count0:" << count0 << endl;
//
//	//part e //
//	//cout << "Part e" << endl;
//	int maxdiff = 0, curdiff = 0;
//	maxHash = 0;
//	for (int i = 0; i < size; i++) {
//		if (myHash(ravenMap[i]) != i) {
//			hash = i;
//			if (i < myHash(ravenMap[i])) {
//				curdiff = i + 1000 - myHash(ravenMap[i]);
//			} else {
//				curdiff = myHash(ravenMap[i]) - i;
//			}
//		}
//		if (curdiff > maxdiff) {
//			maxdiff = curdiff;
//			maxHash = hash;
//		}
//	}
////	cout << ravenMap[maxHash] << " is stored the farthest that is " << maxdiff
////			<< " units from its actual hash: " << myHash(ravenMap[maxHash])
////			<< endl;
//
//	//part e
//	cout << "Part e" << endl;
//	int maxDist = 0;
//	maxHash = 0;
//	for (int i = 0; i < size; i++) {
//		int curDist = 0;
//		if (ravenMap[i] != "") {
//			hash = myHash(ravenMap[i]);
//			if (hash <= i) {
//				curDist = i - hash;
//			} else {// overlooped 999
//				curDist = i - hash + size;
//				//cout << "curDist (overlooped) is " << curDist << endl;
//			}
//			if (curDist > maxDist) {
//				maxHash = i;
//				maxDist = curDist;
//			}
//		}
//	}
//	cout << ravenMap[maxHash] << " is stored the farthest that is " << maxDist
//			<< " units from its actual hash: " << myHash(ravenMap[maxHash])
//			<< endl;
//}
//
///*
// * Processes a string by accepting only a,..z,A,..Z,'
// */
//string processString(string input) {
//	string result;
//	int len = input.length();
//	for (int i = 0; i < len; i++) {
//		if (isalpha(input[i]) != 0) {
//			result.push_back((input[i]));
//		} else if (input[i] == '\'') {
//			result.push_back((input[i]));
//		}
//	}
//	return result;
//}
//

//cleaned up code
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

string* determineCloseHashing();
string processString(string input);
void printHashTable(string *hashTable);
int calcHashWord(string word);
void printPartA(string *hashTable);
void printPartB(string *hashTable);
void printPartC(string *hashTable);
void printPartD(string *hashTable);
void printPartE(string *hashTable);

int C = 123;
int m = 1000;

int main() {
	string *closeHashTable = determineCloseHashing();
	cout << "before printing hash table" << endl;
	printHashTable(closeHashTable);
	cout << "after printing hash table" << endl;
	printPartA(closeHashTable);
	printPartB(closeHashTable);
	printPartC(closeHashTable);
	printPartD(closeHashTable);
	printPartE(closeHashTable);
	return 0;
}

/*
 * computes the hash for a given word
 */
int calcHashWord(string word) {
	int h = 0;
	int s = word.size();
	for (int i = 0; i < s; i++) {
		h = (h * C + word[i]) % m;
	}
	return h;
}

/*
 * Takes a word within file and determines
 * the word's hash value
 */
string* determineCloseHashing() {
	ifstream file;
	file.open("Raven.txt");
	string *ravenMap = new string[1000];
	string word;
	word.clear();
	int h;
	if (file.is_open()) {
		while (!file.eof()) {
			file >> word;
			word = processString(word);
			if (word != "") { //hash the words
				//Levitin process

				h = calcHashWord(word);
				cout << word << ":  h value = " << h << " ";

				if (ravenMap[h] == word) { //word is in map

					cout << " " << word << " is already in the hashmap" << endl;
				}

				else if (ravenMap[h] == "") {	//word isn't in hashmap
					ravenMap[h] = word;
					cout << " " << word << " has been added to the hashmap"
							<< endl;
				}

				else if (ravenMap[h] != word) { // already occupied by some other word, collision
					int count = 0;
					while (ravenMap[h] != "") {
						if (ravenMap[h] == word) {
							cout << " " << word << " is already in the hashmap1"
									<< endl;
							break;
						} else if (h == 999) {
							h = 0;
							count++;
						} else {
							h++;
							count++;
						}
					}
					if (ravenMap[h] == "") {
						ravenMap[h] = word;
						cout << " " << word
								<< " has been added but at a different hash address"
								<< endl;
					}
				}
				word.clear();
			}
		}
	}
	file.close();
	cout << endl;
	return ravenMap;
}

void printHashTable(string *hashTable) {
	cout << "before starting for loop" << endl;
	for (int i = 0; i < 1000; i++) {
		cout << "index :" << i << " ravenMap[" << i << "]: " << hashTable[i]
				<< endl;
	}
	cout << "after ending for loop" << endl;
}

//
//	// Question 3
//	// part a /////////////////////////////////////////////////
void printPartA(string *hashTable) {
	cout << "within part A" << endl;
	double nonEmptyAddress = 0;
	for (int i = 0; i < 1000; i++) {
		if (hashTable[i] != "") {
			nonEmptyAddress++;
		}
	}
	cout << "part a" << endl;
	cout << "Number of non-empty addresses in table is " << nonEmptyAddress
			<< endl;
	cout << "Load Factor is " << nonEmptyAddress / 1000 << endl;
}

//
//	//part b /////////////////////////////////////////////////
void printPartB(string *hashTable) {
	cout << "Part b " << endl;
	int cStart = 0, cEnd = 0, maxStart = 0, maxEnd = 0;
	int clen = 0, maxlen = 0;
	int size = 1000;

	for (int i = 0; i < size; i++) {
		if (hashTable[i] == "") {
			cStart = i;
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

	//checking the circular index position
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
		cStart = i - 1;
		clen = cStart + cEnd - size + 2;
		if (clen > maxlen) {
			maxEnd = cEnd;
			maxStart = cStart;
			maxlen = clen;
		}
	}

	cout << " Longest Empty area starts at: " << maxStart << endl;
	cout << " Longest Empty area ends at: " << maxEnd << endl;
	cout << " Length of Longest Empty area is:" << maxlen << endl;

}
//	//part c   /////////////////////////////////////////////////
void printPartC(string *hashTable) {
	cout << "Part c " << endl;
	int cStart = 0;
	int cEnd = 0;
	int maxStart = 0;
	int maxEnd = 0;
	int clen = 0;
	int maxlen = 0;
	int size = 1000;

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
		clen = cStart + cEnd - size + 2;
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

//	//part d //
void printPartD(string *hashTable) {
	cout << "Part d" << endl;
	int maxNum = 0;
	int maxHash = 0, hash;
	int size = 1000;

	for (int i = 0; i < size; i++) {
		if (hashTable[i] != "") {
			hash = calcHashWord(hashTable[i]);
			int curNum = 0;
			for (int j = 0; j < size; j++) {
				if (calcHashWord(hashTable[j]) == hash) {
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

//part e //
void printPartE(string *hashTable) {
	cout << "Part e" << endl;
	int maxDist = 0, maxHash = 0, hash = 0;
	int size = 1000;

	for (int i = 0; i < size; i++) {
		int curDist = 0;
		if (hashTable[i] != "") {
			hash = calcHashWord(hashTable[i]);
			if (hash <= i) {
				curDist = i - hash;
			} else {	// overlooped 999
				curDist = i - hash + size;
				//cout << "curDist (overlooped) is " << curDist << endl;
			}
			if (curDist > maxDist) {
				maxHash = i;
				maxDist = curDist;
			}
		}
	}
	cout << hashTable[maxHash] << " is stored the farthest that is " << maxDist
			<< " units from its actual hash: "
			<< calcHashWord(hashTable[maxHash]) << endl;
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
