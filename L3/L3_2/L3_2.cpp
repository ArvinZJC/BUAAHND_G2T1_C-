//2017.12.15, L3.pdf, P25, program that determines if the year entered is a leap year

#include <iostream>
using namespace std;

int main()
{
	int Year;
	bool isLeapYear;

	cout << "Enter the year: ";
	cin >> Year;
	cout << endl;

	isLeapYear = ( Year % 4 == 0 && Year % 100 != 0 ) || ( Year % 400 == 0 ); //years which are multiples of 4 with the exception of years divisible by 100 but not by 400 are leap years

	if( isLeapYear )
		cout << Year << " is a leap year." << endl;
	else
		cout << Year << " is not a leap year." << endl;

	system( "Pause" );
	return 0;
} //end main