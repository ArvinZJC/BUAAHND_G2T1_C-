/* 2017.12.22, an extension of Assignment 1, 5-digit number code decryptor
   this program rewritten from L5_A1_2.cpp processes the input more scrupulously */

#include <iostream>
#include <string>
using namespace std;

/* Check the input. */
int CheckInput( string input )
{
	//ensure that there are 5 digits
	if( input.size() != 5 )
	{
		cout << "Error! Please enter again: ";
		
		return 1;
	}
	else
	{
		//ensure that there is no non-digital character
		for( int counter = 0; counter < 5; counter++ )
		{
			if( input[ counter ] < '0' || input[ counter ] > '9' )
			{
				cout << "Error! Please enter again: ";

				return 1;
			} //end if
		} //end for

		return 0;
	} //end if...else
} //end function CheckInput

/* Descrypt a 5-digit number code. */
void Decrypt( int numberCode )
{
	int number[ 5 ];

	cout << "Your number code decrypted: ";

	//loop to encrypt the 5-digit number code
	for( int counter = 0; counter < 5; counter++ )
	{
		//store the 5-digit number code encrypted in the array named number in reverse order
		number[counter] = numberCode % 10;
		numberCode /= 10;
		
		//decrypt each number using the formula "( x + 5 ) % 10"
		number[counter] += 5;
		number[counter] %= 10;

		cout << number[ counter ];
	} //end for

	cout << endl;
} //end function Decrypt

int main()
{
	int run = 1;
	string input;
	
	cout << "Enter your 5-digit number code encrypted: ";

	//loop until the input is legal (run = 0)
	while( run )
	{
		getline( cin, input );
		run = CheckInput( input ); //call the specified function to check the input
	} //end while

	Decrypt( stoi( input ) ); //call the specified function to decrypt the 5-digit number code

	system( "Pause" );
	return 0;
} //end main