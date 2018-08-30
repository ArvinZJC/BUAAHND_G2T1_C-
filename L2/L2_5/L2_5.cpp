//2017.12.12, program that uses a goto statement to enable the user to decide whether to perform another operation
#include <iostream>
using namespace std;

int main()
{
calculator:
	int num1, num2; //num is the abbreviation of number
	char run;

	cout << "Enter 2 integers: ";
	cin >> num1 >> num2;
	cout << "\n" << num1 << " ¡Á " << num2 << " = " << num1 * num2 << "\n"
		 << num1 << " + " << num2 << " = " << num1 + num2 << "\n"
		 << "\nDo you wish to perform another operation? (Y/N)  ";
	cin >> run;

	switch( run )
	{
	case 'Y': //although there is more than one statement in the case part, we do not need to use "{}"
	case 'y':
		cout << endl;
		goto calculator; //repeat the calculation

	case 'N':
	case 'n':
		break; //exit switch

	default:
		cout << "There is no such selection. Thus, it is automatically regarded as \"N\"." << endl;
	} //end switch-case
	
	system( "Pause" );
	return 0;
} //end function main