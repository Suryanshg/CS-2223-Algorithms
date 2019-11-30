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
int myHash(string word);

int C = 123;
int m = 1000;

int main() {
	hashFile();
	return 0;
}

/*
 * computes the hash for a given word
 */
int myHash(string word){
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
void hashFile() {
	ifstream file;
	file.open("Raven.txt");
	string ravenMap[1000];
	string word;
	word.clear();
	int h;
	if (file.is_open()) {
		while (!file.eof()) {
			file >> word;
			word = processString(word);
			if (word != "") { //hash the words
				//Levitin process

				h = myHash(word);
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
	cout << endl;
	for (int i = 0; i < 1000; i++) {
		cout << "index :" << i
				<< " ravenMap[" << i << "]: " << ravenMap[i] <<endl;
	}

	// Question 3
	// part a /////////////////////////////////////////////////
	double nonEmptyAddress = 0;
	for (int i = 0; i < 1000; i++) {
		if (ravenMap[i] != "") {
			nonEmptyAddress++;
		}
	}
	cout << "part a" << endl;
	cout << "Number of non-empty addresses in table is " << nonEmptyAddress << endl;
	cout << "Load Factor is "<< nonEmptyAddress/1000<<endl;

	// part b /////////////////////////////////////////////////
	int stringSize = 1000;
	int firstIndex = 0;
	if (ravenMap[1000] != "") {
		int i = 1000;
		while (ravenMap[i] != "") {
			i--;
		}
		firstIndex = i;
	}
	string ravenMapDuplicate[stringSize * 2];
	for (int i = 0; i < stringSize; i++) {
		ravenMapDuplicate[i] = ravenMapDuplicate[stringSize + i] = ravenMap[i];
	}
	int longestEmptyCount = 0;
	int longestEmptyEndingIndex = 0;
	int longestEmptyStartingIndex = 0;
	int previousCount = 0;

	for (int i = firstIndex; i < stringSize + firstIndex; i++) {
		if (ravenMapDuplicate[i] == "") {
			if (previousCount > longestEmptyCount) {
				previousCount++;
				longestEmptyCount = previousCount;
				longestEmptyEndingIndex = i - firstIndex;
			} else {
				previousCount++;
			}
		} else {
			previousCount = 0;
		}
	}

	if ((longestEmptyEndingIndex - longestEmptyCount) < 0) { //count is bigger than longestEmptyCount
		int temp = abs(longestEmptyEndingIndex - longestEmptyCount);
		longestEmptyStartingIndex = 1000 - temp;
	} else {
		longestEmptyStartingIndex = longestEmptyEndingIndex - longestEmptyCount
				+ 1;
	}
	cout << "part b" << endl;
	cout << "The longest empty area in the table is " << longestEmptyCount
			<< endl;
	cout << "The starting index is " << longestEmptyStartingIndex
			<< " and the ending index is " << longestEmptyEndingIndex << endl;




	//part b // revised
	cout<<"Part b revised"<<endl;
	int cStart=0,cEnd=0, maxStart=0, maxEnd=0;
	int clen=0,maxlen=0;
	int size=sizeof(ravenMap)/sizeof(ravenMap[0]);
	for(int i=0;i<size;i++){
		if(ravenMap[i]==""){
			cStart=i;
			i++;
			while(ravenMap[i]==""){
				i++;
			}
			cEnd=i-1;
			clen=cEnd-cStart+1;

			if(clen>maxlen){
				maxEnd=cEnd;
				maxStart=cStart;
				maxlen=clen;
			}
		}
	}

	cout<<" Longest Empty area starts at: "<<maxStart<<endl;
	cout<<" Longest Empty area ends at: "<<maxEnd<<endl;
	cout<<" Length of Longest Empty area is:"<< maxlen<<endl;


	//part c   /////////////////////////////////////////////////
	stringSize = 1000;
	firstIndex = 0;
	if (ravenMap[1000] == "") { //find what the first
		int i = 1000;
		while (ravenMap[i] == "") {
			i--;
		}
		firstIndex = i;
	}
	string ravenMap2ndDuplicate[stringSize * 2];
	for (int i = 0; i < stringSize; i++) {
		ravenMap2ndDuplicate[i] = ravenMap2ndDuplicate[stringSize + i] =
				ravenMap[i];
	}

	int longestNonEmptyCount = 0;
	int longestNonEmptyEndingIndex = 0;
	int longestNonEmptyStartingIndex = 0;
	previousCount = 0;

	for (int i = firstIndex; i < stringSize + firstIndex; i++) {
		if (ravenMap2ndDuplicate[i] != "") {
			if (previousCount > longestNonEmptyCount) {
				previousCount++;
				longestNonEmptyCount = previousCount + 1;
				longestNonEmptyEndingIndex = i - firstIndex;
			} else {
				previousCount++;
			}
		} else {
			previousCount = 0;
		}
	}
	if ((longestNonEmptyEndingIndex - longestNonEmptyCount) < 0) { //count is bigger than longestEmptyCount
		int temp = abs(longestNonEmptyEndingIndex - longestNonEmptyCount);
		longestNonEmptyStartingIndex = 1000 - temp;
	} else {
		longestNonEmptyStartingIndex = longestNonEmptyEndingIndex
				- longestNonEmptyCount + 1;
	}
	cout << "part c" << endl;
	cout << "The longest non-empty area in the table is "
			<< longestNonEmptyCount << endl;
	cout << "The starting index is " << longestNonEmptyStartingIndex
			<< " and the ending index is " << longestNonEmptyEndingIndex
			<< endl;

	//part c // revised
	cout<<"Part c revised"<<endl;
	cStart=0;
	cEnd=0;
	maxStart=0;
	maxEnd=0;
	clen=0;
	maxlen=0;

	for(int i=0;i<size;i++){
		if(ravenMap[i]!=""){
			cStart=i;
			i++;
			while(ravenMap[i]!=""){
				i++;
			}
			cEnd=i-1;
			clen=cEnd-cStart+1;

			if(clen>maxlen){
				maxEnd=cEnd;
				maxStart=cStart;
				maxlen=clen;
			}
		}
	}

	cout<<" Largest cluster starts at: "<<maxStart<<endl;
	cout<<" Largest cluster ends at: "<<maxEnd<<endl;
	cout<<" Length of Largest cluster is:"<< maxlen<<endl;

	//part e revised //
	cout<<"Part e"<<endl;
	int maxdiff=0,  curdiff=0;
	int maxHash=0, hash;
	for(int i=0;i<size;i++){
		if(myHash(ravenMap[i])!=i){
			hash=i;
			curdiff=abs(myHash(ravenMap[i])-i);
		}

		if(curdiff>maxdiff){
			maxdiff=curdiff;
			maxHash=hash;
		}
	}

	cout<<ravenMap[maxHash]<<" is stored the farthest that is "<<maxdiff<<" units from its actual hash: "<<myHash(ravenMap[maxHash])<<endl;
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
