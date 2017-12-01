#include <stdio.h>
#include<iostream>
#include<fstream>
#include "pMT.h"
using namespace std;


void readFile()
{
	string line;
	char delimeter(':');
	ifstream myfile("mv_test.txt");
	while (getline(myfile, line))
	{
		cout << line << '\n';
	}
	myfile.close();
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

	system("pause");
	return 0;
}
