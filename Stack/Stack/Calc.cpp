//Spencer Cheshire
//CS 2420-602
//Assignment 3 - Stack and Postfix calculation
//September 19th, 2016
//Main functions for the Postfix calculations using the Stack class implemented in the book.
//I, Spencer Cheshire, have not used any code other than my own (or that in the textbook) for this project. I
//also have not used any function or data-structure from the Standard-Template Library. I
//understand that any violation of this disclaimer will result in a 0 for the project

#include "Stack.h"
#include <fstream> //for 'ifstream'
#include <iostream> //for 'cout'
#include <string> //for 'string'

using namespace std;

//The orderOfOperations function
//Purpose: Function to determine which opcode or operator comes first. Determines the precedence
//Parameters: The two opcodes we are comparing
//Returns: True or false if op1 > op2, or op1 == op2
bool orderOfOperations(char, char);

//The readFile function
//Purpose: Allows for command line processing with a text file for this program
//Parameters: The argument that is getting passed in
//Returns: none
bool readFile(const char*);

int main(int argc, char **argv) {
	//If we want to use this on the command line, this if statement helps us with that
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " FILE" << endl;
		return EXIT_FAILURE;
	}

	readFile(argv[1]);

	std::system("PAUSE");
	return 0;
}

bool orderOfOperations(char opcode1, char opcode2)
{
	//Placeholders
	int value1 = -1;
	int value2 = -2;

	//Lines 52 - 65 Determine whether or not a certain operator comes before another or whether it is 'greater'
	//		than another.

	// OPCODE1 //
	if (opcode1 == '+' || opcode1 == '-')
		value1 = 1;
	else if (opcode1 == '*' || opcode1 == '/')
		value1 = 2;
	else //Just in case we get an invalid character
		return false;

	// OPCODE2 //
	if (opcode2 == '+' || opcode2 == '-')
		value2 = 1;
	else if (opcode2 == '+' || opcode2 == '-')
		value2 = 2;
	else //Just in case we get an invalid character
		return false;

	//Here is where we determine if one operator is greater than another
	if (value1 == value2)
		return true;
	else if (value1 > value2)
		return true;

	return false;
}

bool readFile(const char* theFile)
{
	//Declare local variables
	Stack<char> theStack;
	string fileInput;

	//Open the file
	ifstream in;
	in.open(theFile);

	//Make sure the file isn't empty...
	if(in.fail()) {
		cout << "\nError while opening the file, cannot continue.";
		cout << "\nApplication terminating...\n";
		in.close();
		return 1;
	}

	//I used these lines for testing, because I originally was using in.peek() instead of getline(), so this line
	//		helped me figure out the rest of the program
	//while (in) {
	//	getline(in, fileInput);
	//	cout << fileInput << endl;
	//}

	while (in.good() && in.peek() != EOF) {
		cout << endl;
		getline(in, fileInput);

		for(int i = 0; i < fileInput.length(); i++) {
			if (fileInput[i] == '(') { //The next input is a left parenthesis
				//Read the left parenthesis and push it onto the stack
				theStack.push(fileInput[i]); 
			} else if (isdigit(fileInput[i])) { //The next input is a number or other operand
				//Read the operand and write it to the output
				cout << fileInput[i] << " ";
			} else if (fileInput[i] == '+' || fileInput[i] == '-' || fileInput[i] == '*' || fileInput[i] == '/') { //The next input is one of the operation symbols
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
				theStack.push(fileInput[i]);
			} else if (fileInput[i] == ')') { //Read and discard the next input symbol (which should be a right parenthesis)
				//Print the top operation and pop it; keep printing and popping until the next symbol
				//   on the stack is a left parenthesis.
				while(!theStack.empty() && theStack.top() != '(') {
					//if (no left parenthesis is encountered)
						//Print an error message indicating unbalanced parenthesis, and halt. 
					
					cout << theStack.top() << " ";
					theStack.pop();
				}
			
				//Pop the left parenthesis
				theStack.pop();
			}
		}

		//This while loop handles the condition for the end of the line. If we're at the end of the line,
		//	we need to print the last item from the stack and move on to the next line
		while(!theStack.empty()) {
			cout << theStack.top();
			theStack.pop();
		}
	} 

	in.close();

	cout << endl;

	return true;
}