//2017.12.15, L3.pdf, P12, program that carry out a random calculation
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int num1, num2, CATG; //num and CATG are the abbreviations of number and category
	
	srand( time( NULL ) );
	CATG = rand() % 4 + 1;
	//pick a random integer between 1 and 4 (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division)
	
	cout << "Enter 2 integers separated by a space: ";
	cin >> num1 >> num2;
	cout << endl;

	//the following nested if...else statements can be rewritten by a switch-case statement
	if( CATG == 4 && num2 == 0 )
		cout << "When the denominator is 0, the division cannot be carried out." << endl;
	else if( CATG == 1 )
		cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	else if( CATG == 2 )
		cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	else if( CATG == 3 )
		cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
	else //CATG = 4 and num2 ¡Ù 0
		cout << num1 << " / " << num2 << " = " << ( double ) num1 / num2 << endl;

	system( "Pause" );
	return 0;
} //end function main