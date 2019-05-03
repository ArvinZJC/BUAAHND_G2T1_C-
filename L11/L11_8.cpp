// 《21天学通C++（第7版）》, P117, program that indicates that reference is the alias of the corresponding variable

#include <iostream>
using namespace std;

int main()
{
	int original = 30;
	int& reference1 = original;
	int& reference2 = reference1;

	cout << "original = " << original
		 << "\nThe variable \"original\" is at 0x" << hex << &original << ".\n\n"
		 << "reference1 = " << dec << reference1
		 << "\nThe reference \"reference1\" is at 0x" << hex << &reference1 << ".\n\n"
		 << "reference2 = " << dec << reference2
		 << "\nThe reference \"reference2\" is at 0x" << hex << &reference2 << "." << endl;

	system("Pause");
	return 0;
} // end main