/* L4_A.pdf, Assignment 1, 5-digit number code encryptor;
   my 2nd method (with an array) which is more practical than my 1st method */

#include <iostream>
using namespace std;

/* Encrypt a 5-digit number code. */
void Encrypt(int numberCode)
{
	int number[5];
	
	cout << "Your number code encrypted: ";

	// loop to encrypt the 5-digit number code
	for (int count = 0; count < 5; count++)
	{
		// store the 5-digit number code in the array named number in reverse order (Step 2)
		number[count] = numberCode % 10;
		numberCode /= 10;

		// encrypt each number using the formula "(x + 5) % 10" (Step 1)
		number[count] += 5;
		number[count] %= 10;

		cout << number[count];
	} // end for

	cout << endl;
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