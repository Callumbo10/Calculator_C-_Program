// Version_2_Basic_Calculator_CLI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //decleration of headers
#include <fstream> 
#include <string> 
#include <cmath>

#include "Calculator.h"


int main()
{

	char Continue = 'y';
	float num1, num2;
	char opr; //this is the variable that will store the users desired operator, for example "+"
	while (Continue == 'y') {
		cout << endl;
		cout << "Enter two integers (seperated by a space): "; //this prints the statement asking the user to enter their integers 
		cin >> num1 >> num2; //this then records the two integer inputs from the user and stores them as number 1 and 2 
		cout << endl;  //this then puts a space before the next line of text

		cout << "Enter operator: + (addition), - (subtraction)," << " * (multiplication), / (division): ";
		//this prints the statement asking the user to enter their desired operator 
		cin >> opr; //this then records and stores the users selected and input operator to complete the equation

		Calculator Result_1;

		Result_1.setNum1(num1);
		Result_1.setNum2(num2);
		Result_1.setOp(opr);

		cout << endl << "Calculation: " << Result_1.getNum1() << " " << Result_1.getOp() << " " << Result_1.getNum2() << " = " << Result_1.Calculate() << endl;
		cout << "Continue? (Y/N)" << endl;
		cin >> Continue;

	}

	return 0;
}