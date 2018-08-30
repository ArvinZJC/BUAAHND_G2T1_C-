//2017.12.15, L3.pdf, P48, program that calculate the sum of integers between 1 and 100 except those that are divisible by 5
#include <iostream>
using namespace std;

int main()
{
	int sum = 0;

	for( int num = 1; num <= 100; num++ ) //num is the abbreviation of number
	{
		if( num % 5 != 0 )
			sum += num;
	} //end for

	cout << "The sum of integers between 1 and 100 except those that are divisible by 5: " << sum << endl;

	system( "Pause" );
	return 0;
} //end function main