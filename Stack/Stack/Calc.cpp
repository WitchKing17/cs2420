//Spencer Cheshire
//CS 2420-602
//Assignment 3 - Stack and Postfix calculation
//September 19th, 2016
//Main functions for the Postfix calculations using the Stack class implemented in the book.
//I, Spencer Cheshire, have not used any code other than my own (or that in the textbook) for this project. I
//also have not used any function or data-structure from the Standard-Template Library. I
//understand that any violation of this disclaimer will result in a 0 for the project

#include "Stack.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " FILE" << endl;
		return EXIT_FAILURE;
	}

	Stack<double> theStack;

	fstream in;
	in.open("tests.txt");

	if(in.fail()) {
		cout << "\nError while opening the file, cannot continue.\n";
		cout << "\nApplication terminating...";
		system("PAUSE");
		return 1;
	}

	while(in) {
		// if (the next input is a left parenthesis)
			// Read the left parenthesis and push it onto the stack
		// else if (the next input is a number or other operand)
			// Read the operand and write it to the output
		// else if (the next input is one of the operation symbols)
			// do
				// Print the top operation and pop it
			// while none of these three conditions are true: 
				// 1. The stack becomes empty, or
				// 2. The next symbol on the stack is a left parenthesis, or
				// 3. The next symbol on the stack is an operation with lower precedence
				//		than the next input symbol.
			
			// Read the next input symbol, and push this symbol onto the stack.
		// else
			// Read and discard the next input symbol (which should be a right parenthesis)
			// Print the top operation and pop it; keep printing and popping until the next symbol
			//   on the stack is a left parenthesis.
			// if (no left parenthesis is encountered)
				// Print an error message indicating unbalanced parenthesis, and halt). 
			// Pop the left parenthesis
	}

	in.close();

	system("PAUSE");
	return 0;
}