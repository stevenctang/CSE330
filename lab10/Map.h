/*****************************************
Programmer: Steven Tang 004532176
Date: 3/16/2016
Class: CSE 330 Winter 2016 Wednesday Lab
Assignment: Map.h
Problem: In this lab I am to implement my own Map.h implementation using binary search trees. I'm using my own Set implementation as well.
Completion: Map.h is completely done but my test_map.cpp and test.cpp comes out with a Segmentation fault: 11.
Completion: 80%.
Time Complexity: O(n)
******************************************/
#ifndef MAP_H
#define MAP_H

// Map.h
//#include<set>
#include "../lab08/Set.h"
#include "Pair.h"

using namespace std;

template < class key, class value >
class Map : public Set < Pair < key, value > >
{
public:
    typedef Set < Pair < key, value > > parent;
    typedef Set_iterator < Pair < key, value > > iterator;
    Map(): parent() {}

    iterator find(const key & k) { return parent::find(Pair<key,value>(k,value()));}
    value & operator[](const key & k){iterator it = parent::insert(Pair<key,value> (k,value()));
    	return (*it).second;}
    void erase(const key & k){parent::erase(Pair<key,value>(k,value()));}
};

#endif
