//Spencer Cheshire
//CS 2420-601
//Assignment 4
//September 26th, 2016
//I, Spencer Cheshire, have not used any code other than my own (or that in the textbook) for this project. I
//also have not used any function or data-structure from the Standard-Template Library. I
//understand that any violation of this disclaimer will result in a 0 for the project

// These are the tests for the search assignment.
// To practice Test Driven Development, all but one of the tests are commented out.
// First write the code necessary to get this test passing.
// Then move the '#if 0' line down to uncomment the next test case.
// Do not make any other modifications to the tests.
// After you have all the tests passing, write your benchmarks and call them
// from the main function.
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <string>
#include <chrono>
#include <gtest\gtest.h>
#include "search.h"

using namespace std;

//The LinearSearch function
//Purpose: Performs a Linear Search on an array
//Parameters: The Array we are searching, the size of the array, and the item we are searching for
//Returns: A pointer to the item we searched for, if it exists in the array. Otherwise, it will return
//		nullptr
int* LinearSearch(int*, int, int);

//The RecursiveBinarySearch function
//Purpose: Performs a recursive binary search on an array
//Parameters: The array we are searching, the size of the array, and the item we are searching for
//Returns: A pointer to the item we searched for, it if exists in the array. otherwise, it will return
//		nullptr
int* RecursiveBinarySearch(int*, int, int);

//The IterativeBinarySearch function
//Purpose: Performs an iterative binary search on an array (the fastest type of search)
//Parameters: The array we are searching, the size of the array, and the item we are searching for
//Returns: A pointer to the item we searched for, if it exists in the array. Otherwise, it will return
//		nullptr;
int* IterativeBinarySearch(int*, int, int);

