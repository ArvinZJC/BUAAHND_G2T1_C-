// L9.pdf, P39, program that judges if the file is successfully read

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	/* if "L9_2.cpp" and "test_L9_2.txt" are not in the same folder, the following file path needs completing;
	   "\\"is used in Windows, while "/" is used in Linux */
	ifstream fileRead("test_L9_2.txt");

	// execute if the file is successfully read
	if (fileRead.is_open())
	{
		cout << "The file is successfully read." << endl;

		fileRead.close(); // close the file currently associated with the stream to avoid resource leak or any other problems
	}	
	else
		cout << "The file is not successfully read." << endl;

	return 0;
} // end main