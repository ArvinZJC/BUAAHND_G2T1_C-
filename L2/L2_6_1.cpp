/* program that gets the max of 3 numbers entered;
   my 1st method */

#include <iostream>
using namespace std;

int main()
{
	double number1, number2, number3, temp, max;

	cout << "Enter 3 numberbers each separated by a space: ";
	cin >> number1 >> number2 >> number3;

	temp = (number1 > number2) ? number1 : number2; // assign the max of "number1" and "number2" to "temp"
	max = (number3 > temp) ? number3 : temp; // assign the max of "number3" and "temp" to "max"

	cout << "The max: " << max << endl;

	return 0;
} // end main