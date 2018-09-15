/* 2018.09.05, 《21天学通C++（第7版）》, P118, program that contains a function calculating square of an integer
   the function can modify the value imported by reference */

#include <iostream>
using namespace std;

void ReturnSquare( int& number )
{
	number *= number;
} //end function ReturnSquare

int main()
{
	int number = 0;

	cout << "Enter an integer that you wish to square: ";
	cin >> number;

	ReturnSquare( number );

	cout << "Square: " << number << endl;

	system( "Pause" );
	return 0;
} //end main