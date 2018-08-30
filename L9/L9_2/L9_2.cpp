//2018.01.02, L9.pdf, P39, program that judges if the file read exists
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fileRead( "test_L9_2.txt" );
	/* if "L9_2.cpp" and "test_L9_2.txt" are not in the same folder, the address of "test_L9_2.txt" needs adding;
	   "\\"is used in Windows, while "/" is used in Linux */

	if( fileRead )
	{
		cout << "The file exists." << endl;

		fileRead.close(); //close the file currently associated with the stream to avoid resource leak
	}	
	else
		cout << "The file does not exist." << endl;

	system( "Pause" );
	return 0;
} //end function main