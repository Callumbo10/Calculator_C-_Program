#pragma once
#pragma once
// Header File => Function Declarations File 

#include "stdafx.h"
#include <iostream> //decleration of headers
#include <fstream> 
#include <string> 
#include <cmath> 

using namespace std;

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{ //uses encapsulation, to privatise certain information within the class to avoid changes being
  //made to it by other aspects of the file 
public:
	// Default Constructor:
	// sets the member variables to their null states 
	Calculator();


	// Overload Constructor:
	// created to provide a different way to call the same function 
	Calculator(float, float, char);
	// in order to overload it, parameters must be provided 

	double Calculate() const;
	// Calculate the expression - calculates the result from users inputs
	// @return double - result of users input calculation expression

	// Deconstructor: 
	// when the object leaves the function that it was created for, it is 
	// removed out of memory
	~Calculator();

	// Accessor Functions:
	// These functions return the member variables
	float getNum1() const; // using const as it is not modifying the member variables 
						   // Returns the users first input Operand
	float getNum2() const;
	// Returns the users second input Operand
	char getOp() const;
	// Returns the users input Operator 

	// Mutator Functions: 
	// Allow the user to edit the member variables one at a time
	void setNum1(float); // no const as they will be modifying the member variables
						 // act similiar to an overloader constructor but only modify one variable at a time

						 // setNum1 - sets new value for first input number
						 // @param float - first input number 

	void setNum2(float);
	// setNum2 - sets new value for second input number
	// @param float - second input number 

	void setOp(char);
	// setOp - sets new value for input operator
	// @param char - input operator

	void setN(int);

	void setN(long long);




	long long convertDecimalToBinary();

	int convertBinaryToDecimal();







private:
	// Member Variables
	float Newnum1, Newnum2;
	char Newopr;
	int Newn;
	long long Newn2;


};


#endif 
