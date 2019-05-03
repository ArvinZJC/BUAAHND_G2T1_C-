/* 《21天学通C++（第7版）》, P115, program that indicates how to use the try...catch statement to handle exception;
   different computers may have different results */

#include <iostream>
using namespace std;

int main()
{
	try
	{
		int* pAge = new int[536870911]; // request a large amount of memory space

		// here omit code related to using the allocated memory

		delete[] pAge; // delete the pointer to release memory
	}
	catch (bad_alloc)
	{
		cout << "Memory allocation failed. Ending program." << endl;
	} // end try...catch

	system("Pause");
	return 0;
} // end main