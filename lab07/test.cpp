/*****************************************
Programmer: Steven Tang 004532176
Date: 2/24/2016
Class: CSE 330 Winter 2016 Wednesday Lab
Assignment: test.cpp
Problem:	In this fie I'm going to test if my implemenation for Deque.h works correctly.
Completion: This lab is 70% complete
Time Complexity: O(N)
******************************************/


#include <iostream>
#include <cassert>
//#include <queue>
#include "Deque.h"

using namespace std;

int main()
{
	Deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);

	Deque<int> c;
	c = d;

	Deque<int>::iterator i;
	for (i = c.begin(); i != c.end(); ++i)
		cout << *i << " ";
	cout << endl;
}
