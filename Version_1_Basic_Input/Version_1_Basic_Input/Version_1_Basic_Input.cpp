// Version_1_Basic_Input.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string calculation;
	cout << "Please input your calculation string" << endl;
	getline(cin, calculation);
	if (calculation == "") {
		cout << "Please provide an input"<< endl;
	}
	else {
		cout << "Your Input Calculation was: " << calculation << ".\n";
	}
	system("pause");
	return 0;
}

