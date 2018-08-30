//2017.12.15, L3.pdf, P51, triangle printing program
#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
	/* print a left-aligned regular triangle (10 lines);
	   determine the lines */
	{
		for (int j = 1; j <= i * 2 - 1; j++) //determine how many smiling faces a specified line has
			cout << "\1"; //Bitmap Font needs to be used in cmd.exe to show smiling faces correctly

		cout << endl;
	} //end for

	system( "Pause" );
	return 0;
} //end function main