//main method
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int test_result = RUN_ALL_TESTS();
  
  // Insert your benchmarks here after the tests pass.

  //These are the 3 arrays we will use, all of three different sizes
  int a[1000];
  int b[10000];
  int c[100000];

  //Add items into the first array.
  for (int i = 0; i < 1000; i++) {
	int num = (rand() % 1000) + 1; 
	a[i] = num;
  }

  //Add items into the second array.
  for (int i = 0; i < 10000; i++) {
	int num = (rand() % 10000) + 1;
	b[i] = num;
  }

  //Add items into the third array.
  for (int i = 0; i < 100000; i++) {
	int num = (rand() % 100000) + 1;
	c[i] = num;
  }

  //We will use these numbers when searching in our functions.
  int aNum = (rand() % 1000) + 1;
  int bNum = (rand() % 10000) + 1;
  int cNum = (rand() % 100000) + 1;

  //Lines 83 - 159 are the lines that do the actual calculations for our arrays.
  //	***NOTE: I know we were supposed to calculate the time in nanoseconds, but I kept getting an error that I 
  //		didn't know how to get rid of when I would do that conversion. I would add these lines:
  //			seconds /= <num of iterations>;
  //			cout << chrono::duration_cast<chrono::nanoseconds>(seconds).count() << " nanoseconds." << endl;
  //	
  //		THIS is the error i would get:
  //			'cannot convert from '_CR' to 'std::chrono::nanoseconds''
  //		I'm not sure why it gave me that error, but I couldn't get rid of it so I just did seconds.
  chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000; i++) {
	LinearSearch(a, 1000, aNum);
  }
  chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
  chrono::duration<double> seconds = chrono::duration_cast<chrono::duration<double> >(t2 - t1);

  chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 100000; i++) {
	RecursiveBinarySearch(a, 1000, aNum);	
  }
  chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsTwo = chrono::duration_cast<chrono::duration<double> >(t4 - t3);

  chrono::high_resolution_clock::time_point t5 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 100000; i++) {
	IterativeBinarySearch(a, 1000, aNum);	
  }
  chrono::high_resolution_clock::time_point t6 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsThree = chrono::duration_cast<chrono::duration<double> >(t6 - t5);

  cout << "\n1,000 items:" << endl;
  cout << "\tLinearSearch: " << seconds.count() << " seconds, 1,000 iterations" << endl;
  cout << "\tRecursiveBinarySearch: " << secondsTwo.count() << " seconds, 100,000 iterations" << endl;
  cout << "\tIterativeBinarySearch: " << secondsThree.count() << " seconds, 100,000 iterations" << endl;

  chrono::high_resolution_clock::time_point t7 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10000; i++) {
	LinearSearch(b, 10000, bNum);
  }
  chrono::high_resolution_clock::time_point t8 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsFour = chrono::duration_cast<chrono::duration<double> >(t8 - t7);

  chrono::high_resolution_clock::time_point t9 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000000; i++) {
	RecursiveBinarySearch(b, 10000, bNum);	
  }
  chrono::high_resolution_clock::time_point t10 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsFive = chrono::duration_cast<chrono::duration<double> >(t10 - t9);

  chrono::high_resolution_clock::time_point t11 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000000; i++) {
	IterativeBinarySearch(b, 10000, bNum);	
  }
  chrono::high_resolution_clock::time_point t12 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsSix = chrono::duration_cast<chrono::duration<double> >(t12 - t11);

  cout << "\n10,000 items:" << endl;
  cout << "\tLinearSearch: " << secondsFour.count() << " seconds, 10,000 iterations" << endl;
  cout << "\tRecursiveBinarySearch: " << secondsFive.count() << " seconds, 1,000,000 iterations" << endl;
  cout << "\tIterativeBinarySearch: " << secondsSix.count() << " seconds, 1,000,000 iterations" << endl;

  chrono::high_resolution_clock::time_point t13= chrono::high_resolution_clock::now();
  for (int i = 0; i < 100000; i++) {
	LinearSearch(c, 100000, cNum);
  }
  chrono::high_resolution_clock::time_point t14 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsSeven = chrono::duration_cast<chrono::duration<double> >(t14 - t13);

  chrono::high_resolution_clock::time_point t15 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10000000; i++) {
	RecursiveBinarySearch(c, 100000, cNum);	
  }
  chrono::high_resolution_clock::time_point t16 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsEight = chrono::duration_cast<chrono::duration<double> >(t16 - t15);

  chrono::high_resolution_clock::time_point t17 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10000000; i++) {
	IterativeBinarySearch(c, 100000, cNum);	
  }
  chrono::high_resolution_clock::time_point t18 = chrono::high_resolution_clock::now();
  chrono::duration<double> secondsNine = chrono::duration_cast<chrono::duration<double> >(t18 - t17);

  cout << "\n100,000 items:" << endl;
  cout << "\tLinearSearch: " << secondsSeven.count() << " seconds, 100,000 iterations" << endl;
  cout << "\tRecursiveBinarySearch: " << secondsEight.count() << " seconds, 10,000,000 iterations" << endl;
  cout << "\tIterativeBinarySearch: " << secondsNine.count() << " seconds, 10,000,000 iterations" << endl;

  system("PAUSE");
  return test_result;
}

// BEGIN TEST CASES //
TEST(RandomArray, Trivial) {
  // There should be a constructor taking a size_t capacity parameter.
  size_t capacity = 7;
  RandomArray r(capacity);
}

TEST(RandomArray, SizeConst) {
  // There should be a const size() method returning the capacity.
  size_t capacity = 7;
  RandomArray r(capacity);
  const RandomArray *const_r = &r;
  EXPECT_EQ(capacity, const_r->size());
}

TEST(RandomArray, Size9) {
  // Test that size works with a different size array.
  size_t capacity = 9;
  RandomArray r(capacity);
  const RandomArray *const_r = &r;
  EXPECT_EQ(capacity, const_r->size());
}

TEST(RandomArray, Begin) {
  // The begin method should allow access to the array.
  RandomArray r(5);
  int *data = r.begin();
  for (int i = 0; i < 5; ++i) {
    data[i] = i;
  }
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(i, data[i]);
  }
}

