#include <stdio.h>
#include<iostream>
#include<fstream>
#include "pMT.h"
using namespace std;


int main(int argc, char **argv)
{
	//Get hash selection
	int hashCall = 0;
	cout << "Please choose a hash function: " << '\n'
		<< "1 = RS Hash" << '\n' << "2 = BKDR Hash"
		<< '\n' << "3 = Weak Hash" << '\n'
		<< "INPUT: ";
	cin >> hashCall;
	cout << '\n';

	//Create new tree
	pMT *merkleTree = new pMT(hashCall);

	//Read file
	std::fstream in("mv_test.txt");
	if (!in)
	{
		cout << "Unable to open file";
	}
	else
	{
		char test[255];
		string vote;
		string time;
		char delimeter('\t');
		while (in) {
			in.getline(test, 255, delimeter);

			cout << test << endl;
			time = vote.substr(vote.find('\t') + 1);
			cout << time;
		}
		in.close();
	}

	system("pause");
	return 0;
}
