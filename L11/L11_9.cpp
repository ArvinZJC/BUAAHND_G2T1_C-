/* 《21天学通C++（第7版）》, P118, program that contains a function calculating square of an integer
   the function can modify the value imported by reference */

#include <iostream>
using namespace std;

/* Return square of an integer. */
void ReturnSquare(int& number)
{
	number *= number;
} // end function ReturnSquare

int main()
{
	int number = 0;

	cout << "Enter an integer that you wish to square: ";
	cin >> number;

	ReturnSquare(number); // call the specified function to return square of an integer

	cout << "Square: " << number << endl;

	return 0;
} // end main