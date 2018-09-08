//2017.12.23, program that uses Selection Sort

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
	int k, temp;
	int array[] = { 5, 5, 2, 5, 3 };

	cout << "Before sorting:" << endl;

	OutputArray( array ); //call the specified function to output the array named array

	for( int i = 0; i < 4; i++ )
	{
		k = i;
		
		for( int j = i + 1; j < 5; j++ )
		{
			if( array[ k ] > array[ j ] )
				k = j;
		} //end for

		if( i != k )
		{
			temp = array[ i ];
			array[ i ] = array[ k ];
			array[ k ] = temp;
		}
		else
			break;
	} //end for

	cout << "\nAfter sorting:" << endl;

	OutputArray( array ); //call the specified function to output the array named array

	cout << endl;

	system( "Pause" );
	return 0;
} //end main