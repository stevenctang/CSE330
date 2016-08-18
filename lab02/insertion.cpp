/*****************************************************************
 * Steven Tang 004532176
 * January 20, 2016
 * Wednesday Lab 1:30 - 3:20 
 * insertion.cpp
 * Problem: The problem that we are trying to solve is that we want to know if the time algorithm for selection sort, bubble sort, and insertion sort is O(n^2). To do that, we must create a program to test out each of the algorithms. 
 * Solution: How I solved this problem was by making a simple program that generated a random number up to 1000000. I then used the time command in the command prompt to track how long each of the programs took to finish running. I used the table provided, and if all Cs were the same, it was O(n^2).
 * The time complexity is O(n^2) and the storage complexity is O(1)
 * This program is 100%!
 * **************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// This function takes an item in the array/vector then grabs the smallest item and puts it in the beginning of the array/vector if its the smallest. After it repeats until it reaches teh end
void insertion( vector<int> &v )
{
    int i,j,elem,n;
    n = v.size();
    for ( i = 1; i < n; i++){
        for ( elem = v[i],j= i-1; j>=0 && elem < v[j]; j--)
            v[j+1] = v[j];
        v[j+1] = elem; 
    }   
}

// main runs the program, has a vector and a random number generator
int main()
{
    int n;
    srand(time(0));
    cin >> n;
    vector <int> v(n);
    for ( int i = 0; i <n; i++)
        v[i] = rand()%1000000;
    insertion(v);
    for (int i = 0; i <v.size(); i++)
        cout << v[i] << endl;
}//main