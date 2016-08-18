/*****************************************************
 * Name : Steven Tang 004532176
 * Date: Januray 28th, 2016
 * Class: CSE 330 Winter 2016
 * Assignment: homework1.cpp
 * Problem: This assignment is asking us to create floating type array. With this array, we're going to find the Variance and Average of it.
 * Solution: So how I went about this problem first is by making constructing my main. I knew what I basically needed, an array and while loop so the user can insert numbers until they are done. After I created the functions average and variance. I created average first because I needed it for the variance function. After that, I just called the functions in main. I did make some precautions if the user entered no numbers,1 number, or a set of numbers over 100. The reason why I chose over 100 is because we only have 100 spaces for float numbers!
 * Time Complexity = O(n^2) , Space Complexity O(n)
 * This program is 100%!
 ******************************************************/
#include <iostream>
#include <cmath>

using namespace std;


//This function find the average(mean) of a set of numbers. It adds all the numbers up in the array and divides them by the total number of items in the array.
double average ( float arr[], int size )
{
    double sum,avg;
    int n = size;
   
    for ( int i=0; i < n; i++)
        sum += arr[i];

    avg = sum/size;
    return avg;
}


//The function variance takes the array of numbers, subtracts it by the mean and is squared. After it goes through the whole array, the variance is then divides by the number of items subtracted by 1. It is the average of the squared differences from the mean.
double variance ( float arr[] ,int size )
{
    double mean = average(arr,size-1);
    double var = 0;
    int n = size-1;

    for ( int i = 0; i < n; i++)
        var += pow(arr[i] - mean,2); 
   
	 return var /= n-1;
    
}

//This is just the main function.
int main() 
{
    const int size = 100;
    int count = 0;
    float myArray[size];
    cout << "Enter your numbers to put in the array" << endl;

    while(cin!='\0'){
        for (int i = 0; i < size; i++){
            cin >> myArray[i];
            ++count;

        if(cin == '\0')
            break;
        }
    }

	cout << "\n";
	if(count-1 == 0 || count-1 == 1){
		cout << "Error! There is nothing to calculate." << endl;
		return 0;
    } else if ( count > 100) {
		cout << "Error! Your set of numbers exceeds the limit!" << endl;
		return 0;
	} else 
		cout << "This is your average: "  << average(myArray, count - 1) << endl;
    	cout << "This is your variance: " << variance(myArray,count) << endl;
    
}
