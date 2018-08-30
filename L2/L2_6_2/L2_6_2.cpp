/* 2017.12.12, program that gets the max of 3 numbers entered;
   my 2nd method */
#include <iostream>
using namespace std;

int main()
{
	double num1, num2, num3, max;

	cout << "Enter 3 numbers each separated by a space: ";
	cin >> num1 >> num2 >> num3;

	max = num1; //assume that "num1" is the largest to start
	
	if( num2 > max ) //determine whether "num2" is larger than "max"
		max = num2;

	if( num3 > max ) //determine whether "num3" is larger than "max"
		max = num3;

	cout << "The max: " << max << endl;

	system( "Pause" );
	return 0;
} //end function main