TEST(RandomArray, Begin91) {
  // Test begin with another size array.
  RandomArray r(91);
  int *data = r.begin();
  for (int i = 0; i < 91; ++i) {
    data[i] = i * 7 - 3;
  }
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(i * 7 - 3, data[i]);
  }
}

TEST(RandomArray, End) {
  // There should be a end method.
  RandomArray r(17);
  int *b = r.begin();
  int *e = r.end();
  EXPECT_EQ(b + 17, e);
}

TEST(RandomArray, End14) {
  // Test end with another size array.
  RandomArray r(14);
  int *b = r.begin();
  int *e = r.end();
  EXPECT_EQ(b + 14, e);
}

TEST(RandomArray, IteratorTypedef) {
  // There should be an iterator typedef, which begin and end return.
  RandomArray r(7);
  for (RandomArray::iterator it = r.begin(); it != r.end(); ++it) {
    *it = 89;
    EXPECT_EQ(89, *it);
  }
}

TEST(RandomArray, ConstBegin) {
  // There should also be a const begin method.
  // (Make sure you return a const int*)
  RandomArray r(10);
  int *data = r.begin();
  const RandomArray *cr = &r;
  const int *cdata = cr->begin();
  EXPECT_EQ(const_cast<const int *>(data), cdata);
}

TEST(RandomArray, ConstEnd) {
  // There should also be a const end method.
  // (Make sure you return a const int*)
  RandomArray r(10);
  int *end = r.end();
  const RandomArray *cr = &r;
  const int *cend = cr->end();
  EXPECT_EQ(const_cast<const int *>(end), cend);
}

TEST(RandomArray, ConstIterator) {
  // There should be a const_iterator typedef, which begin and end return.
  RandomArray r(7);
  for (int i = 0; i < 7; ++i) {
    r.begin()[i] = 4;
  }
  const RandomArray *cr = &r;
  for (RandomArray::const_iterator it = cr->begin(); it != cr->end(); ++it) {
    EXPECT_EQ(4, *it);
  }
}

// Stringify is a helper function that converts an array to a string
// using the << operator.
string Stringify(const RandomArray &r) {
  ostringstream s;
  s << r;
  return s.str();
}

TEST(RandomArray, StringOutputEmpty) {
  // There should be an friend operator<< function, which works on empty
  // arrays.
  RandomArray r(0);
  EXPECT_EQ("{}", Stringify(r));
}

TEST(RandomArray, StringOutputOneItem) {
  RandomArray r(1);
  *r.begin() = 17;
  EXPECT_EQ("{17}", Stringify(r));
  *r.begin() = 12;
  EXPECT_EQ("{12}", Stringify(r));
}

TEST(RandomArray, StringOutputMultipleItems) {
  RandomArray r(10);
  int *data = r.begin();
  for (int i = 0; i < 10; ++i) {
    data[i] = i;
  }
  EXPECT_EQ("{0,1,2,3,4,5,6,7,8,9}", Stringify(r));
  for (int i = 0; i < 10; ++i) {
    data[i] = i - 3;
  }
  EXPECT_EQ("{-3,-2,-1,0,1,2,3,4,5,6}", Stringify(r));
}

TEST(RandomArray, Randomize) {
  // The Randomize method should fill the array with random numbers
  // from 0 to the size of the array (inclusive).
  // Use the rand() function from <cstdlib>
  // http://www.cplusplus.com/reference/cstdlib/rand/
  RandomArray r(20);
  r.Randomize(0);
  for (RandomArray::const_iterator it = r.begin(); it != r.end(); ++it) {
    EXPECT_LE(0, *it);
    EXPECT_GE(20, *it);
  }
}

// SameContents compares two arrays and formats them for gtest.
// a and b must have the same size.
testing::AssertionResult SameContents(const RandomArray &a,
                                      const RandomArray &b) {
  if (a.size() != b.size()) {
    ADD_FAILURE() << "Different sizes: " << a.size() << ", " << b.size();
    return testing::AssertionFailure();
  }
  int differences = 0;
  for (RandomArray::const_iterator ait = a.begin(), bit = b.begin();
       ait != a.end(); ++ait, ++bit) {
    if (*ait != *bit) {
      ++differences;
    }
  }
  if (differences == 0) {
    return testing::AssertionSuccess() << a << " == " << b;
  } else {
    return testing::AssertionFailure() << a << " != " << b;
  }
}

