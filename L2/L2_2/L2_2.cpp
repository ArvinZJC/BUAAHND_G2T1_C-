//2017.12.12, L2.pdf, P62, program that uses conditional operator (?:)
#include <iostream>
using namespace std;

int main()
{
	int num1, num2 = 100, num3 = 200; //num is the abbreviation of number

	num1 = ( num2 < num3 ) ? num2 : num3;
	/* assign the max of "num2" and "num3" to "num1";
	   conditional operator (?:) is C++¡¯s only ternary operator (operator that takes three operands);
	   "?:" can be used in place of an if...else statement */

	cout << num1 << endl;

	system( "Pause" );
	return 0;
} //end function main