/* 2017.12.19, L4_A.pdf, Assignment 1, 5-digit number code encryptor;
   my 2nd method (with an array) which is more practical than my 1st method */
#include <iostream>
using namespace std;

void encrypt( int numCD ) //num and CD are respectively the abbreviations of number and code
{
	int num[ 5 ];
	
	cout << "Your number code encrypted: ";

	for( int CNT = 0; CNT < 5; CNT++ )
		/* loop to encrypt the 5-digit number code;
		CNT is the abbreviation of counter */
	{
		//store the 5-digit number code in the array named num in reverse order (Step 2)
		num[ CNT ] = numCD % 10;
		numCD /= 10;

		//encrypt each number using the formula "( x + 5 ) % 10" (Step 1)
		num[ CNT ] += 5;
		num[ CNT ] %= 10;

		cout << num[ CNT ];
	} //end for

	cout << endl;
} //end function encrypt

int main()
{
	int numCD;
	
	cout << "Enter your 5-digit number code (avoid starting with 0): ";
	cin >> numCD; //regard the 5-digit number code as a 5-digit integer

	while( ( numCD < 10000 ) || ( numCD > 99999 ) ) //loop until a proper 5-digit number code is entered
	{
		cout << "Error! Please enter again: ";
		cin >> numCD;
	} //end while

	encrypt( numCD ); //call the specified function to encrypt the 5-digit number code

	system( "Pause" );
	return 0;
} //end function main