TEST(RandomArray, RandomizeWithDifferentSeeds) {
  // Running with different seeds should produce different arrays.
  // Use the srand() function from <cstdlib>
  // http://www.cplusplus.com/reference/cstdlib/srand/
  RandomArray a(7);
  RandomArray b(7);

  a.Randomize(10);
  b.Randomize(20);

  EXPECT_FALSE(SameContents(a, b));
}

TEST(RandomArray, RandomizeWithSameSeeds) {
  // Running with the same seed should produce the same array.

  RandomArray a(8);
  RandomArray b(8);

  a.Randomize(19);
  b.Randomize(19);
  EXPECT_TRUE(SameContents(a, b));
}

TEST(RandomArray, Randomize0) {
  // Make sure we can randomize a zero-length array.
  RandomArray r(0);
  r.Randomize(5);
}

TEST(RandomArray, Randomize1) {
  // Make sure we can randomize a 1 item array.
  RandomArray r(1);
  r.Randomize(5);
}

// Sorted returns true if r is sorted, and formats r for gtest.
testing::AssertionResult Sorted(const RandomArray &r) {
  if (r.size() == 0) {
    return testing::AssertionSuccess();
  }
  RandomArray::const_iterator it = r.begin();
  int first = *it;
  int last = first;
  bool different = false;
  for (++it; it != r.end(); ++it) {
    if (*it != first) {
      different = true;
    }
    if (last > *it) {
      return testing::AssertionFailure() << r;
    }
    last = *it;
  }
  if (!different && r.size() > 1) {
    return testing::AssertionFailure() << "only one value in " << r;
  }
  return testing::AssertionSuccess();
}

TEST(RandomArray, SortedRandomize) {
  // The SortedRandomize method should fill the array with monotonically
  // increasing
  // random numbers. Do not sort, just add a random number to the previous item:
  // Array[0] = rand() % 5; Array[n] = Array[n-1]+(rand()%5)
  RandomArray r(12);
  r.SortedRandomize(5);
  EXPECT_TRUE(Sorted(r));
}

TEST(RandomArray, SortedRandomizeWithDifferentSeeds) {
  // Running with different seeds should produce different arrays.
  RandomArray a(7);
  RandomArray b(7);

  a.SortedRandomize(10);
  EXPECT_TRUE(Sorted(a));
  b.SortedRandomize(20);
  EXPECT_TRUE(Sorted(b));

  EXPECT_FALSE(SameContents(a, b));
}

TEST(RandomArray, SortedRandomizeWithSameSeeds) {
  // Running with the same seed should produce the same array.

  RandomArray a(6);
  RandomArray b(6);

  a.SortedRandomize(19);
  EXPECT_TRUE(Sorted(a));
  b.SortedRandomize(19);
  EXPECT_TRUE(Sorted(b));
  EXPECT_TRUE(SameContents(a, b));
}

TEST(RandomArray, SortedRandomize0) {
  // Make sure we can randomize a zero-length array.
  RandomArray r(0);
  r.Randomize(5);
  EXPECT_TRUE(Sorted(r));
}

TEST(RandomArray, SortedRandomize1) {
  // Make sure we can randomize a 1 item array.
  RandomArray r(1);
  r.SortedRandomize(5);
  EXPECT_TRUE(Sorted(r));
}

TEST(LinearSearch, EmptyArray) {
  // The LinearSearch function should return nullptr if size is 0.
  EXPECT_EQ(nullptr, LinearSearch(nullptr, 0, 7));
}

TEST(LinearSearch, ElementExists) {
  // LinearSearch should return a pointer to the item if it exists in the array.
  int a[1] = {7};
  EXPECT_EQ(a, LinearSearch(a, 1, 7));
}

