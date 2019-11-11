//============================================================================
// Name        : graycodesarefun.cpp
// Author      : Suryansh Goyal && Alex Galvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
vector<string> brgc(int n);
void printChildren(string str);
int myFFS(int n);

string action[2]={"Out","In"};
string names[4]={"Dylan","Chris","Bob","Alice"};

int main()
{
 vector<string>grayCodes= brgc(4);
 int size=grayCodes.size();
 cout<<"Index | GrayCode |      Child(ren) in Photo      | Action"<<endl;
 string bit;
 int actionIndex;
 for(int i=1;i<size;i++){
     bit=grayCodes[i];
     actionIndex=bit[4-myFFS(i)] - '0';
     cout<<i<<"       "<<bit<<"          ";
     printChildren(bit);
     cout<<"                         "<<names[4-myFFS(i)]<<" "<<action[actionIndex];
     cout<<"\n";
 }

 //cout<<getLSB(result[1])<<endl;
}

/*
 * returns a vector of Gray codes of order "n"
 */
vector<string> brgc(int n){
    vector<string> result;
    if(n==1){
        result.push_back("0");
        result.push_back("1");
        return result;
    }
    else{
        vector<string> L1=brgc(n-1);
        vector<string> L2;
        int size=L1.size();
        for(int i=0;i<size;i++){
             L2.push_back(L1[size-1-i]);
        }

        for(int i=0;i<size;i++){
            L1[i].insert(0,"0");
            L2[i].insert(0,"1");
        }

        for(int i=0;i<size;i++){
            L1.push_back(L2[i]);
        }

        return L1;

    }

}

/*
 * Prints the children present in the passed bit string.
 */
void printChildren(string str){
    vector<int> children;
    int size=str.size();
    for(int i=0;i<size;i++){
        if(str[i]=='1'){
            children.push_back(i);
        }
    }
    size=children.size();
    cout<<names[children[0]];
    if(size>1){
        for(int i=1;i<size;i++){
            cout<<" & "<<names[children[i]];
        }
    }
}

/*
 * generates the position of the Least Significant set bit
 */
int myFFS(int n)
{
    return log2(n & -n) + 1;
}
