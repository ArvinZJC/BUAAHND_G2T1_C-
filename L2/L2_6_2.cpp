/* program that gets the max of 3 numbers entered;
   my 2nd method */

#include <iostream>
using namespace std;

int main()
{
	double number1, number2, number3, max;

	cout << "Enter 3 numbers each separated by a space: ";
	cin >> number1 >> number2 >> number3;

	max = number1; // assume that the value of the variable "number1" is the largest to start
	
	if (number2 > max) // determine whether the value of the variable "number2" is larger than that of the variable "max"
		max = number2;

	if (number3 > max) // determine whether the value of the variable "number3" is larger than that of the variable "max"
		max = number3;

	cout << "The max: " << max << endl;

	system("Pause");
	return 0;
} // end main