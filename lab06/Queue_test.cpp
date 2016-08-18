/**************************************************
* Name : Steven Tang 004532176
* Date: 2/15/16
* File Name: Queue_test.cpp
* Problem: Now we are needed to test our QUEUE implmentation to see if it's correct. It's very similar to the stack test.
* Completion : 100%
* Time / Space Complexity: Both O(1)
**************************************************/
#include <iostream>
#include <cassert>
#include "Queue.h"
#include "../lab03/String.h"
#include <vector>
#include <list>

using namespace std;

int main()
{
   Stack<int, vector> s1;
   assert(s1.size() == 0);
   assert(s1.empty());

   s1.push(19);
   assert(s1.size() == 1);
   assert(s1.front() == 19);

   s1.push(41);
   assert(s1.size() == 2);
   assert(s1.front() == 19);
   assert(s1.back() == 41);

   s1.pop();
   assert(s1.front() == 19);
   assert(s1.size()==1);

   cout << "SUCCESS\n";
}