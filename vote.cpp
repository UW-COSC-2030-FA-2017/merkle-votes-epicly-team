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

			if (hashCall == 1)
			{
				merkleTree.find(vote, time, 1);

			}
			else if (hashCall == 2)
			{
				merkleTree.find(vote, time, 2);
			}
			else
			{
				merkleTree.find(vote, time, 3);
			}
		}

		//Test other functions
		merkleTree.locateData(vote);

		if (hashCall == 1)
		{
			merkleTree.locateHash(merkleTree.hash_1(vote));
			merkleTree.findHash(merkleTree.hash_1(vote));

		}
		else if (hashCall == 2)
		{
			merkleTree.locateHash(merkleTree.hash_2(vote));
			merkleTree.findHash(merkleTree.hash_2(vote));
		}
		else
		{
			merkleTree.locateHash(merkleTree.hash_3(vote));
			merkleTree.findHash(merkleTree.hash_3(vote));
		}

		in.close();
	}

	system("pause");
	return 0;
}
