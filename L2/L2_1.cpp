// L2.pdf, P37, program that shows the effect of using "boolalpha"

#include <iostream>
using namespace std;

int main()
{
	bool a1 = true, a2 = 0;
	
	cout << "Before using \"boolalpha\":\n"
		 << "  a1 = " << a1 << "  a2 = " << a2 << "\n"
		 << "  a1 && a2 = " << (a1 && a2) << "\n"
		 << "After using \"boolalpha\":\n"
		 << boolalpha << "  a1 = " << a1 << "  a2 = " << a2 << "\n"
		 << "  a1 && a2 = " << (a1 && a2) << endl;

	return 0;
} // end main