TEST(LinearSearch, ElementDoesntExist) {
  // LinearSearch should return null if the item isn't in the array.
  int a[1] = {16};
  EXPECT_EQ(nullptr, LinearSearch(a, 1, 7));
}

TEST(LinearSearch, ElementExists2Items) {
  // LinearSearch should return a pointer to the item if it exists in the array.
  int a[2] = {7, 2};
  EXPECT_EQ(a, LinearSearch(a, 2, 7));
  EXPECT_EQ(a + 1, LinearSearch(a, 2, 2));
}

TEST(LinearSearch, ElementDoesntExist2Items) {
  // LinearSearch should return null if the item isn't in the array.
  int a[2] = {16, 5};
  EXPECT_EQ(nullptr, LinearSearch(a, 2, 2));
}

TEST(LinearSearch, ElementExists5Items) {
  // LinearSearch should return a pointer to the item if it exists in the array.
  int a[5] = {7, 5, 9, 6, 4};
  EXPECT_EQ(a, LinearSearch(a, 5, 7));
  EXPECT_EQ(a + 1, LinearSearch(a, 5, 5));
  EXPECT_EQ(a + 2, LinearSearch(a, 5, 9));
  EXPECT_EQ(a + 3, LinearSearch(a, 5, 6));
  EXPECT_EQ(a + 4, LinearSearch(a, 5, 4));
}

TEST(LinearSearch, ElementDoesntExist5Items) {
  // LinearSearch should return null if the item isn't in the array.
  int a[5] = {7, 2, 9, 3, 4};
  EXPECT_EQ(nullptr, LinearSearch(a, 5, 17));
  EXPECT_EQ(nullptr, LinearSearch(a, 5, 0));
  EXPECT_EQ(nullptr, LinearSearch(a, 5, 1));
  EXPECT_EQ(nullptr, LinearSearch(a, 5, 5));
  EXPECT_EQ(nullptr, LinearSearch(a, 5, 6));
}

TEST(LinearSearch, RandomArray) {
  // Test linear search with a randomized array
  RandomArray r(50);
  r.Randomize(5);
  EXPECT_EQ(nullptr, LinearSearch(r.begin(), r.size(), 51));
  bool found[50];
  for (int i = 0; i < 50; ++i) {
    found[i] = false;
  }
  for (RandomArray::const_iterator it = r.begin(); it != r.end(); ++it) {
    if (found[*it]) {
      continue;
    }
    found[*it] = true;
    EXPECT_EQ(it, LinearSearch(r.begin(), r.size(), *it));
  }
}

TEST(LinearSearch, SortedRandomArray) {
  // Test linear search with a randomized array
  RandomArray r(50);
  r.SortedRandomize(5);
  int last = r.begin()[49];
  EXPECT_EQ(nullptr, LinearSearch(r.begin(), r.size(), last + 1));
  for (RandomArray::const_iterator it = r.begin(); it != r.end(); ++it) {
    if (*it == last)
      continue;
    last = *it;
    EXPECT_EQ(it, LinearSearch(r.begin(), r.size(), *it));
  }
}
TEST(RecursiveBinarySearch, EmptyArray) {
  // The RecursiveBinarySearch function should return nullptr if size is 0.
  EXPECT_EQ(nullptr, RecursiveBinarySearch(nullptr, 0, 7));
}

TEST(RecursiveBinarySearch, ElementExists) {
  // RecursiveBinarySearch should return a pointer to the item if it exists in
  // the array.
  int a[1] = {7};
  EXPECT_EQ(a, RecursiveBinarySearch(a, 1, 7));
}

TEST(RecursiveBinarySearch, ElementDoesntExist) {
  // RecursiveBinarySearch should return null if the item isn't in the array.
  int a[1] = {16};
  EXPECT_EQ(nullptr, RecursiveBinarySearch(a, 1, 7));
}

TEST(RecursiveBinarySearch, ElementExists2Items) {
  // RecursiveBinarySearch should return a pointer to the item if it exists in
  // the array.
  int a[2] = {7, 22};
  EXPECT_EQ(a, RecursiveBinarySearch(a, 2, 7));
  EXPECT_EQ(a + 1, RecursiveBinarySearch(a, 2, 22));
}

