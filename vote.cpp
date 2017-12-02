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

	//Create new tree with hash
	pMT merkleTree = pMT(hashCall);

	//Read file
	std::fstream in("mv_test.txt");
	if (!in)
	{
		cout << "Unable to open file";
	}
	else
	{
		string vote;
		int time;
		int i = 0;
		char delimeter('\t');
		while (in)
		{
			getline(in, vote, delimeter);
			cout << vote;
			time = time + 1;
			merkleTree.insert(vote, time);
		}
		in.close();
	}

	system("pause");
	return 0;
}
