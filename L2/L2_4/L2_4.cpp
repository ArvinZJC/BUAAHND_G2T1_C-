//2017.12.12, L2.pdf, P100, program that judge whether the integer entered is odd or even

#include <iostream>
using namespace std;

int main()
{
	int number;

	cout << "Enter an integer: ";
	cin >> number;

	//even integers can be divided exactly by 2
	if( number % 2 == 0 )
		cout << number << " is even." << endl;
	else
		cout << number << " is odd." << endl;

	system( "Pause" );
	return 0;
} //end main