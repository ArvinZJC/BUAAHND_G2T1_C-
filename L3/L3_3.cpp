// L3.pdf, P42, program that shows the level of an integer grade

#include <iostream>
using namespace std;

int main()
{
	int grade;

	cout << "Enter an integer grade between 0 and 100: ";
	cin >> grade;
	
	// loop until a proper integer grade is entered
	while (grade < 0 || grade > 100)
	{
		cout << "Error! Please enter again: ";
		cin >> grade;
	} // end while

	cout << endl;

	switch (grade / 10)
	{
	case 10:
	case 9:
		cout << "A" << endl;
		break;

	case 8:
		cout << "B" << endl;
		break;

	case 7:
		cout << "C" << endl;
		break;

	case 6:
		cout << "D" << endl;
		break;

	default:
		cout << "F" << endl;
	} // end switch-case

	return 0;
} // end main