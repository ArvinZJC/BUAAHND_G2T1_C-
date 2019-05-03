/* L5_A.pdf, Assignment 1, 5-digit number code decryptor;
   my 2nd method (with an array) which is more practical than my 1st method */

#include <iostream>
using namespace std;

/* Decrypt a 5-digit number code. */
void Decrypt(int numberCode)
{
	int number[5];
	
	cout << "Your number code decrypted: ";

	// loop to encrypt the 5-digit number code
	for (int count = 0; count < 5; count++)
	{
		// store the 5-digit number code encrypted in the array named number in reverse order
		number[count] = numberCode % 10;
		numberCode /= 10;

		// decrypt each number using the formula "(x + 5) % 10"
		number[count] += 5;
		number[count] %= 10;

		cout << number[count];
	} // end for

	cout << endl;
} // end function Decrypt

int main()
{
	int numberCode;
	
	cout << "Enter your 5-digit number code encrypted: ";
	cin >> numberCode; // regard the 5-digit number code as an integer which will be filled with 0 to ensure 5 digits

	// ensure that there are no more than 5 digits
	while (numberCode > 99999)
	{
		cout << "Error! Please enter again: ";
		cin >> numberCode;
	} // end while

	Decrypt(numberCode); // call the specified function to decrypt the 5-digit number code

	system("Pause");
	return 0;
} // end main