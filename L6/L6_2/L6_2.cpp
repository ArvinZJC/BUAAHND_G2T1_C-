//2017.12.26, L6.pdf, P30, program that decides if the integer entered is a narcissistic number
#include <iostream>
#include <cmath>
using namespace std;

bool isNarcissisticNum( int num ) //num is the abbreviation of number
{
	int units, tens, hundreds, tot; //tot is the abbreviation of total

	units = num % 10;
	tens = ( num / 10 ) % 10;
	hundreds = ( num / 100 ) % 10;
	tot = pow( units, 3 ) + pow( tens, 3 ) + pow( hundreds, 3 );

	if( tot == num )
		return true;
	else
		return false;
} //end function isNarcissisticNum

int main()
{
	int num;

	cout << "Enter an integer between 100 and 999: ";
	cin >> num;

	while( num < 100 || num > 999 ) //loop until a proper 3-digit integer is entered
	{
		cout << "Error! Please enter again: ";
		cin >> num;
	} //end while

	if( isNarcissisticNum( num ) ) //call the specified function to decide if the integer entered is a narcissistic number
		cout << "\n" << num << " is a narcissistic number." << endl;
	else
		cout << "\n" << num << " is not a narcissistic number." << endl;

	system( "Pause" );
	return 0;
} //end function main