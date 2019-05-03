// 《21天学通C++（第7版）》, P103 & 104, program that operates data with a pointer and the indirection operator (*)

#include <iostream>
using namespace std;

int main()
{
	int dogAge = 30;
	int* pAge = &dogAge;

	cout << "Initialised dog's age: " << dogAge
		 << "\nPointer \"pAge\" points to the variable \"dogAge\"."
		 << "\nEnter an age for your dog: ";
	cin >> *pAge; // store input at the memory pointed to by the pointer "pAge"
	cout << "\nInput stored using the pointer \"pAge\" at 0x" << hex << pAge << "." // display the value of the pointer
		 << "\nDog's age: " << dec << dogAge << endl;

	system("Pause");
	return 0;
} // end main