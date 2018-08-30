/* 2017.12.08, L1.pdf, P54, "Hello World!" beginner program;
   L1_1.cpp, L1_2.cpp and L1_3.cpp demonstrate 3 ways to declare using the std namespace */
#include <iostream> //indicate the header file included

int main()
{
	std::cout << "Hello World!" << std::endl;
	/* print "Hello World!";
	   features of the C++ Standard Library are declared within the std namespace;
	   "<<" is the stream insertion operator */

	system( "Pause" ); //pause the program and diplay "Press any key to continue..."
	return 0; //return the value 0 to indicate that the program has successfully run
} //end function main