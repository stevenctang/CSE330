/**************************************************
* Name : Steven Tang 004532176
* Date: 2/15/16
* File Name: Queue.h
* Problem: In this lab I am trying to implement my own Queue class that will be used by any other stl container. What I am asked to do in this file is to just implement all of the given funtions.
* Solution: What I did was basically implement the functions in this class that was given. It was straight forward because we were using the classes that we implemented, this was just an adapter. Also, Queue is known for first in first out process.
* Completion: 100%
* Time / Space Complexity: Both O(n)
**************************************************/
#ifndef QUEUE_H
#define QUEUE_H


#include <list>

using namespace std;

template <class T, template < class C,class = allocator<C> > class Container = list>
class Stack
{
public:
	T & front() { return container.front();}
	T & back() { return container.back(); }
    bool empty() const { return container.empty();}
    unsigned int size() const { return container.size(); }
    void push(const T & x) { container.push_back(x); }
    void pop() { container.pop_back(); }
   

private:
   Container<T> container;
};

#endif
