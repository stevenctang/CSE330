/**************************************************
* Name : Steven Tang 004532176
* Date: 2/15/16
* File Name: test.cpp
* Problem: Now we are needed to test our implmentation to see if it's correct.
* Solution: In this file, we are just testing our implementation to see if it's right.
* Time / Space Complexity: Both O(n)
**************************************************/
#include <iostream>
#include <list>
#include <vector>
//#include "../lab04/Vector.h"
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> s;      // uses List as the default container
	s.push(5);
	s.push(6);
	cout << s.top() << endl;

	Stack<double, vector> v; // uses Vector as the container
	v.push(1.5);
	v.push(2.3);
	v.pop();
	cout << v.top() << endl;
}
