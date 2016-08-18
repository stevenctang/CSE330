/**************************************************************
* Name: Steven Tang 004532176
* Date: 3/9/16
* Class: CSE 330 Winter 2015 Wednesday Lab
* File name: test.cpp
* Problem: In this file, I'm testing to see if my priority queue class implementation is correct.
* Completion: 100%
* Time/space Complexity is Log(N)
***************************************************************/

#include <iostream>
#include <cassert>

#include "Priority_queue.h"

using namespace std;

int main()
{
   Priority_queue<int> p, q, pq;

   int x;
   while (cin >> x)
	p.push(x);

   pq = q = p;

   while (!pq.empty()) {
	cout << pq.top() << " ";
	pq.pop();
   }
   cout << endl;
}
