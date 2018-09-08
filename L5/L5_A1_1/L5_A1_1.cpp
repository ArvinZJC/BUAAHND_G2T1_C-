/* 2017.12.22, L5_A.pdf, Assignment 1, 5-digit number code decryptor
   my 1st method */

#include <iostream>
using namespace std;

/* Decrypt a 5-digit number code. */
void Decrypt( int numberCode )
{
	int units, tens, hundreds, thousands, tenThousands, a, b, c, d, e;

	{
		units = numberCode % 10;
		tens = ( numberCode / 10 ) % 10;
		hundreds = ( numberCode / 100 ) % 10;
		thousands = ( numberCode / 1000 ) % 10;
		tenThousands = ( numberCode / 10000 ) % 10;
	} //get the number of each digit in the integer (including 0 filled) from right to left

	{
		a = ( units + 5 ) % 10;
		b = ( tens + 5 ) % 10;
		c = ( hundreds + 5 ) % 10;
		d = ( thousands + 5 ) % 10;
		e = ( tenThousands + 5 ) % 10;
	} //decrypt each number using the formula "( x + 5 ) % 10"

	cout << "Your number code decrypted: " << a << b << c << d << e << endl;
} //end function Decrypt

int main()
{
	int numberCode;
	
	cout << "Enter your 5-digit number code encrypted: ";
	cin >> numberCode; //regard the 5-digit number code as an integer which will be filled with 0 to ensure 5 digits

	//ensure that there are no more than 5 digits
	while( numberCode > 99999 )
	{
		cout << "Error! Please enter again: ";
		cin >> numberCode;
	} //end while

	Decrypt( numberCode ); //call the specified function to decrypt the 5-digit number code

	system( "Pause" );
	return 0;
} //end main