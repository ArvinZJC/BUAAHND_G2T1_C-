/* 2017.12.12, program that gets the max of 3 numbers entered;
   my 1st method */
#include <iostream>
using namespace std;

int main()
{
	double num1, num2, num3, tmp, max; //num and tmp are respectively the abbreviations of number and temp

	cout << "Enter 3 numbers each separated by a space: ";
	cin >> num1 >> num2 >> num3;

	tmp = ( num1 > num2 ) ? num1 : num2; //assign the max of "num1" and "num2" to "tmp"
	max = ( num3 > tmp ) ? num3 : tmp; //assign the max of "num3" and "tmp" to "max"

	cout << "The max: " << max << endl;

	system( "Pause" );
	return 0;
} //end function main