//2017.12.12, L2.pdf, P100, program that judge whether the integer entered is odd or even
#include <iostream>
using namespace std;

int main()
{
	int num; //num is the abbreviation of number

	cout << "Enter an integer: ";
	cin >> num;

	if( num % 2 == 0 ) //even integers can be divided exactly by 2
		cout << num << " is even." << endl;
	else
		cout << num << " is odd." << endl;

	system( "Pause" );
	return 0;
} //end function main