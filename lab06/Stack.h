/**************************************************
* Name : Steven Tang 004532176
* Date: 2/15/16
* File Name: Stack.h
* Problem: In this lab I am trying to implement my own Stack class that will be used by any other stl container. What I am asked to do in this file is to just implement all of the given funtions.
* Solution: What I did was basically implement the functions in this class that was given. It was straight forward because we were using the classes that we implemented before, this was just an adapter for other containers.p
* Time / Space Complexity: Both O(n)
**************************************************/
#ifndef STACK_H
#define STACK_H

// Stack.h  -- a stack implemented as an adapter (of vector or list or ...)

//#include "../lab05/List.h"
#include <list>

using namespace std;

//Use the following line for STL containers.
template <class T, template < class C,class = allocator<C> > class Container = list>
//template <class T, template <class T> class Container = list>

class Stack
{
public:
   //We don't need a constructor or destructor because the Container has/should have one
   //Stack(): container() { }
   //~Stack() { ~container(); }
   bool empty() const { return container.empty();}
   unsigned int size() const { return container.size(); }
   void push(const T & x) { container.push_back(x); }
   void pop() { container.pop_back(); }
   T & top() { return container.back(); }

private:
   Container<T> container;
};

#endif
