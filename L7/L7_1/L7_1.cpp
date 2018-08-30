//2017.12.28, L7.pdf, P22, factorial calculator
#include <iostream>
using namespace std;

class Calculator
{
	long long product;
	//type long long enables the calculator to correctly calculate at most 20!, while type int or long at most 12!;

public:
	Calculator()
	{
		product = 1;
		/* 0 should not be assigned to "product" as an initial value since the product of any number and 0 is 0;
		   1 should be assigned to "product" as an initial value to directly print the result 1 when num = 0 */
	} //end constructor calculator

	long long calculateFactorial( int num ) //num is the abbreviation of number
	{
		while( num-- )
		//calculate the factorial using the formula "x! = x * ( x ¨C 1 ) * ( x ¨C 2 ) * ¡­ * 1" when 1 ¡Ü num ¡Ü 20
			product *= ( num + 1 );

		return product;
	} //end function calculateFactorial
}; //end class Calculator

int main()
{
	Calculator test; //create a Calculator object and assign it to "test"

	int num;

	cout << "Enter an integer between 0 and 20: ";
	cin >> num;

	while( ( num < 0 ) || ( num > 20 ) ) //loop until a proper integer is entered
	{
		cout << "Error! Please enter again: ";
		cin >> num;
	} //end while

	cout << "\n" << num << "! = " << test.calculateFactorial( num ) << endl;
	//call the specified function in class Calculator to calculate the factorial

	system( "Pause" );
	return 0;
} //end function main