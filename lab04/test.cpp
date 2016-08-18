/**************************************************
* Name : Steven Tang 004532176
* Date: 2/5/16
* File Name: Test.cpp
* Problem: In this lab we're trying to implement our own vector class. We must define functions very similar to the string class implementation. Also, we would need to do something where we can take in any data type we want because vectors can take in double, integers or even strings. In this file, we're testing if my implementation is correct.
* Solution: I basically just copied what was given in the lab. I use this code to test out if my implemenation is correct by using assert functions. If the assert doesn't return true, the program will crash. If it does return true, then the program will continue to run until we reach the end, which will output "SUCCESS".
* Time / Space Complexity: O(n)
**************************************************/
#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{  
	Vector<int> v;

	v.reserve(2);
	assert(v.capacity() == 2);
	 
	Vector<string> v1(2);
	assert(v1.capacity() == 2);
	assert(v1.size() == 2);
	assert(v1[0] == "");
	assert(v1[1] == "");
		
	v1[0] = "hi";
	assert(v1[0] == "hi");

		
	Vector<int> v2(2, 7);
	assert(v2[1] == 7);

	Vector<int> v10(v2);
	assert(v10[1] == 7);
	
	Vector<string> v3(2, "hello");
	assert(v3.size() == 2);
	assert(v3.capacity() == 2);
	assert(v3[0] == "hello");
	assert(v3[1] == "hello");

	v3.resize(1);
	assert(v3.size() == 1);
	assert(v3[0] == "hello");

	Vector<string> v4 = v3;
	assert(v4.size() == 1);
	assert(v4[0] == v3[0]);
	v3[0] = "test";
	assert(v4[0] != v3[0]);  // fails when assignment results in shallow copy
	assert(v4[0] == "hello");

	v3.pop_back();
	assert(v3.size() == 0); 

	Vector<int> v5(7, 9);
	Vector<int>::iterator it = v5.begin();
	while (it != v5.end()){
		assert(*it == 9);
		++it;
	}

	Vector<int> v6;
	v6.push_back(100);
	assert(v6.size() == 1);
	assert(v6[0] == 100);
	v6.push_back(101);
	assert(v6.size() == 2);
	assert(v6[0] == 100);
	v6.push_back(101);

	cout << "SUCCESS\n";
	
} // End of main

