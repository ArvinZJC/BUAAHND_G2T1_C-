//2017.12.23, program that uses Bubble Sort

#include <iostream>
using namespace std;

/* Output an array. */
void OutputArray( int array[] )
{
	for( int counter = 0; counter < 5; counter++ )
		cout << array[ counter ] << "  ";
} //end function OutputArray

int main()
{
	int temp;
	int array[] = { 5, 5, 2, 5, 3 };
	bool run;

	cout << "Before sorting:\n";

	OutputArray( array ); //call the specified function to output the array named array

	for( int i = 0; i < 4; i++ )
	{
		run = true;

		for( int j = 0; j < 4 - i; j++ )
		{
			if( array[ j ] > array[ j + 1 ] )
			{
				temp = array[ j ];
				array[ j ] = array[ j + 1 ];
				array[ j + 1 ] = temp;
				run = false;
			} //end if
		} //end for

		if( run )
			break;
	} //end for

	cout << "\nAfter sorting:\n";

	OutputArray( array ); //call the specified function to output the array named array

	cout << endl;

	system( "Pause" );
	return 0;
} //end main