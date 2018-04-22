// CPP File => Function Definition File  
#include "stdafx.h"
#include "Calculator.h"

Calculator::Calculator()
//Example of Scope resolution (the double colons) 
{
	// Member Variables set to their Null states 
	Newnum1, Newnum2 = 0;
	Newopr = ' ';
}

Calculator::Calculator(float num1, float num2, char opr)
{
	Newnum1 = num1;
	Newnum2 = num2;
	Newopr = opr;
}

Calculator::~Calculator() //the object destructor
{

}

float Calculator::getNum1() const
{
	return Newnum1;
}

float Calculator::getNum2() const
{
	return Newnum2;
}

char Calculator::getOp() const
{
	return Newopr;
}

void Calculator::setNum1(float num1)
{
	Newnum1 = num1;
}

void Calculator::setNum2(float num2)
{
	Newnum2 = num2;
}


void Calculator::setOp(char opr)
{
	Newopr = opr;
}

double Calculator::Calculate() const
{

	switch (Newopr) { //the switch statement is used to find the result of the equation to be output 
	case '+':
		// This Case statement is for when the user wants to do addition using "case"
		// Then cout is used to output the product of num1 + num2 followed by an end to the case with a break
		return Newnum1 + Newnum2;
		break;
	case'-':
		// This case statement is for when the user wants to do subtraction 
		// Then cout is used to output the product of num1 - num2
		return Newnum1 - Newnum2;
		break;
	case'*':
		// This case statement is for when the user wants to do multiplication
		// Then cout is used to output the product of num1 * num2
		return Newnum1 * Newnum2;
		break;

	case'/':
		// This case statement is for when the user wants to do division 
		// An if and else statement is used in case the user tries to divide by zero
		// IF the number is not zero then cout is used to output the product of num1 / num2 as desired by the user 
		// ELSE if it is zero then cout is used to output a statement letting the use know the problem

		if (Newnum2 != 0)
			return Newnum1 / Newnum2;
		else
			cout << "ERROR \nCannot divide by zero" << endl;
		break;
	default:
		cout << "Erroneous operation" << endl;
	}
}


void Calculator::setN(int n)
{
	Newn = n;
}

void Calculator::setN(long long n)
{
	Newn2 = n;
}

long long Calculator::convertDecimalToBinary() // this function is responsible for converting the users decimal input to binary
{
	long long binaryNumber = 0;
	int remainder, i = 1, step = 1;

	while (Newn != 0) // this while loop ensures that the operation will only occur if the user enters a value that is not empty/ NULL
	{ // the loop will continue to output the working out for the conversion until the answer is reached and thus the input number
	  // is now equal to 0, exiting the loop 
		remainder = Newn % 2;
		Newn /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}


int Calculator::convertBinaryToDecimal()
{
	int decimalNumber = 0, i = 0, remainder;
	while (Newn2 != 0)
	{
		remainder = Newn2 % 10;
		Newn2 /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}




