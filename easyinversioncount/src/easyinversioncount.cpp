//============================================================================
// Name        : easyinversioncount.cpp
// Author      : Suryansh Goyal && Alex Galvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

int main() {
	int count = 0;
	int foo[] = {5,4,3,2,1};
	int len = sizeof(foo)/sizeof(foo[0]);
	//int len =*(&foo + 1)-foo;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (foo[i] > foo[j]) //num out of order
					{
				count++;
				cout<<"("<<foo[i]<<", "<<foo[j]<<") count: "<<count<<endl;
			}
		}
	}
	cout << "count: "<<count<<endl;
	return count;
}