TEST(RecursiveBinarySearch, ElementDoesntExist2Items) {
  // RecursiveBinarySearch should return null if the item isn't in the array.
  int a[2] = {16, 55};
  EXPECT_EQ(nullptr, RecursiveBinarySearch(a, 2, 2));
}

TEST(RecursiveBinarySearch, ElementExists5Items) {
  // RecursiveBinarySearch should return a pointer to the item if it exists in
  // the array.
  int a[5] = {7, 15, 19, 26, 41};
  EXPECT_EQ(a, RecursiveBinarySearch(a, 5, 7));
  EXPECT_EQ(a + 1, RecursiveBinarySearch(a, 5, 15));
  EXPECT_EQ(a + 2, RecursiveBinarySearch(a, 5, 19));
  EXPECT_EQ(a + 3, RecursiveBinarySearch(a, 5, 26));
  EXPECT_EQ(a + 4, RecursiveBinarySearch(a, 5, 41));
}

TEST(RecursiveBinarySearch, ElementDoesntExist5Items) {
  // RecursiveBinarySearch should return null if the item isn't in the array.
  int a[5] = {7, 12, 19, 23, 24};
  EXPECT_EQ(nullptr, RecursiveBinarySearch(a, 5, 17));
  EXPECT_EQ(nullptr, RecursiveBinarySearch(a, 5, 0));
  EXPECT_EQ(nullptr, RecursiveBinarySearch(a, 5, 1));
  EXPECT_EQ(nullptr, RecursiveBinarySearch(a, 5, 5));
  EXPECT_EQ(nullptr, RecursiveBinarySearch(a, 5, 6));
}

TEST(RecursiveBinarySearch, SortedRandomArray) {
  // Test binary search with a randomized sorted array
  RandomArray r(50);
  r.SortedRandomize(5);
  int last = r.begin()[49];
  EXPECT_EQ(nullptr, RecursiveBinarySearch(r.begin(), r.size(), last + 1));
  for (RandomArray::const_iterator it = r.begin(); it != r.end(); ++it) {
    if (*it == last)
      continue;
    last = *it;
    const int *found = RecursiveBinarySearch(r.begin(), r.size(), *it);
    ASSERT_NE(nullptr, found);
	EXPECT_LE(it, found);
    EXPECT_EQ(*it, *found);
    EXPECT_LE(found, r.end());
  }
}

TEST(IterativeBinarySearch, EmptyArray) {
  // The IterativeBinarySearch function should return nullptr if size is 0.
  EXPECT_EQ(nullptr, IterativeBinarySearch(nullptr, 0, 7));
}

TEST(IterativeBinarySearch, ElementExists) {
  // IterativeBinarySearch should return a pointer to the item if it exists in
  // the array.
  int a[1] = {7};
  EXPECT_EQ(a, IterativeBinarySearch(a, 1, 7));
}

TEST(IterativeBinarySearch, ElementDoesntExist) {
  // IterativeBinarySearch should return null if the item isn't in the array.
  int a[1] = {16};
  EXPECT_EQ(nullptr, IterativeBinarySearch(a, 1, 7));
}

TEST(IterativeBinarySearch, ElementExists2Items) {
  // IterativeBinarySearch should return a pointer to the item if it exists in
  // the array.
  int a[2] = {7, 12};
  EXPECT_EQ(a, IterativeBinarySearch(a, 2, 7));
  EXPECT_EQ(a + 1, IterativeBinarySearch(a, 2, 12));
}

TEST(IterativeBinarySearch, ElementDoesntExist2Items) {
  // IterativeBinarySearch should return null if the item isn't in the array.
  int a[2] = {16, 5};
  EXPECT_EQ(nullptr, IterativeBinarySearch(a, 2, 2));
}

