/**************************************************
 * Name : Steven Tang 004532176
 * Date: 2/15/16
 * Class: CSE 330 Winter 2016
 * File Name: test.cpp
 * Problem: In this file I'm going to test my List.h file. This code was given to me from Professor Z.
 * Completion: 70%, some functions are missing and I kept on getting an error ./List.h:161:83: error: member reference base type 'List_iterator<T> *' is not a structure or union. I did not know what this meant so I could not really finish the lab.
 * Time / Space Complexity: Both O(n)
 **************************************************/
#include <iostream>
#include "List.h"

using namespace std;

int main()
{
   List<int> l;

   l.push_back(44);  // list = 44
   l.push_back(33);  // list = 44, 33
   l.push_back(11);  // list = 44, 33, 11
   l.push_back(22);  // list = 44, 33, 11, 22

   List<int> m(l);

   List<int>::iterator itr(m.begin());
   while (itr != m.end()) {
        cout << *itr << endl;
        itr++;
   }
}
