// 《21天学通C++（第7版）》, P114, program that indicates a safe way to use pointers

#include <iostream>
using namespace std;

int main()
{
	char selection = 'y';

	cout << "Is it sunny? (y/n)  ";
	cin >> selection;

	if (selection == 'y')
	{
		int* pTemperature = new int;

		*pTemperature = 30; // initialise the pointer to avoid any relevant error

		cout << "Temperature: " << *pTemperature << "℃" << endl;

		delete pTemperature; // delete the pointer to release memory
	} // end if

	return 0;
} // end main