/**************************************************
* Name : Steven Tang 004532176
* Date: 2/15/16
* File Name: Stack_test.cpp
* Problem: Now we are needed to test our implmentation in the Stack.H to see if it's correct.
* Solution: In this file, we are just testing our implementation to see if it's right. This code was given from Professor Z.
* Completion: 100%
* Time / Space Complexity: Both O(n)
**************************************************/
#include <iostream>
#include <cassert>
#include "Stack.h"
#include "../lab03/String.h"
#include <vector>
#include <list>

using namespace std;

int main()
{
   Stack<int, vector> s1;
   assert(s1.size() == 0);
   assert(s1.empty());

   s1.push(16);
   assert(s1.size() == 1);
   assert(s1.top() == 16);

   s1.pop();
   assert(s1.size() == 0);

   s1.push(11);
   assert(s1.size() == 1);
   assert(s1.top() == 11);

   s1.push(22);
   assert(s1.size() == 2);
   assert(s1.top() == 22);

   s1.push(33);
   assert(s1.size() == 3);
   assert(s1.top() == 33);

   s1.pop();
   assert(s1.size() == 2);
   assert(s1.top() == 22);

   Stack<String, list> s2;
   s2.push("abc");
   s2.push("de");
   s2.pop();
   assert(s2.top() == "abc");

   cout << "SUCCESS\n";
}