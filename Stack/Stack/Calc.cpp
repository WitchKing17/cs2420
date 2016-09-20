//Spencer Cheshire
//CS 2420-602
//Assignment 3 - Stack and Postfix calculation
//September 19th, 2016
//Main functions for the Postfix calculations using the Stack class implemented in the book.
//I, Spencer Cheshire, have not used any code other than my own (or that in the textbook) for this project. I
//also have not used any function or data-structure from the Standard-Template Library. I
//understand that any violation of this disclaimer will result in a 0 for the project

#include "Stack.h"
#include <fstream> //for 'fstream'
#include <iostream> //for 'cout'
#include <string> //for 'string'

using namespace std;

//The isOperator function
//Purpose: Helper function for our main function to determine if the next character in the string is a symbol
//Parameters: The character we want to check
//Returns: true or false
bool isOperator(char o);

//The orderOfOperations function
//Purpose: Function to determine which opcode or operator comes first. Determines the precedence
//Parameters: The two opcodes we are comparing
//Returns: True or false if op1 > op2
bool orderOfOperations(char opcode1, char opcode2);

// UNCOMMENT LINE 31 AND LINES 34-37 AND LINE 98 IF YOU WANT TO USE THE COMMAND LINE INSTEAD

//int main(int argc, char **argv) {
int main() {
	//If we want to use this on the command line, this if statement helps us with that
	/*if (argc != 2) {
		cerr << "Usage: " << argv[0] << " FILE" << endl;
		return EXIT_FAILURE;
	}*/

	//Declare the variables we need for the program
	Stack<char> theStack;
	string fileInput;

	//Open the file
	ifstream in;
	in.open("tests.txt");

	//Make sure the file isn't empty...
	if(in.fail()) {
		cout << "\nError while opening the file, cannot continue.";
		cout << "\nApplication terminating...";
		std::system("PAUSE");
		return 1;
	}

	//I used these lines for testing, because I originally was using in.peek() instead of getline(), so this line
	//		helped me figure out the rest of the program
	//while (in) {
	//	getline(in, fileInput);
	//	cout << fileInput << endl;
	//}

	while (in) {
		cout << endl;
		getline(in, fileInput);

		for(int i = 0; i < fileInput.length(); i++) {
			if (fileInput[i] == '(') { //The next input is a left parenthesis
				//Read the left parenthesis and push it onto the stack
				theStack.push(fileInput[i]); 
			} else if (isdigit(fileInput[i])) { //The next input is a number or other operand
				//Read the operand and write it to the output
				//in >> fileInput[i];
				cout << fileInput[i] << " ";
				//theStack.push(fileInput[i]);
			} else if (isOperator(fileInput[i])) { //The next input is one of the operation symbols
				//while none of these three conditions are true: 
				//1. The stack becomes empty, or
				//2. The next symbol on the stack is a left parenthesis, or
				//3. The next symbol on the stack is an operation with lower precedence
				//		than the next input symbol
				while (!theStack.empty() && theStack.top() != '(' && orderOfOperations(theStack.top(), fileInput[i])) {
					//Print the top operation and pop it
					cout << theStack.top() << " ";
					theStack.pop();
				}
				
				//Read the next input symbol, and push this symbol onto the stack.
				//in >> fileInput[i];
				theStack.push(fileInput[i]);
			} else if (fileInput[i] == ')') { //Read and discard the next input symbol (which should be a right parenthesis)
				//Print the top operation and pop it; keep printing and popping until the next symbol
				//   on the stack is a left parenthesis.
				while(!theStack.empty() && theStack.top() != '(') {
					cout << theStack.top() << " ";
					theStack.pop();
				}
			
				//if (no left parenthesis is encountered)
					//Print an error message indicating unbalanced parenthesis, and halt. 
			
				//Pop the left parenthesis
				theStack.pop();
			}
		}

		//This while loop handles the condition for the end of the line. If we're at the end of the line,
		//	we need to 
		while(!theStack.empty()) {
			cout << theStack.top();
			theStack.pop();
		}
	} 

	in.close();

	cout << endl;

	std::system("PAUSE");
	return 0;
}

bool isOperator(char o) 
{
	//Check if we have MDAS (PEMDAS). 
	if (o == '+' || o == '-' || o == '*' || o == '/') {
		return true;
	}

	return false;
}

bool orderOfOperations(char opcode1, char opcode2)
{
	int weight1 = -1;
	int weight2 = -2;

	//These switch statements give certain operations their order, so we can make sure we're performing operations in
	//	the correct order.
	switch(opcode1) 
	{
	case '+':
	case '-':
		weight1 = 1;
	case '*':
	case '/':
		weight1 = 2;
	}

	switch(opcode2) 
	{
	case '+':
	case '-':
		weight2 = 1;
	case'*':
	case '/':
		weight2 = 2;
	}

	//Here is where we determine if one operator is greater than another
	if (weight1 == weight2)
		return true;
	else if (weight1 > weight2)
		return true;

	return false;
}