// 《21天学通C++（第7版）》, P104 & 105, program that uses function sizeof on pointers of different types

#include <iostream>
using namespace std;

int main()
{
	int age = 30;
	double pi = 3.1416;
	char sayYes = 'y';

	// initialise pointers to addresses of the variables
	int* pInt = &age;
	double* pDouble = &pi;
	char* pChar = &sayYes;

	cout << "function sizeof with fundamental types -"
		 << "\nsizeof(int) = " << sizeof(int)
		 << "\nsizeof(double) = " << sizeof(double)
		 << "\nsizeof(char) = " << sizeof(char)
		 << "\n\nfunction sizeof with pointers to fundamental types -"
		 << "\nsizeof(pInt) = " << sizeof(pInt)
		 << "\nsizeof(pDouble) = " << sizeof(pDouble)
		 << "\nsizeof(pChar) = " << sizeof(pChar) << endl;

	system("Pause");
	return 0;
} // end main