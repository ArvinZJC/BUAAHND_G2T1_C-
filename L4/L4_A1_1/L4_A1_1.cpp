/* 2017.12.19, L4_A.pdf, Assignment 1, 5-digit number code encryptor;
   my 1st method */
#include <iostream>
using namespace std;

void encrypt( int numCD ) //num and CD are respectively the abbreviations of number and code
{
	int units, tens, hundreds, thousands, tenThousands, a, b, c, d, e;

	//get the number of each digit in the 5-digit integer from right to left (Step 2)
	units = numCD % 10;
	tens = ( numCD / 10 ) % 10;
	hundreds = ( numCD / 100 ) % 10;
	thousands = ( numCD / 1000 ) % 10;
	tenThousands = ( numCD / 10000 ) % 10;

	//encrypt each number using the formula "( x + 5 ) % 10" (Step 1)
	a = ( units + 5 ) % 10;
	b = ( tens + 5 ) % 10;
	c = ( hundreds + 5 ) % 10;
	d = ( thousands + 5 ) % 10;
	e = ( tenThousands + 5 ) % 10;

	cout << "Your number code encrypted: " << a << b << c << d << e << endl;
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