// program that uses a goto statement to enable the user to decide whether to perform another operation

#include <iostream>
using namespace std;

int main()
{
calculator:
	int number1, number2;
	char run;

	cout << "Enter 2 integers: ";
	cin >> number1 >> number2;
	cout << "\n" << number1 << " × " << number2 << " = " << number1 * number2 << "\n"
		 << number1 << " + " << number2 << " = " << number1 + number2 << "\n"
		 << "\nDo you wish to perform another operation? (Y/N)  ";
	cin >> run;

	// although there is more than 1 statement in the case part, we do not need to use "{}"
	switch (run)
	{
	case 'Y':
	case 'y':
		cout << endl;
		goto calculator; // repeat the calculation

	case 'N':
	case 'n':
		break; // exit switch

	default:
		cout << "There is no such selection. Thus, it is automatically regarded as \"N\"." << endl;
	} // end switch-case
	
	system("Pause");
	return 0;
} // end main