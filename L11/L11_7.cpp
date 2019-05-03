// 《21天学通C++（第7版）》, P116, program that indicates how to use "new(nothrow)" to handle exception

#include <iostream>
using namespace std;

int main()
{
	int* pAge = new(nothrow) int[0x1fffffff]; // use nothrow version and request a large amount of memory space

	// execute if pAge ≠ null
	if (pAge)
	{
		// here omit code related to using the allocated memory

		delete[] pAge; // delete the pointer to release memory
	}
	else
		cout << "Memory allocation failed. Ending program." << endl;

	system("Pause");
	return 0;
} // end main