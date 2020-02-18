// L2.pdf, P62, program that uses conditional operator (?:)

#include <iostream>
using namespace std;

int main()
{
	int number1, number2 = 100, number3 = 200;

	/* assign the max of "number2" and "number3" to "number1";
	   conditional operator (?:) is C++'s only ternary operator (operator that takes three operands);
	   "?:" can be used in place of an if...else statement */
	number1 = (number2 < number3) ? number2 : number3;

	cout << number1 << endl;

	return 0;
} // end main