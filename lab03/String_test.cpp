/*******************************************************
* Name: Steven Tang 004532176
* Date: Januray 29th, 2016
* Class: CSE 330 Winter 2016
* Program name: String_test.cpp
* Lab 3: Strings
* Problem: We want to test out whether our string class works or not.
* Solution: To solve this solution we just wrote assert codes to test our code. If one assert doesn't work our program crashes.
* Time Complexity / Storage complexity Both O(n)
* This program is 100%
********************************************************/

#include <iostream>
#include <cassert> // To test all of our code
#include "zString.h"

using namespace std;

int main()
{
   String s1; // s1 == ""
   assert(s1.length() == 0);

   String s2("hi");  // s2 == "hi"
   assert(s2.length() == 2);

   String s3(s2);  // s3 == "hi"
   assert(s3.length() == 2);
   assert(s3[0] == 'h');
   assert(s3[1] == 'i');

   s1 = s2;  // s1 == "hi"
   assert(s1 == s2);

   s3 = "bye";  // s3 == "bye"
   assert(s3.length() == 3);
   assert(s3[0] == 'b');
   assert(s3[1] == 'y');
   assert(s3[2] == 'e');
   
   s1 += "re";  // s1 == "hire"
   assert(s1 == "hire");

   s1 += "d"; // s1 == "hired"
   assert(not (s1 == "hire"));

   cout << "SUCCESS" << endl;
}