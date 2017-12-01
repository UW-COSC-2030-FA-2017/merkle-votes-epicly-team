#include <stdio.h>
#include<iostream>
#include<fstream>
#include "pMT.h"
using namespace std;


void readFile(string fileName)
{
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		myfile.close();
	}
	else
	{
		cout << "ERROR: Unable to open file" << endl;
	}
}


int main(int argc, char **argv)
{

	system("pause");
	return 0;
}
