/***********************************************************************
Programmer:		Steven Tang 004532176
Class: 			CSE 330
date: 			2/5/16
Problem:		I am needed to test out my code that I've implemented in my string class.
Solution:		I just used the default constructor to construct a string, then I added/substracted letters from            that string to test my code out.
Completion:		60% Finished, I implemented the + operator, a bit of the - operator, but not the * operator. Operator - only subtracts # of letters.
************************************************************************/
#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String s1("Pillow");
	s1 + "abc";
	cout << s1 << endl;
	String s2("Pokemon");
	s2 - "mon";
	cout << s2 << endl;
	String s3("abc");
	//s3*3;
	cout << s3 << endl;
}