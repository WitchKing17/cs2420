//Spencer Cheshire
//CS 2420-601
//Assignment 4
//September 26th, 2016
//I, Spencer Cheshire, have not used any code other than my own (or that in the textbook) for this project. I
//also have not used any function or data-structure from the Standard-Template Library. I
//understand that any violation of this disclaimer will result in a 0 for the project

#include "search.h"

RandomArray::RandomArray()
{
	capacity = 0;
	data = nullptr;
}

RandomArray::RandomArray(size_t _cap)
{
	capacity = _cap;
	data = new int[_cap];
}

size_t RandomArray::size() const
{
	return capacity;
}

int* RandomArray::begin()
{
	return iterator(&data[0]);
}

const int* RandomArray::begin() const
{
	return const_iterator(&data[0]);
}

int* RandomArray::end()
{
	return iterator(&data[capacity]);
}

const int* RandomArray::end() const
{
	return const_iterator(&data[capacity]);
}

ostream& operator<<(ostream& out, const RandomArray& rho)
{
	//If the array is empty
	if (rho.size() == 0) {
		out << "{}"; 
	} else if (rho.size() == 1) {
		for (int i = 0; i < rho.size(); i++) {
			out << "{" << rho.data[i] << "}"; //If the array has just one item, print that one item.
		}
	} else {
		out << "{";

		for (int i = 0; i < rho.size(); i++) {
			if (i != rho.size() - 1) {
				out << rho.data[i] << ",";
			} else
				out << rho.data[i]; 
		}

		out << "}";
	}

	return out;
}

void RandomArray::Randomize(int n)
{
	srand(n);

	for (int i = 0; i < capacity; i++) {
		int num = (rand() % capacity) + 1;

		data[i] = num;
	}
}

void RandomArray::SortedRandomize(int n)
{
	srand(n);

	for (int i = 0; i < capacity; i++) {
		if (i == 0)
			data[i] = rand() % n;
		else 
			data[i] = data[i -1] + (rand() % n);
	}
}