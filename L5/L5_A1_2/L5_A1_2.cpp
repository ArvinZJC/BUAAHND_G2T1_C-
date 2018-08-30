/* 2017.12.22, L5_A.pdf, Assignment 1, 5-digit number code decryptor;
   my 2nd method (with an array) which is more practical than my 1st method */
#include <iostream>
using namespace std;

void decrypt( int numCD ) //num and CD are respectively the abbreviations of number and code
{
	int num[ 5 ];
	
	cout << "Your number code decrypted: ";

	for( int CNT = 0; CNT < 5; CNT++ )
		/* loop to encrypt the 5-digit number code;
		CNT is the abbreviation of counter */
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
	int numCD;
	
	cout << "Enter your 5-digit number code encrypted: ";
	cin >> numCD; //regard the 5-digit number code as an integer which will be filled with 0 to ensure 5 digits

	while( numCD > 99999 ) //ensure that there are no more than 5 digits
	{
		cout << "Error! Please enter again: ";
		cin >> numCD;
	} //end while

	decrypt( numCD ); //call the specified function to decrypt the 5-digit number code

	system( "Pause" );
	return 0;
} //end function main