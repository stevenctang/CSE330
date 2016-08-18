/*****************************************
Programmer: Steven Tang 004532176
Date: 2/24/2016
Class: CSE 330 Winter 2016 Wednesday Lab
Assignment: Deque.h
Problem: In this lab, I'm trying to implement my own Deque class using two vectors. 
Completion: This lab is 70% complete. I didn't implement my void insert(const iterator &, const T &) and void erase(const iterator &, const iterator &); in my deque class. Also, I believe that in my DequeItertator class, my iterator operator=(const iterator & r); is incorrect.
******************************************/

#ifndef DEQUE_H
#define DEQUE_H
#include <iterator>
#include <vector>

using namespace std;

template <class T> class DequeIterator;

template<class T>
class Deque {
public:
	typedef DequeIterator<T> iterator;
	typedef T value_type;
	Deque(): vecOne(), vecTwo() { }
	Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
	Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }
    ~Deque() { } // destructors for vecOne and vecTwo are automatically called
                     // never call a destructor explicitly
    Deque & operator=(const Deque<T> & d);

	T & operator[](unsigned int);
	T & front();
	T & back();
	bool empty();
	iterator begin();
	iterator end();
	void erase(const iterator &);
	void erase(const iterator &, const iterator &);
	void insert(const iterator &, const T &);
	int size();
	void push_front(const T & value);
	void push_back(const T & value);
	void pop_front();
	void pop_back();
protected:
	vector<T> vecOne;
	vector<T> vecTwo;
};
// IMPLEMENATION OF DEQUE STARTS HERE
template <class T>
T & Deque<T>::operator[] (unsigned int x)
{
	int n = vecOne.size();
	
	if (x < n) // means that it must be in vector one
		return vecOne[(n-1) - x];
	else
		return vecTwo[x-n];
}

template <class T>
T & Deque<T>:: front()
{
	if(vecOne.empty())
		return vecTwo.front();
	else
		return vecOne.back();
}

template <class T>
T & Deque<T>:: back()
{
	if(vecOne.empty())
		return vecTwo.back();
	else
		return vecOne.front();
}

template<class T>
bool Deque<T>::empty()
{
	return vecOne.size + vecTwo.size() == 0;
}

template<class T>
typename Deque<T>::iterator Deque<T>:: begin()
{
	return iterator(this, 0);
}

template<class T>
typename Deque<T>::iterator Deque<T>:: end()
{
	return iterator(this, size());
}

template<class T>
void Deque<T>:: erase(const iterator & itr)
{
	int index = itr.index;
	int n = vecOne.size();
	if (index < n)
		vecOne.erase(vecOne.begin() + ((n-1)-index));
	else
		vecTwo.erase(vecTwo.begin() + (index-n));
}

template<class T>
void Deque<T>:: erase(const iterator &, const iterator &)
{

}

template<class T>
void Deque<T>:: insert(const iterator & l, const T & r)
{
	//vecOne.insrt(l,r);
}

template<class T>
int Deque<T>:: size()
{
	return vecOne.size();
	return vecTwo.size();
}

template<class T>
void Deque<T>::push_front(const T & value)
{
	vecOne.push_back(value);
}

template<class T>
void Deque<T>::push_back(const T & value)
{
	vecTwo.push_back(value);
}

template<class T>
void Deque<T>::pop_front()
{
	if (vecOne.empty())
		vecTwo.erase(vecTwo.begin());
	else
		vecOne.pop_back();
}

template<class T>
void Deque<T>::pop_back()
{
	if(vecTwo.empty())
		vecOne.pop_back();
	else
		vecTwo.pop_back();
}
//End of implementation of Deque
template <class T>
class DequeIterator {

	friend class Deque<T>;
	typedef DequeIterator<T> iterator;

public:
	DequeIterator(): theDeque(0), index(0) { }
	DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
	DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

	T & operator*();
	iterator & operator++();
	iterator operator++(int);
	iterator & operator--();
	iterator operator--(int);
	bool operator==(const iterator & r);
	bool operator!=(const iterator & r);
	bool operator<(const iterator & r);
	T & operator[](unsigned int i);
	iterator operator=(const iterator & r);
	iterator operator+(int i);
	iterator operator-(int i);
protected:
	Deque<T> * theDeque;
	int index;
};

template <class T>
T & DequeIterator<T>:: operator *()
{
	return (*theDeque)[index];
}
template<class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator++()
{
	++index;
	return *this;
}

template<class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator++(int)
{
	DequeIterator<T> clone(*this);
	index++;
	return clone;
}

template<class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator--()
{
	--index;
	return *this;
}

template<class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator--(int)
{
	DequeIterator<T> clone(*this);
	index--;
	return clone;	
}

template<class T>
bool DequeIterator<T>::operator ==(const iterator & r)
{
	return theDeque == r.theDeque && index == r.index;
		
}

template<class T>
bool DequeIterator<T>::operator !=(const iterator & r)
{
	if ( theDeque != r.theDeque || index != r.index)
		return true;
	return false;
}

template<class T>
bool DequeIterator<T>::operator <(const iterator & r)
{
	return theDeque == r.theDeque && index < r.index;
}
template<class T>
T & DequeIterator<T>::operator [](unsigned int i)
{
	return index;	
}

template<class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator =(const iterator & r)
{
	theDeque = r.theDeque; 
	index = r.index;
	return *this;
}

template<class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator +(int i)
{
	return iterator(theDeque, index + i);
}

template<class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator -(int i)
{
	return iterator(theDeque, index - i);
}
#endif