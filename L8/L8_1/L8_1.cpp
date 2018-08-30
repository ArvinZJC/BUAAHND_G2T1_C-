//2017.12.29, L8.pdf, P25, program that erases extra spaces in the string entered
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;

	cout << "Enter a string:" << endl;
	getline( cin, input );

	for( int CNT = 0; CNT < input.length() - 1; CNT++ )
	/* loop to erase extra spaces between 2 words;
	   CNT is the abbreviation of counter */
	{
		if( string( input, CNT, 1 ) == " " && string( input, CNT + 1, 1 ) == " " )
		{
			input.erase( CNT, 1 );
			CNT--;
		} //end if
	} //end for

	if( string( input, input.size() - 1, 1 ) == " " ) //erase spaces in the end
		input.erase( input.size() - 1, 1 );

	if( string( input, 0, 1 ) == " " ) //erase spaces at the beginning
		input.erase( 0, 1 );

	cout << "\nAfter processing:\n" << input << endl;

	system( "Pause" );
	return 0;
} //end function main