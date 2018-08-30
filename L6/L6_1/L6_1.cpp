//2017.12.26, L6.pdf, P29, program that displays all the narcissistic numbers
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num, tot; //num and tot are respectively the abbreviations of number and total

	cout << "All the narcissistic numbers: ";

	for( int hundreds = 1; hundreds <= 9; hundreds++ )
		for( int tens = 0; tens <= 9; tens++ )
			for( int units = 0; units <= 9; units++ )
			{
				num = hundreds * 100 + tens * 10 + units;
				tot = pow( hundreds, 3 ) + pow( tens, 3 ) + pow( units, 3 );

				if( tot == num )
					cout << num << "  ";
			} //end for

	cout << endl;
	
	system( "Pause" );
	return 0;
} //end function main