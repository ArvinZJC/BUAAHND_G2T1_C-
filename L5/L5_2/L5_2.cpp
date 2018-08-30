//2017.12.23, program that uses Selection Sort
#include <iostream>
using namespace std;

void outputArray( int array[] )
{
	for( int CNT = 0; CNT < 5; CNT++ ) //CNT is the abbreviation of counter
		cout << array[ CNT ] << "  ";
} //end function outputArray

int main()
{
	int k, tmp; //tmp is the abbreviation of temp
	int array[] = { 5, 5, 2, 5, 3 };

	cout << "Before sorting:" << endl;

	outputArray( array );

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
			tmp = array[ i ];
			array[ i ] = array[ k ];
			array[ k ] = tmp;
		}
		else
			break;
	} //end for

	cout << "\nAfter sorting:" << endl;

	outputArray( array );

	cout << endl;

	system( "Pause" );
	return 0;
} //end function main