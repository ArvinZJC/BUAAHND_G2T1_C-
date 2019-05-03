// header file as a sample to practise using struct and a programmer-declared header file

#ifndef SAMPLE_H
#define SAMPLE_H
#include <iostream>
#include <iomanip>
using namespace std;

struct Sample
{
	int number1, number2;
	
	/* Add the 2 integers. */
	int Add()
	{
		return number1 + number2;
	} // end function Add

	/* Output the result of dividing the first number by the second number with 2 decimal places kept. */
	void Division()
	{
		if (number2 != 0)
			cout << setiosflags(ios::fixed) << setprecision(2) << (double)number1 / number2 << endl; // keep 2 decimal places
		else
			cout << "Cannot be divided by 0!" << endl;
	} // end function Division
}; // end struct Sample
#endif