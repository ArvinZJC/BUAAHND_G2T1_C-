/* 《21天学通C++（第7版）》, P119, program that contains a function calculating square of an integer;
   the function cannot modify the specified value imported by reference */

#include <iostream>
using namespace std;

/* Calculate square of an integer. */
void CalculateSquare(const int& number, int& square)
{
	square = number * number;
} // end function CalculateSquare

int main()
{
	int number = 0, square = 0;
	
	cout << "Enter an integer that you wish to square: ";
	cin >> number;

	CalculateSquare(number, square); // call the specified function to calculate square of an integer

	cout << "Square of " << number << ": " << square << endl;

	system("Pause");
	return 0;
} // end main