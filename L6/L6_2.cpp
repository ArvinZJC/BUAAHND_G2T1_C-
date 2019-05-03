// L6.pdf, P30, program that decides if the integer entered is a narcissistic number

#include <iostream>
#include <cmath>
using namespace std;

/* Decide if the integer entered is a narcissistic number. */
bool isNarcissisticNumber(int number)
{
	int units, tens, hundreds, total;

	units = number % 10;
	tens = (number / 10) % 10;
	hundreds = (number / 100) % 10;
	total = pow(units, 3) + pow(tens, 3) + pow(hundreds, 3);

	if (total == number)
		return true;
	else
		return false;
} // end function isNarcissisticNumber

int main()
{
	int number;

	cout << "Enter an integer between 100 and 999: ";
	cin >> number;

	// loop until a proper 3-digit integer is entered
	while (number < 100 || number > 999)
	{
		cout << "Error! Please enter again: ";
		cin >> number;
	} // end while

	// call the specified function to decide if the integer entered is a narcissistic number
	if (isNarcissisticNumber(number))
		cout << "\n" << number << " is a narcissistic number." << endl;
	else
		cout << "\n" << number << " is not a narcissistic number." << endl;

	system("Pause");
	return 0;
} // end main