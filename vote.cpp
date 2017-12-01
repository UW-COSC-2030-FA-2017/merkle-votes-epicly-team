#include <stdio.h>
#include<iostream>
#include<fstream>
#include "pMT.h"
using namespace std;


void readFile(string fileName)
{
	string line;
	ifstream myfile;
	myfile.open(fileName);
	if (myfile.is_open())
	{
		//cout << "Successfully opened " << fileName << '\n';

		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	else
	{
		cout << "ERROR: Unable to open file" << endl;
	}
}


/*
void readFile(string fileName)
{
	std::fstream in("mv_test.txt");

	if (!in) {
		cout << "Unable to open file";
	}

	char test[255];
	string line;
	char delimeter(':');
	while (in) {
		in.getline(test, 255, delimeter);

		cout << test << endl;
	}
	in.close();
}
*/

int main(int argc, char **argv)
{
	readFile("mv_test.txt");

	system("pause");
	return 0;
}
