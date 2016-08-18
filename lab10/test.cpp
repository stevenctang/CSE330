/*****************************************
Programmer: Steven Tang 004532176
Date: 3/16/2016
Class: CSE 330 Winter 2016 Wednesday Lab
Assignment: test.cpp
Problem: In this lab I am to implement my own Map.h implementation using binary search trees. I'm using my own Set implementation as well.
Completion: Map.h is completely done but my test_map.cpp and test.cpp comes out with a Segmentation fault: 11.
Completion: 80%.
Time Complexity: O(n)
******************************************/
#include <iostream>
#include <cassert>

#include "Map.h"

using namespace std;

int main()
{
   Map<double, long> counts;

   counts[2.1] = 5;
   counts[-4] = 2;
   counts[.35] = 3;
   counts[-4] = 7;
   cout << counts[2.1] << " " << counts[-4] << " " << counts[.35] << endl;
}
