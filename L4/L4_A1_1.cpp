/* L4_A.pdf, Assignment 1, 5-digit number code encryptor;
   my 1st method */

#include <iostream>
using namespace std;

/* Encrypt a 5-digit number code. */
void Encrypt(int numberCode)
{
	int units, tens, hundreds, thousands, tenThousands, a, b, c, d, e;

	// get the number of each digit in the 5-digit integer from right to left (Step 2)
	units = numberCode % 10;
	tens = (numberCode / 10) % 10;
	hundreds = (numberCode / 100) % 10;
	thousands = (numberCode / 1000) % 10;
	tenThousands = (numberCode / 10000) % 10;

	// encrypt each number using the formula "(x + 5) % 10" (Step 1)
	a = (units + 5) % 10;
	b = (tens + 5) % 10;
	c = (hundreds + 5) % 10;
	d = (thousands + 5) % 10;
	e = (tenThousands + 5) % 10;

	cout << "Your number code encrypted: " << a << b << c << d << e << endl;
} // end function Encrypt

int main()
{
	int numberCode;
	
	cout << "Enter your 5-digit number code (avoid starting with 0): ";
	cin >> numberCode; // regard the 5-digit number code as a 5-digit integer

	// loop until a proper 5-digit number code is entered
	while (numberCode < 10000 || numberCode > 99999)
	{
		cout << "Error! Please enter again: ";
		cin >> numberCode;
	} // end while

	Encrypt(numberCode); // call the specified function to encrypt the 5-digit number code

	system("Pause");
	return 0;
} // end main