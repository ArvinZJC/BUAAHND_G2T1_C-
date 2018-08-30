//2017.12.23, program that uses Bubble Sort
#include <iostream>
using namespace std;

void outputArray( int array[] )
{
	for( int CNT = 0; CNT < 5; CNT++ ) //CNT is the abbreviation of counter
		cout << array[ CNT ] << "  ";
} //end function outputArray

int main()
{
	int tmp; //tmp is the abbreviation of temp
	int array[] = { 5, 5, 2, 5, 3 };
	bool run;

	cout << "Before sorting:\n";

	outputArray( array );

	for( int i = 0; i < 4; i++ )
	{
		run = true;

		for( int j = 0; j < 4 - i; j++ )
		{
			if( array[ j ] > array[ j + 1 ] )
			{
				tmp = array[ j ];
				array[ j ] = array[ j + 1 ];
				array[ j + 1 ] = tmp;
				run = false;
			} //end if
		} //end for

		if( run )
			break;
	} //end for

	cout << "\nAfter sorting:\n";

	outputArray( array );

	cout << endl;

	system( "Pause" );
	return 0;
} //end function main