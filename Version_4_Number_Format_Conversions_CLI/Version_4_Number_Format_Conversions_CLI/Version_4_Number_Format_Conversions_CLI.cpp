// Version_4_Number_Format_Conversions_CLI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //decleration of headers
#include <fstream> 
#include <string> 
#include <cmath>

#include "Calculator.h"


int calc()
{

	ofstream outputFile;
	outputFile.open("Calculation_History.txt", ios_base::app);
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
		outputFile << "Calculation: " << Result_1.getNum1() << " " << Result_1.getOp() << " " << Result_1.getNum2() << " = " << Result_1.Calculate() << endl;
		cout << "Continue? (Y/N)" << endl;
		cin >> Continue;

	}

	return 0;
}

int history()
{
	string temp;
	ifstream infile;
	infile.open("Calculation_History.txt"); 
	cout << "Calculations History" << endl;
	cout << "=====================================================================================" << endl;
	while (getline(infile, temp)) {
		//getline(infile, temp); // Saves the line in STRING.
		cout << temp << endl; // Prints our STRING. "\n" = newline
	}
	system("pause");
	return 0;
}




//-----------------------------------------------------------------------------------------------------------------------------------------------------//
//										DECIMAL TO BINARY 
//----------------------------------------------------------------------------------------------------------------------------------------------------//

int dectobin()
{
	ofstream outputFile;
	outputFile.open("Calculation_History.txt", ios_base::app);
	Calculator DectoBin;
	int n;

	cout << "Enter a decimal number: "; // Asks the user to enter a decimal value into the program
	cin >> n; // the application then stores the users input within the variable "n"

	DectoBin.setN(n);

	// binaryNumber is set to equal the value of the users input after going through the 
	// decimal to binary conversion operation
	cout << n << " in decimal = " << DectoBin.convertDecimalToBinary() << " in binary" << endl; // When the operation is complete the application will then 
	int answer = DectoBin.convertDecimalToBinary();// output the starting input and that value in binary 
	outputFile << n << " in decimal = " << answer << " in binary" << endl;
	system("pause"); // this stops the program from instantly closing by making the user press space before closing
	return 0;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------//
//										BINARY TO DECIMAL
//----------------------------------------------------------------------------------------------------------------------------------------------------//




int BintoDec()
{
	ofstream outputFile;
	outputFile.open("Calculation_History.txt", ios_base::app);
	Calculator BintoDec;
	long long n;


	cout << "Enter a binary number: ";
	cin >> n;
	if (n == 2, 3, 4, 5, 6, 7, 8, 9) {

		cout << "Error non base 2 input provided" << endl;
		system("Pause");
		return 0;
	}


	BintoDec.setN(n);

	cout << n << " in binary = " << BintoDec.convertBinaryToDecimal() << " in decimal" << endl;
	outputFile << n << " in binary = " << BintoDec.convertBinaryToDecimal() << " in decimal" << endl;
	system("pause");
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------//
//								DECIMAL TO HEXADECIMAL 
//----------------------------------------------------------------------------------------------------------------------------------------------------//



int DectoHex()
{
	ofstream outputFile;
	outputFile.open("Calculation_History.txt", ios_base::app);
	Calculator DectoHex;
	int val;
	cout << "Enter a Decimal number: ";
	cin >> val;
	cout << val << " in decimal = " << hex << val << " in hexadecimal" << endl;
	outputFile << val << " in decimal = " << hex << val << " in hexadecimal" << endl;
	system("pause");
	return 0;
}





int bintohex()
{
	ofstream outputFile;
	outputFile.open("Calculation_History.txt", ios_base::app);
	int hex[1000];
	int i = 1, j = 0, rem, dec = 0, binaryNumber;
	cout << "\n\n Convert a binary number to hexadecimal number:\n";
	cout << "----------------------------------------------------\n";
	cout << " Input a binary number: ";
	cin >> binaryNumber;
	while (binaryNumber > 0)
	{
		rem = binaryNumber % 2;
		dec = dec + rem * i;
		i = i * 2;
		binaryNumber = binaryNumber / 10;
	}
	i = 0;
	while (dec != 0)
	{
		hex[i] = dec % 16;
		dec = dec / 16;
		i++;
	}
	cout << " The hexadecimal value: ";
	for (j = i - 1; j >= 0; j--)
	{
		if (hex[j] > 9)
		{
			cout << (char)(hex[j] + 55);
		}
		else
		{
			cout << hex[j];
			outputFile << binaryNumber << " in binary = " << hex[j] << endl;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}



//-----------------------------------------------------------------------------------------------------------------------------------------------------//
//								MAIN MENU FUNCTION CODE
//----------------------------------------------------------------------------------------------------------------------------------------------------//





int main() //creating the main menu statement
{

	int choice;

	cout << "Welcome to my Calculator" << endl;
	cout << "Please select the option you desire" << endl;

	cout << "1.   Calculator" << endl;
	cout << "2.   View History" << endl;
	cout << "3.   Decimal to Binary Calculator" << endl;
	cout << "4.   Binary to Decimal Calculator" << endl;
	cout << "5.   Decimal to Hexadecimal Calculator" << endl;
	cout << "6.   Binary to Hexadecimal Calculator" << endl;

	cin >> choice;
	cout << endl;

	switch (choice) { // the switch case operator reads the users input/ choice and if the input value is equal to any of the defined cases
					  // below, then the respective output is executed. Otherwise, nothing happens and the user is made aware of the mistake
	case 1:
		calc(); //if the user enters "1" then the calculator function is triggered
		break;

	case 2: // if the user enters "2" then the calculation history function is called
		history();
		break;


	case 3:
		dectobin();
		break;

	case 4:
		BintoDec();
		break;
	case 5:
		DectoHex();
		break;

	case 6:
		bintohex();
		break;
	}
	cout << "Invalid Input" << endl;
	system("pause");
	return 0;
}

