//2017.12.12, L2.pdf, P83, program that generates some random numbers

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand( time( NULL ) );

	cout << "2 random integers between 0 and 10:\n"
		 << "  " << rand() % 11 << "\t" << rand() % 11 << "\n"
		 << "2 random integers between 11 and 20:\n"
		 << "  " << 11 + rand() % 10 << "\t" << 11 + rand() % 10 << "\n"
		 << "2 random integers between 21 and 40:\n"
		 << "  " << 21 + ( int ) 20 * rand() / ( RAND_MAX + 1 ) << "\t"
		   << 21 + ( int ) 20 * rand() / ( RAND_MAX + 1 ) << "\n"
		 << "2 random numbers between 0 and 1:\n"
		 << "  " << ( double ) rand() / RAND_MAX << "\t" << ( double ) rand() / RAND_MAX << endl;

	system( "Pause" );
	return 0;
} //end main