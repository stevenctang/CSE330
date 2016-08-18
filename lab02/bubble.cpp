/*****************************************************************
 * Steven Tang 004532176
 * January 20, 2016
 * Wednesday Lab 1:30 - 3:20 
 * bubble.cpp
 * Problem: The problem that we are trying to solve is that we want to know if the time algorithm for selection sort, bubble sort, and insertion sort is O(n^2). To do that, we must create a program to test out each of the algorithms. 
 * Solution: How I solved this problem was by making a simple program that generated a random number up to 1000000. I then used the time command in the command prompt to track how long each of the programs took to finish running. I used the table provided, and if all Cs were the same, it was O(n^2).
 * The time complexity is O(n^2) and the storage complexity is O(1)
 * This program is 100%!
 * **************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


//This function sorts out the vector or array so that they're in order. It compares each pair of items and swaps them if it isn't in order.
void bubble(vector<int> &v)
{
    int i, j, n;
    n = v.size();
    for (i = n-1; i > 0; i--)
        for (j = 0; j < i; j++) 
            if (v[j] > v[j+1])
                swap (v[j],v[j+1]);
}

// main runs the program, has a vector and a random number generator
int main()
{
    int n;
    srand(time(0));
    cin >> n;
    vector <int > v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand()%1000000;
    bubble(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

}//main
