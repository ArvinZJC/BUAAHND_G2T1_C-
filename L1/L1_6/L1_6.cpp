//2017.12.08, L1.pdf, P84, program that illustrates how to keep the specified number of decimal places
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double x = 7.5876;

	cout.setf( ios::fixed );
	cout << setprecision( 2 ) << x << endl; //keep 2 decimal places

	system( "Pause" );
	return 0;
} //end function main