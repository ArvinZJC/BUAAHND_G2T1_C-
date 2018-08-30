/* 2017.12.22, an extension of Assignment 1, 5-digit number code decryptor;
   this program rewritten from L5_A1_2.cpp processes the input more scrupulously */
#include <iostream>
#include <string>
using namespace std;

int CHKinput( string input ) //CHK is the abbreviation of check
{
	if( input.size() != 5 ) //ensure that there are 5 digits
	{
		cout << "Error! Please enter again: ";
		
		return 1;
	}
	else
	{
		for( int CNT = 0; CNT < 5; CNT++ )
		/* ensure that there is no non-digital character;
		   CNT is the abbreviation of counter */
		{
			if( input[ CNT ] < '0' || input[ CNT ] > '9' )
			{
				cout << "Error! Please enter again: ";

				return 1;
			} //end if
		} //end for

		return 0;
	} //end if...else
} //end function CHKinput

void decrypt( int numCD ) //num and CD are respectively the abbreviations of number and code
{
	int num[ 5 ];

	cout << "Your number code decrypted: ";

	for( int CNT = 0; CNT < 5; CNT++ ) //loop to encrypt the 5-digit number code
	{
		//store the 5-digit number code encrypted in the array named num in reverse order
		num[ CNT ] = numCD % 10;
		numCD /= 10;

		//decrypt each number using the formula "( x + 5 ) % 10"
		num[ CNT ] += 5;
		num[ CNT ] %= 10;

		cout << num[ CNT ];
	} //end for

	cout << endl;
} //end function decrypt

int main()
{
	int run = 1;
	string input;
	
	cout << "Enter your 5-digit number code encrypted: ";

	while( run ) //loop until the input is legal (run = 0)
	{
		getline( cin, input );
		run = CHKinput( input ); //call the specified function to check the input
	} //end while

	decrypt( stoi( input ) ); //call the specified function to decrypt the 5-digit number code

	system( "Pause" );
	return 0;
} //end function main