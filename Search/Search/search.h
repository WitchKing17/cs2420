//Spencer Cheshire
//CS 2420-601
//Assignment 4
//September 26th, 2016
//I, Spencer Cheshire, have not used any code other than my own (or that in the textbook) for this project. I
//also have not used any function or data-structure from the Standard-Template Library. I
//understand that any violation of this disclaimer will result in a 0 for the project

#include <iostream>
using namespace std;

//The RandomArray class
class RandomArray
{
//Friend ostream function to overload the << operator
//Purpose: overlads the << operator to print out the items in the RandomArray
//Paramters: An ostream object, and the array object we're printint out
//Returns: None, but prints out the items in the array
friend ostream& operator<<(ostream&, const RandomArray&);

public:
	//Default RandomArray constructor
	//Purpose: Creates a default RandomArray object
	//Parameters: None
	//Returns: None
	RandomArray();

	//Parameterized RandomArray constructor
	//Purpose: Creates a RandomArray object with given parameters
	//Parameters: a size_t variable, the capacity
	//Returns: None
	RandomArray(size_t);

	//The size() function
	//Purpose: Gives us the size of the array
	//Parameters: None
	//Returns: The size as a size_t
	size_t size() const;

	//The begin() function
	//Purpose: Puts us at the beginning of the array
	//Parameters: None
	//Returns: An int pointer to the beginning of the array
	//Precondition: requires an int*
	int* begin();

	//The begin() function
	//Purpose: Puts us at the beginning of the array
	//Parameters: None
	//Returns: A const int pointer to the beginning of the array
	//Precondition: requires a const int*
	const int* begin() const;

	//The end() function
	//Purpose: Puts us at the end of the array
	//Parameters: None
	//Returns: An int pointer to the end of the array
	//Precondition: requires an int*
	int* end();

	//The end() function
	//Purpose: Puts us at the end of the array
	//Parameters: None
	//Returns: A const int pointer to the end of the array
	//Precondition: requires a const int*
	const int* end() const;

	//The Randomize function
	//Purpose: Fills each item in the array with a random number
	//Parameters: An int, the seed that we want to use for the random function
	//Returns: none
	void Randomize(int);

	//The SortedRandomize funcion
	//Purpose: Fills the array with monotonically increasing random numbers
	//Parameters: The seed that we want to use, as an int
	//Returns: none
	void SortedRandomize(int);

	//Iterator typedefs
	typedef int* iterator;
	typedef const int* const_iterator;
private:
	//Member variables
	size_t capacity;
	int* data;
};