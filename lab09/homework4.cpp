/**************************************************************
* Name: Steven Tang 004532176
* Date: 3/18/16
* Class: CSE 330 Winter 2015
* File name: homework4.cpp
* Problem: In this homework assignment, I have to sort 2 files using heapsort. One file is for integers and another is for strings. In my main cpp file, I am needed to input them into a container, I chose vectors, and then I am needed to sort them by calling Heapsort.
* Completion: 100% complete
* Time complexity of Heapsort is O(n log(n))
***************************************************************/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<class T>
void adjust_heap(T start, unsigned heapSize, unsigned position)
{
	while(position < heapSize){
		unsigned int childpos = position * 2 + 1;
		if(childpos < heapSize){
			if((childpos + 1 < heapSize) && start[childpos + 1] > start[childpos])
				childpos++;
			if (start[position] > start[childpos])
				return;
			else
				swap(start[position], start[childpos]);
		}
	position = childpos;
	}
}

template<class T>
void heap_sort(T start, T stop)
{
    unsigned int heapSize = stop - start;
    for (int i = (heapSize/2)-1; i >= 0; i--)
        adjust_heap(start,heapSize, i);

    unsigned int lastPosition = stop - start -1;
	while (lastPosition > 0) {
		swap(start[0],start[lastPosition]);
		adjust_heap(start,lastPosition,0);
		lastPosition--;
	}
}

int main()
{
	int i,x,j;
	string words;
	vector<int> a;
	vector<string> b;
    fstream numbers;
	fstream strings;

    numbers.open("test_numbers.txt");
    if(numbers.fail()){
        cout << "Failed to open the numbers file" << endl;
        return 0;
	}
	while(numbers >> x)
		a.push_back(x);

	strings.open("test_strings.txt");
	if(strings.fail()){
		cout << "Failed to open the string file" << endl;
		return 0;
	}
	while(strings >> words)
		b.push_back(words);

    vector<int>::iterator it1 = a.begin();
    vector<int>::iterator it2 = a.end();
	cout << "\n" << "Sorted integer vector is : " << endl;
	heap_sort(it1,it2);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";

    vector<string>::iterator it3 = b.begin();
    vector<string>::iterator it4 = b.end();
	cout << "\n" << "Sorted string vector is : " << endl;
    heap_sort(it3,it4);
    for (j = 0; j < b.size(); j++)
        cout<< b[j] << " ";
	cout << "\n";

	strings.close();
    numbers.close();
}// end of main
