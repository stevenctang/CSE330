/***********************************************************************
K Zemoudeh
4/7/08
String.cpp

Implementation of constructors and member functions defined in String.h.

Modified by:	Steven Tang
date: 			2/5/16
Modification:	Original program had basic operations for the String class such as +=, = etc. In this homework, I added the operators +, - , and *. The + operator will add the additional letters to the original string. The - operator will remove the letters and the * letter will multiply the string out.
Completion:		60% Finished, I implemented the + operator, a bit of the - operator, but not the * operator. Operator - only subtracts # of letters.
************************************************************************/

#include <cassert>

#include "String.h"

// default constructor
String::String()
{
	size = 0;
	buffer = 0;
}

// constructor from char string to String
// find the size of p first, allocate space for it, assign p to buffer
String::String(const char * p)
{
	int p_size = 0;
	for (const char *q = p; *q; q++)
		p_size++;
	buffer = new char[p_size];

	for (int i = 0; i < p_size; i++)
		buffer[i] = p[i];

	size = p_size;
}

// copy constructor
String::String(const String & source)
{
	size = source.size;
	buffer = new char[size];
	for (int i = 0; i < size; i++)
		buffer[i] = source.buffer[i];
}

String::~String()
{
	delete [] buffer;
}

int String::length()
{
	return size;
}

// array index operator
char & String::operator[](const int i)
{
	assert(i < size);
	return buffer[i];
}

String String::operator+=(const String & source)
{
	int temp_size = size + source.size;
	char * temp;
	temp = new char[temp_size];
	int i;
	for (i = 0; i < size; i++)
		temp[i] = buffer[i];
	for (int j = 0; j < source.size; j++, i++)
		temp[i] = source.buffer[j];
	delete [] buffer;
	size = temp_size;
	buffer = temp;
	return *this;
}

// assignment operator
// similar to char string constructor, delete the old buffer, 
// create a new buffer and size based on source
String String::operator=(const String & source)
{
    delete [] buffer;
    size = source.size;
    buffer = new char[size];
    
    int i;
    for (i = 0; i < size; i++)
        buffer[i] = source.buffer[i];
    
    return *this;
}

bool operator==(const String & left, const String & right)
{
    int i, j;
    for (i = 0, j = 0; i < left.size and j < right.size; i++, j++)
        if (left.buffer[i] != right.buffer[j])
            return false;
    if (i == left.size and j == right.size)
        return true;
    return false;
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
	if (left <= right and !(left == right))
		return true;
	return false;
}

ostream & operator<<(ostream & out, const String & s)
{
	for (int i = 0; i < s.size; i++)
		out << s.buffer[i];
	return out;
}

/*
	Modifications starts here!
	*
	*
	*

*/
String String::operator * ( const String & left )
{
	char * temp = new char[size];
    int l = length();

    for(int i = 0; i < length(); i++)
        temp[i] = buffer[i];

    int lsize = size + left.size;
    buffer = new char[lsize];

    for(int i = 0; i < length(); i++)
        buffer[i] = temp[i];
    
    for(int i = l, j = 0; j < left.size; i++,j++)
       buffer[i] = left.buffer[j];
 
    size = size+ left.size;
    return temp;
    delete [] temp;

}

String String::operator - (const String& left )
{
    char * temp = new char[size];
    int l = length();

    for(int i = 0; i < length(); i++)
        temp[i] = buffer[i];

    int lsize = size + left.size;
     
    size = size - left.size;
    return temp;
    delete [] temp;
    
}

String String::operator + (const String& left)
{
    char * temp = new char[size];
    int l = length();

    for(int i = 0; i < length(); i++)
        temp[i] = buffer[i];

    int lsize = size + left.size;
    buffer = new char[lsize];

    for(int i = 0; i < length(); i++)
        buffer[i] = temp[i];
    
    for(int i = l, j = 0; j < left.size; i++,j++)
       buffer[i] = left.buffer[j];
 
    size = size+ left.size;
    return temp;
    delete [] temp;
}