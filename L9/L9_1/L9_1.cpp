//2018.01.02, L9.pdf, P28, program that uses the list container

#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	list<int> test;
	list<int>::iterator element;

	test.push_front( 3 );
	test.push_front( 4 );
	test.push_back( 1 );
	test.push_back( 2 );

	cout << "Elements in the list container named test: ";

	for( element = test.begin(); element != test.end(); element++ )
		cout << *element << "  ";
	
	cout << "\nThe biggest one: " << *max_element( test.begin(), test.end() )
		 << "\nThe smallest one: " << *min_element( test.begin(), test.end() )
		 << "\nSum: " << accumulate( test.begin(), test.end(), 0 ) << endl;

	system( "Pause" );
	return 0;
} //end main