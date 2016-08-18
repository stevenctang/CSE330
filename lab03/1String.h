/*******************************************************
* Name: Steven Tang 004532176
* Date: Januray 29th, 2016
* Class: CSE 330 Winter 2016
* Program name: String.h
* Lab 3: Strings
* Problem: The problem we are trying to complete in this lab is that we're trying to implement our own string class.
* Solution: How I completed the class for String is that I created the friend objects that we needed. I also created a constructor and deconstructor. As an addition, I looked at the String_test file and implemented all of the other functions that were needed.
* Time Complexity / Storage complexity : Both O(n)
* This program is 100%
*******************************************************/
#ifndef STRING_H
#define STRING_H

// String.h

#include <iostream>

using namespace std;

class String {
        int size;
        char * buffer;
public:
        String();
        String(const String &);
        String(const char *);
        ~String();
        int length() const;
        char& operator[] (unsigned int);
        void operator =(const String&);
        void operator += (const String&);
        void operator * (const String&);
        void operator - (const String&);
        void operator + (const String&);
        
    // other methods

        friend bool operator==(const String &, const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator<(const String &, const String &);
        friend ostream & operator<<(ostream &, const String &);
};

#endif