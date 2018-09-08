//2017.12.29, L8.pdf, P25, program that erases extra spaces in the string entered

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;

	cout << "Enter a string:" << endl;
	getline( cin, input );

	//loop to erase extra spaces between 2 words
	for( int counter = 0; counter < input.length() - 1; counter++ )
	{
		if( string( input, counter, 1 ) == " " && string( input, counter + 1, 1 ) == " " )
		{
			input.erase( counter, 1 );
			counter--;
		} //end if
	} //end for

	//erase spaces in the end
	if( string( input, input.size() - 1, 1 ) == " " )
		input.erase( input.size() - 1, 1 );

	//erase spaces at the beginning
	if( string( input, 0, 1 ) == " " )
		input.erase( 0, 1 );

	cout << "\nAfter processing:\n" << input << endl;

	system( "Pause" );
	return 0;
} //end main