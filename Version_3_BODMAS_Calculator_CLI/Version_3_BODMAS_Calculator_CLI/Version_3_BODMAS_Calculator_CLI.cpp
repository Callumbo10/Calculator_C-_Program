// BODMAScalcv3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<list>
#include<queue>
#include<cstdlib>
#include<cmath>
#include <string>

using namespace std; //namepsace std is included to tell the compiler which class/namespace to look in for an identifier.
					 //It also eliminates the need to include std:: infront of commands such as cout and cin, reducing code and efforts 

struct CalculatorLogic //similiar to the use of a class, each of the items below are defined as members
{
	double num; // This is used to store scanned Operands
	char currentCharacter; //this variable captures and stores the currently scanned character within the users input calculation, in order to isolate and work with it individually

	CalculatorLogic()
	{
		currentCharacter = ' '; //the currently scanned character variable is initally stored to blank
		num = 1; // the initial number variable is stored to 1 generically 
	}
};

list<CalculatorLogic> l; //list used for checks in the main function

queue<CalculatorLogic> Operands; //This Queue is utilised to store the Operands that are pulled from the users input expression
queue<CalculatorLogic> InputExpression; //This queue is utilised to store the user initially input expression, with all of the values being pushed onto it at the start and then popped off when a character has been sorted and 
										// pushed onto the correct respective stack or queue
stack<char> Operators; // This stack is utilised to store the operators that are pulled from the users input
stack<double> Results; //When the final answer is reached, this stack contains the result to be popped off and displayed to the user 


					   // =========================================================== PRECEDENCE/ PRIORITY OF OPERATOR FUNCTION ===================================================================================== //

int Priority(char currentCharacter) // this function will take the currently scanned character/ operator and check what precedence level it has
{
	switch (currentCharacter)
	{
	case '^':
		return 3;
	case '/':
	case '*':
		return 2; // the return values of these cases are utilised to later determine the precedence level of the characters on the stack and to decide whether or not the operators stack needs to be reorganised to 
				  //accomodate bodmas rules 
	case '+':
	case '-':
		return 1; //if it is a plus or minus, under bodmas rules these have the lowest precedence - hence the lowest value 
	default:
		return 0;
	}
}


// =========================================================== CHECK FOR BRACKETS FUNCTION ===================================================================================== //


bool brackets(char currentCharacter)
{
	switch (currentCharacter) // This function checks whether there are brackets and whether any of these operators are within them
	{
	case '+':
	case '-':
	case '/':
	case '*':
	case '^':
	case '(':
	case ')':
		return true;
	default:
		return false;
	}
}



// =========================================================== CHECK IF CHARACTER IS A NUMBER/ OPERAND: FUNCTION ===================================================================================== //

bool isOperand(char currentCharacter) //this function scans the current character in the input expression and checks whether it is an operand using ascii values below 
{
	if (currentCharacter == '.' || (int)currentCharacter >= 48 && (int)currentCharacter <= 57)
		return true; //if it is an operand then it returns true
	else
		return false; // if it isnt then it returns false 
}



// =========================================================== INFIX TO POSTFIX (Reverse Polish Notation) CONVERSION FUNCTION ===================================================================================== //

void Infix_To_Postfix_Conversion() //This function takes the users input infix expression and converts it into a postfix format. 
								   // the reason being that it is not only easier for the compilor, faster and more efficient but it also goes hand in hand with programming stack and queue data structures
{
	while (InputExpression.empty() == false) //while the users input is not empty the following can occur, otherwise an error is displayed 
	{
		CalculatorLogic currentCharacter = InputExpression.front(); //the current character variable is set to equal the first character in the users input expression
		InputExpression.pop(); //when this value has been stored in the currentCharacter variable, that character in the input expression queue is popped off 

		if (currentCharacter.currentCharacter == '(') //if the current character is an open bracket/ parenthesis
			Operators.push('('); // then it will be pushed onto the stack
		else if (currentCharacter.currentCharacter == ')') // however if it a close bracket
		{
			while (1)
			{
				char TemporaryCharacterStore = Operators.top(); // here a variable is created to temporarily store the top operator on the operator stack
				Operators.pop(); // this top oeprator is then removed from the stack
				if (TemporaryCharacterStore == '(' || TemporaryCharacterStore == '\0' || Operators.empty() == true) // now if the top operator, currently being stored in the TemporaryCharacterStore variable
																													// is an open bracket, divide by 0 or is empty then it will be ignored
					break;
				else //however, if these conditions are not met then another temporary storage variable is created to take the current operator and the top operator that was removed from the stack
					 // and push it onto the operands stack, which will the support of other functions, will order the stack in the correct BODMAS postfix layout ready for execution (without the need for parenthesis)
				{
					CalculatorLogic tempStore2;
					tempStore2.currentCharacter = TemporaryCharacterStore;
					Operands.push(tempStore2);
				}
			}
		}
		// else if the current character isnt a bracket and is instead a +,-,*,/ or ^ then the following will occur
		else if (currentCharacter.currentCharacter == '+' || currentCharacter.currentCharacter == '-'
			|| currentCharacter.currentCharacter == '/' || currentCharacter.currentCharacter == '*' || currentCharacter.currentCharacter == '^')
		{
			if (Operators.empty() == false && Priority(Operators.top()) <= Priority(currentCharacter.currentCharacter))
				//if the operator stack is not empty and the current top operator is less than or equal to the current selected operator 
				Operators.push(currentCharacter.currentCharacter); // then the operator will simply be pushed onto the stack as the operator at the top of the stack is of less than or equal to precedence and priority under
																   // bodmas rules
			else // else if this isnt the case
			{
				while (Operators.empty() == false && Priority(Operators.top()) > Priority(currentCharacter.currentCharacter)) // whilst the operator stack isnt empty, and the priority of the top operator on the stack
																															  //is greater than the current selected operator, then... 
				{
					CalculatorLogic tempStore2; // the temporary storage variable is utilised again to taken reorganize the stack so that the operator that was on top and has greater precedence, remains on top. 
												//Thus the new current selected operator will be placed on the stack first and underneath the high precedence operator so bodmas calculations are successful 
					tempStore2.currentCharacter = Operators.top();
					Operands.push(tempStore2);
					Operators.pop();
				}
				Operators.push(currentCharacter.currentCharacter);
			}
		}
		else //  if none of these cases are made then the current character must be an operand and thus will be added to the numbers/ operands queue
			Operands.push(currentCharacter);
	}

	while (Operators.empty() == false)  // this end section finalises this process and places all of the operands and operators onto one queue, which is the operands queue.
										//In the order that they need to be executed according to bodmas - ready for the next solve calculation function 
	{
		CalculatorLogic tempStore2;
		tempStore2.currentCharacter = Operators.top();
		Operands.push(tempStore2);
		Operators.pop();
	}
}

