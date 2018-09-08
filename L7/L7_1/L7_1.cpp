//2017.12.28, L7.pdf, P22, factorial calculator

#include <iostream>
using namespace std;

/* This class contains functions for calculating the factorial. */
class Calculator
{
	long long product; //type long long enables the calculator to correctly calculate at most 20!, while type int or long at most 12!;

public:
	Calculator()
	{
		/* 0 should not be assigned to "product" as an initial value since the product of any number and 0 is 0
		   1 should be assigned to "product" as an initial value to directly print the result 1 when number = 0 */
		product = 1;
	} //end constructor calculator

	/* Calculate the factorial. */
	long long CalculateFactorial( int number )
	{
		//calculate the factorial using the formula "x! = x * ( x ¨C 1 ) * ( x ¨C 2 ) * ¡­ * 1" when 1 ¡Ü number ¡Ü 20
		while( number-- )
			product *= ( number + 1 );

		return product;
	} //end function CalculateFactorial
}; //end class Calculator

int main()
{
	Calculator user; //create a Calculator object and assign it to "user"

	int number;

	cout << "Enter an integer between 0 and 20: ";
	cin >> number;

	//loop until a proper integer is entered
	while( ( number < 0 ) || ( number > 20 ) )
	{
		cout << "Error! Please enter again: ";
		cin >> number;
	} //end while

	cout << "\n" << number << "! = " << user.CalculateFactorial( number ) << endl; //call the specified function in class Calculator to calculate the factorial

	system( "Pause" );
	return 0;
} //end main