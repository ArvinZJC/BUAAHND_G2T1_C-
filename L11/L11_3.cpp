// 《21天学通C++（第7版）》, P108, program that operates data with a dynamic array and the increment operator (++)

#include <iostream>
using namespace std;

int main()
{
	int inputNumbers = 0;

	cout << "How many integers you wish to enter?  ";
	cin >> inputNumbers;

	int* pNumbers = new int[inputNumbers]; // allocate requested integers
	int* pCopy = pNumbers;

	cout << "Successfully allocated memory for " << inputNumbers << " integers." << endl;

	for (int index = 0; index < inputNumbers; ++index)
	{
		cout << "Enter number " << index << ": ";
		cin >> *(pNumbers + index);
	} // end for

	cout << "\nDisplay all numbers input:" << endl;

	for (int index = 0; index < inputNumbers; index++)
		cout << *(pCopy++) << "  ";

	cout << endl;

	delete[] pNumbers; // delete the pointer to release memory

	return 0;
} // end main