// =========================================================== SOLVE CALCULATION FUNCTION ===================================================================================== //

void SolveCalculation() //After the expression has been converted from infix to postfix this solve calculation function will commence 
{
	while (Operands.empty() == false) // Whilst the operands queue is not empty 
	{
		CalculatorLogic currentCharacter = Operands.front(); // the current character variable will store the top/ first value of the operands queue, then pop this value from the queue 
		Operands.pop();

		// the following function works in the same way as the basic calculator, by working in the order or the stack and placing operands and the variables op1 and op2 and then using a switch case to determine what operator is
		// to be conducted on these operands.
		// this is kept within a loop until stack is empty and all that is left is the answer which is kept and pushed onto the Results stack
		if (currentCharacter.currentCharacter == '+' || currentCharacter.currentCharacter == '*'
			|| currentCharacter.currentCharacter == '-' || currentCharacter.currentCharacter == '/' || currentCharacter.currentCharacter == '^')
		{
			double op2 = Results.top();
			Results.pop();
			double op1 = Results.top();
			Results.pop();

			switch (currentCharacter.currentCharacter)
			{
			case '+':
				op1 += op2;
				break;
			case '-':
				op1 -= op2;
				break;
			case '*':
				op1 *= op2;
				break;
			case '/':
				op1 /= op2;
				break;
			case '^':
				int num = op1;
				if ((int)op2 == op2)
				{
					for (register int i = 1; i < (int)op2; ++i)
						op1 *= num;
				}
				else
				{
					op1 = pow(op1, op2);
				}
				break;
			}
			Results.push(op1);
		}
		else if (currentCharacter.currentCharacter == ' ')
			Results.push(currentCharacter.num);
	}
}


// =========================================================== MAIN FUNCTION  ===================================================================================== //

int main() //The allocation of main as the function title, ensures it is the first function that is called 
{

	cout << "Enter the calculation " << endl; //when the user accesses the program they will be presented with a prompt for them to enter their mathematical expression
	string str; // this input will then be stored within the str string variable using the get line command 
	getline(cin, str, '\n');
	 if (str == "") {

		cout << "Blank input provided: Please enter a calculation" << endl;
		system("pause");
		return 0;
	}
	int i = 0;

	while (i < str.length()) //whilst the users input is not blank 
	{
		if (str[i] != ' ') //or equal to a space 
		{
			if (brackets(str[i]) == true) // a predefined list is used here in order to check the validity of the users input expression
										  // as well as sort the input into the correct stack or queue before calling the functions below 
			{
				CalculatorLogic Operators;
				Operators.currentCharacter = str[i];
				l.push_back(Operators);
				++i;
			}
			else if (isOperand(str[i]) == true)
			{
				string Operators = "";
				while (isOperand(str[i]) == true)
				{
					Operators += str[i];
					++i;
				}
				CalculatorLogic Operators1;
				Operators1.num = atof(Operators.data());
				l.push_back(Operators1);
			}

			else
			{
				cout << "Undefined symbol encountered : \"" << str[i] << "\"" << endl; // if none of these precheck conditions are met then the user has enteered and incorrect value and will be presented with an error message
				system("Pause");
				return 0;
			}
		}
		else
			++i;
	}

	list<CalculatorLogic>::iterator it = l.begin();
	while (it != l.end()) //whilst this list is not equal to nothing
	{
		InputExpression.push(*it);
		++it;
	}
	l.clear(); // this clears the list as it is no longer needed for the checks 
	Infix_To_Postfix_Conversion(); // the infix to postfix conversion funciton is then called
	SolveCalculation(); //  then when that is completed, the calculation function begins 
						// and the answer is outputed here by retrieving the top and only value on the results stack
	cout << "The Calculation Result is: \n" << Results.top() << endl;
	system("pause");
	return 0;
}