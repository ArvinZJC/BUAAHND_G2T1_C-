/* tree printing program;
   this program rewritten from L3_A1.cpp uses function setw to help to print spaces */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int number;

	cout << "Enter an integer between 3 and 10 to print a tree: ";
	cin >> number;

	// loop until a proper integer is entered
	while (number < 3 || number > 10)
	{
		cout << "Error! Please enter again: ";
		cin >> number;
	} // end while

	// loop to print the crown of the tree
	for (int i = 1; i <= number; i++)
	{
		cout << setw(number - i + 1);

		for (int j = 1; j <= i * 2 - 1; j++)
			cout << "*";

		cout << endl;
	} // end for

	// loop to print the trunk of the tree
	for (int length = 1; length <= number; ++length)
		cout << setw(number) << "*" << endl;

	system("Pause");
	return 0;
} // end main