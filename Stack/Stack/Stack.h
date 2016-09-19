//Spencer Cheshire
//CS 2420-601
//September 19th, 2016
//Assignment 3 - Stack
//I, Spencer Cheshire, have not used any code other than my own (or that in the textbook) for this project. I
//also have not used any function or data-structure from the Standard-Template Library. I
//understand that any violation of this disclaimer will result in a 0 for the project

// NOTE: This is the Stack from the book. You allowed us to use the stack from the book. This one is from pages
//		370-371.

#include <cstdlib>

template <class Item>
class Stack
{
public:
	//Typedefs and member constants
	typedef std::size_t size_type;
	typedef Item value_type;
	static const size_type CAPACITY = 30;

	//The Stack Constructor
	Stack() { used = 0;}

	//Modifcation Member Functions
	void push(const Item& entry);

	void pop();

	//Constant Member Functions
	bool empty() const {return (used == 0); }

	Item top() const;
private:
	Item data[CAPACITY];
	size_type used;
};