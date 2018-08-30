//2017.12.15, L3.pdf, P25, program that determines if the year entered is a leap year
#include <iostream>
using namespace std;

int main()
{
	int YR; //YR is the abbreviation of year
	bool isLeapYR;

	cout << "Enter the year: ";
	cin >> YR;
	cout << endl;

	isLeapYR = ( YR % 4 == 0 && YR % 100 != 0 ) || ( YR % 400 == 0 );
	//years which are multiples of 4 with the exception of years divisible by 100 but not by 400 are leap years

	if( isLeapYR )
		cout << YR << " is a leap year." << endl;
	else
		cout << YR << " is not a leap year." << endl;

	system( "Pause" );
	return 0;
} //end function main