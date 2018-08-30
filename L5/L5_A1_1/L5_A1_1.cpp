/* 2017.12.22, L5_A.pdf, Assignment 1, 5-digit number code decryptor;
   my 1st method */
#include <iostream>
using namespace std;

void decrypt( int numCD ) //num and CD are respectively the abbreviations of number and code
{
	int units, tens, hundreds, thousands, tenThousands, a, b, c, d, e;

	//get the number of each digit in the integer (including 0 filled) from right to left
	units = numCD % 10;
	tens = ( numCD / 10 ) % 10;
	hundreds = ( numCD / 100 ) % 10;
	thousands = ( numCD / 1000 ) % 10;
	tenThousands = ( numCD / 10000 ) % 10;

	//decrypt each number using the formula "( x + 5 ) % 10"
	a = ( units + 5 ) % 10;
	b = ( tens + 5 ) % 10;
	c = ( hundreds + 5 ) % 10;
	d = ( thousands + 5 ) % 10;
	e = ( tenThousands + 5 ) % 10;

	cout << "Your number code decrypted: " << a << b << c << d << e << endl;
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