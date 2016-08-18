/*****************************************
Programmer: Steven Tang 004532176
Date: 2/17/2016
Class: CSE 330 Winter 2016
Assignment: homework3.cpp
Problem:	We want to create 4 functions that will put two lists together, one that's intersected and one that's unionized. Also there will be an ordered list for each of them. So I will create a function with ordered union and another function with ordered intersect.
 Solution:  What I did first was work on my main function. I created two lists, and then I created the functions. I first called the unordered functions and then I called SORT to sort my lists before I pass them into the ordered functions. After I called each function, I printed each of them out onto the screen.
Completion: 	This lab is 100% complete
******************************************/
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

// This unordered_union function takes in two lists as a parameter.
// It then takes in one UNORDERED list at a time and puts the contents into another list.
// It Repeats with the second list that is passed through.
template<class T>
list<T> unordered_union( list<T> & a,  list<T> &b)
{
	list<int> new_list;
    list<int>::iterator a_begin = a.begin();
    list<int>::iterator b_begin = b.begin();
    
    while( a_begin != a.end()){
        new_list.push_back(*a_begin); 
        a_begin++;
    }
    while (b_begin != b.end()){
        new_list.push_back(*b_begin); 
        b_begin++;
    }
    return new_list;
}

// This unordered_intersect function takes in two lists as a parameter.
// What is does is that it looks at one list, takes one element, and then looks
// at another list and then takes an element from the other list. This repeats
// until each list is exhausted. This function doesn't put the list in order.
template <class T>
list<T> unordered_intersect(list<T> & a, list<T> &b)
{
	list<int> new_list;
    list<int>::iterator a_begin = a.begin();
    list<int>::iterator b_begin = b.begin();
    
    while( a_begin != a.end() && b_begin != b.end() ){
        new_list.push_back(*a_begin); 
        new_list.push_back(*b_begin);
        a_begin++; 
        b_begin++;
    }
    return new_list;
}

// This ordered_union function takes in two lists as a parameter.
// It then takes in one ORDERED list at a time and puts the contents into the new list.
// It Repeats with the second list that is ORDERED and puts it into the new list.
template<class T>
list<T> ordered_union( const list<T> & a,  const list<T> &b)
{
	list<int> new_list;
    list<int>::const_iterator a_begin = a.begin();
    list<int>::const_iterator b_begin = b.begin();

    while( a_begin != a.end()){
        new_list.push_back(*a_begin); 
        a_begin++;
    }
    while (b_begin != b.end()){
        new_list.push_back(*b_begin); 
        b_begin++;
    }
    return new_list;
}

// This ordered_intersect function takes in two lists as a parameter.
// What is does is that it looks at one list, looks for the LOWEST element and takes it. Then looks
// at another list for the LOWEST element and then takes that element from the other list. This repeats
// until each list is exhausted. This function DOES put the list in order.
template <class T>
list<T> ordered_intersect( const list<T> & a, const list<T> &b)
{
	list<int> new_list;
    list<int>::const_iterator a_begin = a.begin();
    list<int>::const_iterator b_begin = b.begin();
    
 	while( a_begin != a.end() && b_begin != b.end() ){
        if( *a_begin < *b_begin ){
        	new_list.push_back(*a_begin);
        	a_begin++;

        }else if( *a_begin > *b_begin ){
        	new_list.push_back(*b_begin);
        	b_begin++;
        }
        else{
            new_list.push_back(*a_begin); 
            new_list.push_back(*b_begin);
            a_begin++; 
            b_begin++;
        } 
    }
    for ( a_begin = a_begin; a_begin != a.end(); a_begin++ )
      	new_list.push_back(*a_begin);
    for ( b_begin = b_begin; b_begin != b.end(); b_begin++ )
        new_list.push_back(*b_begin);
    return new_list;
}

//All this function does is prints out the contents of the first list
void print_list1(list<int> x)
{
	list<int>::iterator itr;
	cout << "List one: ";
	for ( itr = x.begin(); itr != x.end(); itr++)
		cout << *itr << " ";
	cout << "\n";
}

//All this function does is prints out the contents of the second list
void print_list2(list<int> x)
{
	list<int>::iterator itr;
	cout << "List two: ";
	for ( itr = x.begin(); itr != x.end(); itr++)
		cout << *itr << " ";
	cout<< "\n";
}

//This function takes in the parameters that are the beginning and the end of a list.
//When it takes in the beginning and end of the list, the function then sorts out the
//list by comparing each element. If an element is bigger than the other, it swaps it.
template<class T>
void sort_list(T begin, T end)
{
    T itr;
	T itr2;  
  
 	for(T it = begin; it != end; ++it){
   		itr = it;
    	itr2 = it;
    	++itr2;
    	for( ; itr2 != end; itr2++){
    		if(*itr2 < *itr)
       			itr = itr2;
    	}       
    	swap(*it, *itr);
  	}
}

//Main function that tests my code
int main ()
{
	list<int> list_one;
	list<int> list_two;
	list<int>::iterator itr;

	list_one.push_back(20);
	list_one.push_back(5);
	list_one.push_back(15);
	list_one.push_back(100);

	list_two.push_back(8);
	list_two.push_back(22);
	list_two.push_back(66);
	list_two.push_back(4);
	
	print_list1(list_one);
	print_list2(list_two);
	
	cout << "Unordered union: ";
	list<int> unordered_u = unordered_union(list_one,list_two);
	for (itr = unordered_u.begin(); itr != unordered_u.end(); itr++)
		cout << *itr << " ";
	cout << "\n";

	cout << "Unordered intersect: ";
	list<int> unordered_i = unordered_intersect(list_one,list_two);
	for (itr = unordered_i.begin(); itr != unordered_i.end(); itr++)
		cout << *itr << " ";
	cout << "\n";
	
	sort_list(list_one.begin(), list_one.end());
    sort_list(list_two.begin(), list_two.end());

	cout << "Ordered union: ";
	list<int> ordered_u = ordered_union(list_one,list_two);
	for (itr = ordered_u.begin(); itr != ordered_u.end(); itr++)
		cout << *itr << " ";
	cout << "\n";

	cout << "Ordered intersect: ";
	list<int> ordered_i = ordered_intersect(list_one,list_two);
	for (itr = ordered_i.begin(); itr != ordered_i.end(); itr++)
		cout << *itr << " ";
	cout << "\n";

}//end of main
