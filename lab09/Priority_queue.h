/**************************************************************
* Name: Steven Tang 004532176
* Date: 3/9/16
* Class: CSE 330 Winter 2015 Wednesday Lab
* File name: Priority_queue.h
* Problem: In this lab, I am implementing my own Priority Queue class without using the STL.
* Completion: 100% Complete
* Time/space Complexity is Log(N)
***************************************************************/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// Priority_queue.h  -- a priority_queue implemented as a heap

#include <vector>

using namespace std;

template <class T>
class Priority_queue {
public:
	Priority_queue() : c() { }
    Priority_queue(const Priority_queue & p): c(p.c) { }
    Priority_queue & operator=(const Priority_queue & p) { c = p.c; return *this; }
    // vector destructor is automatically called when an obj of type Priority_queue is destroyed

	bool empty() { return c.empty(); }
	unsigned int size() { return c.size(); }
    void push(const T & x);
    void pop();
    T & top() { return c.front(); }
private:
   vector<T> c;
};

template<class Iterator>
void push_heap(Iterator start, Iterator stop)
{
	unsigned int position = (stop - start) -1;
	unsigned int parent = (position - 1)/ 2;

	while(position > 0 && start[position] > start[parent]){
		swap(start[position], start[parent]);
		position = parent;
		parent = (position -1)/2;
	}
}

template<class Iterator>
void make_heap(Iterator start, Iterator stop)
{
	unsigned int heapSize = stop - start;
	for (int i = (heapSize/2)-1; i >= 0; i--)
		adjust_heap(start,heapSize, i);
}

template <class Iterator>
void adjust_heap(Iterator start, unsigned heapsize, unsigned position)
{
    while (position < heapsize) {
    	unsigned int childpos = position * 2 + 1;
    	if (childpos < heapsize) {
    	    if ((childpos + 1 < heapsize) &&
    	    	start[childpos + 1] > start [childpos])
    	    		childpos++;

			if (start[position] > start[childpos])
        		return;
   			else
        		swap (start[position], start[childpos]);
    		}
    	position = childpos;
    	}
}

template<class Iterator>
void pop_heap(Iterator start, Iterator stop)
{
	unsigned int lastPosition = (stop - start) - 1;
	swap (start[0], start[lastPosition]);
	adjust_heap(start,lastPosition,0);
}

template<class Iterator>
void sort_heap(Iterator start, Iterator stop)
{
	unsigned int lastPosition = stop - start - 1;
	while(lastPosition > 0){
		swap(start[0], start[lastPosition]);
		adjust_heap(start,lastPosition,0);
		lastPosition--;
	}
}

template<class Iterator>
void heap_sort(Iterator start, Iterator stop)
{
	make_heap(start,stop);
	sort_heap(start,stop);
}

template<class T>
void Priority_queue<T>:: push(const T & x)
{
    c.push_back(x);
    push_heap(c.begin(),c.end());
}

template<class T>
void Priority_queue<T>::pop()
{
    pop_heap(c.begin(),c.end());
    c.pop_back();
}


#endif
