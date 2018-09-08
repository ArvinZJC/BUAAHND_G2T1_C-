//2017.12.08, L1.pdf, P78-80, program using some fuctions in the <cmath> header file to finish some calculations

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a = -678, b = 20;
	double c = -123.987, d = 2.3;

	cout << "The absolute value of -678: " << fabs( a ) << "\n"
		 << "The absolute value of -123.987: " << fabs( c ) << "\n"
	     //abs() and fabs() are functions that return the absolute values of parameters and they are nearly the same in C++
		 << "20 ^ 2.3 = " << pow( b, d ) << "\n"
	     //pow() is a function that returns base raised to the power exponent
		 << "¡Ì 20 = " << sqrt( b ) << endl;
	     //sqrt() is a function that returns the square root of a parameter

	system( "Pause" );
	return 0;
} //end main