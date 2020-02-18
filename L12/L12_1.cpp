// program that includes a programmer-declared header file containing struct

#include "Sample.h"
#include <iostream>
using namespace std;

int main()
{
	Sample sample1; // create a Sample object and assign it to "sample1"
	
	sample1.number1 = 1;
	sample1.number2 = 3;

	cout << "number1 = " << sample1.number1
		 << "\nnumber2 = " << sample1.number2
		 << "\nnumber1 + number2 = " << sample1.Add() // call the specified function in struct Sample to add the 2 integers
		 << "\nnumber1 ÷ number2 = ";

	sample1.Division(); // call the specified method in struct Sample to output the result of dividing the first integer by the second integer with 2 decimal places kept

	return 0;
} // end main