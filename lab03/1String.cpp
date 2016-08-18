/*******************************************************
* Name: Steven Tang 004532176
* Date: Januray 29th, 2016
* Class: CSE 330 Winter 2016
* Program name: String.cpp
* Lab 3: Strings
* Problem: The problem we are trying to complete in this lab is that we're trying to implement our own string class.
* Solution: How I completed the implementation of this lab is that I basically just wrote out each function that was in my class. Most of the operator classes has the same function so it was used over again.
* Time Complexity / Storage complexity Both O(n)
* This program is 100%
*******************************************************/

#include "String.h"
#include <cassert> // to test out i < size

String::String()
{
    buffer = 0;
    size = 0;
}

String::String(const String &s)
{ 
    size = s.size;
    buffer = new char[size];
    for(int i = 0; i < size; i++)
        buffer[i] = s.buffer[i];
}

String::String(const char *p)
{
	size = strlen(p);
	buffer = new char[size];

	for (int i = 0; i < size; i++)
			buffer[i] = p[i];
}

String::~String()
{
    delete[] buffer;
    size = 0;
}

int String::length() const
{
    return size;
}

char & String::operator[] (const unsigned int i)
{
    assert( i < size );
    return buffer[i];
}


void String::operator = (const String & s)
{
	delete[] buffer;
    size = s.size;
    buffer = new char[size];
    for(int i = 0; i < size;i++)
        buffer[i] = s.buffer[i];
}

/*void String::operator * ( const String & left )
{
    char * temp = new char[size];
    int l = length();

    for(int i = 0; i < length(); i++)
        temp[i] = buffer[i];

    int lsize = size + left.size;
    buffer = new char[lsize];

    for(int i = 0; i < length(); i++)
        buffer[i] = temp[i];
    
    for(int i = l, j = 0; j < left.length(); i++,j++)
       buffer[i] = left.buffer[j];
 
    size = size * left.size;
    delete [] temp;
}*/

void String::operator - (const String& left )
{
    char * temp = new char[size];
    int l = length();

    for(int i = 0; i < length(); i++)
        temp[i] = buffer[i];

    int lsize = size + left.size;
    /*buffer = new char[lsize];

    for(int i = 0; i < length(); i++)
        buffer[i] = temp[i];
    
    for(int i = l, j = 0; j < left.length(); i++,j++)
       buffer[i] = left.buffer[j];*/
 
    size = size - left.size;
    delete [] temp;
    
}

void String::operator + (const String& left)
{
    char * temp = new char[size];
    int l = length();

    for(int i = 0; i < length(); i++)
        temp[i] = buffer[i];

    int lsize = size + left.size;
    buffer = new char[lsize];

    for(int i = 0; i < length(); i++)
        buffer[i] = temp[i];
    
    for(int i = l, j = 0; j < left.length(); i++,j++)
       buffer[i] = left.buffer[j];
 
    size = size+ left.size;
    delete [] temp;
}

void String::operator += (const String& left)
{
    char * temp = new char[size];
    int l = length();

    for(int i = 0; i < length(); i++)
        temp[i] = buffer[i];

    int lsize = size + left.size;
    buffer = new char[lsize];

    for(int i = 0; i < length(); i++)
        buffer[i] = temp[i];
    
    for(int i = l, j = 0; j < left.length(); i++,j++)
       buffer[i] = left.buffer[j];
 
    size+=left.size;
    delete [] temp;

}

bool operator<=(const String & left, const String & right)
{
   int i, j;
    for ( i = 0, j =0; j < left.size and j<right.size; i++, j++)
        if ( left.buffer[i] <= right.buffer[j])
            return false;
    if (i < left.size and j <= right.size)
        return true;
    return false;
}

bool operator<(const String & left, const String & right)
{
    int i, j;
    for ( i = 0, j =0; j < left.size and j<right.size; i++, j++)
        if ( left.buffer[i] < right.buffer[j])
            return false;
    if (i < left.size and j < right.size)
        return true;
    return false;
}

bool operator == (const String & left, const String & right)
{
	int i,j;
	for ( i = 0, j = 0; i < left.length() and j < right.length(); i++,j++){
		if (left.buffer[i] != right.buffer[j])
			return false;
	}
	if ( i == left.length() and j == right.length())
		return true;
	return false;

}


ostream & operator<<(ostream &os, const String & left)
{
    for(int i = 0; i < left.size; i++)
        os << left.buffer[i];

    return os;

}

