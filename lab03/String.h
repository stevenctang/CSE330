/***********************************************************************
K Zemoudeh
4/7/08
String.cpp

Implementation of constructors and member functions defined in String.h.

Modified by:    Steven Tang
date:           2/5/16
Modification:   Original program had basic operations for the String class such as +=, = etc. In this homework, I added the operators +, - , and *. The + operator will add the additional letters to the original string. The - operator will remove the letters and the * letter will multiply the string out.
************************************************************************/
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
    int length();
    char& operator[] (const int i);
    String operator =(const String&);
    String operator += (const String&);
    
    // MODIFCATION STARTS HERE
    String operator * (const String&);
    String operator - (const String&);
    String operator + (const String&);
    // MODIFICATION ENDS HERE
    
    
	// other methods

    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);
};

#endif