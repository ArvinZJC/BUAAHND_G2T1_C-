/* L1.pdf, P61, "Hello World!" beginner program;
   L1_1.cpp, L1_2.cpp and L1_3.cpp demonstrate 3 ways to declare using the std namespace */

#include <iostream>
using std::cout; 
using std::endl;

int main()
{
	cout << "Hello World!" << endl;

	system("Pause");
	return 0;
} // end main