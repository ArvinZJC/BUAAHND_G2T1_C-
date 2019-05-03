// L3_A.pdf, Assignment 1, tree printing program

#include <iostream>
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
		for (int space1 = number - i; space1 >= 1; space1--)
			cout << " ";
		
		for (int j = 1; j <= i * 2 - 1; j++)
			cout << "*";

		cout << endl;
	} // end for

	// loop to print the trunk of the tree
	for (int length = 1; length <= number; ++length)
	{
		for (int space2 = 1; space2 <= number - 1; ++space2)
			cout << " ";

		cout << "*" << endl;
	} // end for

	system("Pause");
	return 0;
} // end main