TEST(IterativeBinarySearch, ElementExists5Items) {
  // IterativeBinarySearch should return a pointer to the item if it exists in
  // the array.
  int a[5] = {7, 15, 19, 26, 34};
  EXPECT_EQ(a, IterativeBinarySearch(a, 5, 7));
  EXPECT_EQ(a + 1, IterativeBinarySearch(a, 5, 15));
  EXPECT_EQ(a + 2, IterativeBinarySearch(a, 5, 19));
  EXPECT_EQ(a + 3, IterativeBinarySearch(a, 5, 26));
  EXPECT_EQ(a + 4, IterativeBinarySearch(a, 5, 34));
}

TEST(IterativeBinarySearch, ElementDoesntExist5Items) {
  // IterativeBinarySearch should return null if the item isn't in the array.
  int a[5] = {7, 12, 19, 23, 24};
  EXPECT_EQ(nullptr, IterativeBinarySearch(a, 5, 17));
  EXPECT_EQ(nullptr, IterativeBinarySearch(a, 5, 0));
  EXPECT_EQ(nullptr, IterativeBinarySearch(a, 5, 1));
  EXPECT_EQ(nullptr, IterativeBinarySearch(a, 5, 5));
  EXPECT_EQ(nullptr, IterativeBinarySearch(a, 5, 6));
}

TEST(IterativeBinarySearch, SortedRandomArray) {
  // Test binary search with a randomized sorted array
  RandomArray r(50);
  r.SortedRandomize(5);
  int last = r.begin()[49];
  EXPECT_EQ(nullptr, IterativeBinarySearch(r.begin(), r.size(), last + 1));
  for (RandomArray::const_iterator it = r.begin(); it != r.end(); ++it) {
    if (*it == last)
      continue;
    last = *it;
    const int *found = RecursiveBinarySearch(r.begin(), r.size(), *it);
    ASSERT_NE(nullptr, found);
    EXPECT_LE(it, found);
    EXPECT_EQ(*it, *found);
    EXPECT_LE(found, r.end());
  }
}

//Linear Search
int* LinearSearch(int* theArray, int size, int key) {
	//If the array doesn't have anything in it
	if (size == 0)
		return nullptr; 

	//Loop through each item in the array one by one until we find the item we're looking for.
	//	Once we find the item, return it
	for (int i = 0; i < size; i++) {
		if (key == theArray[i]) 
			return (theArray + i);
	}

	//If we don't find the item we're looking for, return nullptr
	return nullptr;
}

//RecursiveBinarySearch
int* RecursiveBinarySearch(int* theArray, int size, int key) {
	//If the array doesn't have anything in it
	if (size == 0)
		return nullptr;

	//We need to keep track of the middle of the array so we can have the two 'halves' to search through
	//	if we don't find it right away. The 'middle' variable keeps track of that.
	int middle = size/2;

	if (key == theArray[middle]) { //Base case: if we find the item we're looking for, return it
		return (theArray + middle);
	} else if (key > theArray[middle]) { //If the item is greater than what we found, search the upper array
		return RecursiveBinarySearch(&theArray[middle], size/2, key);
	} else if (key < theArray[middle]) { //If the item is less than what we found, search the lower array
		return RecursiveBinarySearch(theArray, size/2, key);
	}

	//If there's nothing, return nullptr
	return nullptr;
}

//IterativeBinarySearch
int* IterativeBinarySearch(int* theArray, int size, int key) {
	//We need to keep track of the beginning and the end. These variables take care of that.
	int end = size - 1;
	int start = 0;

	//While start is less than or equal to end
	while (start <= end) {
		//Keep track of the middle variable.
		int mid = start + (end - start) / 2;

		if (key < theArray[mid]) //If the item is less than what we found, search the lower array. Do this by 
			end = mid - 1;       //		changing where the end of the array is.
		else if (key > theArray[mid]) //If the item is greater than what we found, search the upper array. Do this
			start = mid + 1;		  //	changing the location of the start
		else 
			return (theArray + mid); //Base case: We find what we're looking for and return it
	}

	//If there's nothing, return nullptr
	return nullptr;
}