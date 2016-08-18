/**************************************************************
* Name: Steven Tang 004532176
* Date: 3/9/16
* Class: CSE 330 Winter 2015 Wednesday Lab
* File name: Priority_queue.cpp
* Problem: In this file, I'm testing to see if my priority queue class implementation is correct, if there was something wrong and my assert function turns out to be false, the program will crash.
* Completion: 100% complete
* Time/space Complexity is Log(N)
***************************************************************/
#include <iostream>
#include <cassert>

#include "Priority_queue.h"

using namespace std;

int main()
{
   Priority_queue<int> pq;

   assert(pq.size() == 0);
   assert(pq.empty());

   pq.push(10);
   assert(pq.top() == 10);

   pq.push(20);
   assert(pq.top() == 20);

   pq.push(30);
   assert(pq.top() == 30);

   pq.push(40);
   assert(pq.top() == 40);

   pq.push(50);
   assert(pq.top() == 50);

   pq.push(5);
   assert(pq.top() == 50);

   pq.pop();
   assert(pq.top() == 40);

   pq.pop();
   assert(pq.top() == 30);

   pq.pop();
   assert(pq.top() == 20);

   pq.pop();
   assert(pq.top() == 10);

   pq.pop();
   assert(pq.top() == 5);

   pq.pop();
   assert(pq.size() == 0);

   Priority_queue<int> pq2;
   pq2.push(30);
   pq2.push(11);
   pq2.push(7);
   pq2.pop();
   assert(pq2.top() == 11);
   pq2.pop();
   assert(pq2.top() == 7);
   pq2.pop();
   assert(pq2.empty());

   cout << "All tests passed." << endl;
}
