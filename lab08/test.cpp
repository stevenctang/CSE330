/*****************************************
Programmer: Steven Tang 004532176
Date: 3/6/2016
Class: CSE 330 Winter 2016 Wednesday Lab
Assignment: test.cpp
Problem:In this file I'm trying testing to see if my implementation of my set class is correct.
Completion: 80% Done.
Time Complexity: O(n)
******************************************/

// test.cpp

#include <iostream>
#include <cassert>

#include "Set.h"

using namespace std;

int main()
{
   Set<int> s;

   s.insert(10);
   s.insert(7);
   s.insert(6);
   s.insert(9);
   s.insert(8);
   s.insert(11);

   Set<int>::iterator i = s.find(7);
   s.erase(i);

   for (i = s.begin(); i != s.end(); i++)
	cout << *i << endl;

   cout << "All tests passed." << endl;
}
