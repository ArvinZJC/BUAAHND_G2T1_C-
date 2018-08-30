//2017.12.15, L3.pdf, P42, program that shows the level of an integer grade
#include <iostream>
using namespace std;

int main()
{
	int GDE; //GDE is the abbreviation of grade

	cout << "Enter an integer grade between 0 and 100: ";
	cin >> GDE;
	
	while( GDE < 0 || GDE > 100 ) //loop until a proper integer grade is entered
	{
		cout << "Error! Please enter again: ";
		cin >> GDE;
	}

	cout << endl;

	switch( GDE / 10 )
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
	} //end switch-case

	system( "Pause" );
	return 0;
} //end function main