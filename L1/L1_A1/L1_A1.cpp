//2017.12.09, L1_A.pdf, Assignment 1, calculations with 3 known numbers x, y and z
#include <iostream>
#include <cmath>
using namespace std;

 int main()
{
	int x = 312, z = 58;
	double y = 657.87, sum, AVG, formula; //AVG is the abbreviation of average

	cout << "If x = 312, y = 657.87, z = 58, then:" << endl;

	sum = x + y + z; //calculate the sum
	AVG = round( sum / 3 ); //calculate the rounding average
	formula = sqrt( abs( ( y * 56.7 + z ) / pow( x, z ) ) );
	/* calcualte the value of the formula "¡Ì ( y * 56.7 + z / x ^ z )";
	   the function abs() is used to satisfy the requirement of ensuring "y * 56.7 + z / x ^ z ¡Ý 0";
	   the value of "formula" is 0 due to loss of accuracy if being declared as a variable of type float */

	cout << "1) the sum is " << sum << "\n"
	     << "2) the rounding average is " << AVG << "\n"
		 << "3) the value of the formula \"¡Ì ( y * 56.7 + z / x ^ z )\" is " << formula << endl;

	system( "Pause" );
	return 0;
} //end function main