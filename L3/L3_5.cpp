// L3.pdf, P51, triangle printing program

#include <iostream>
using namespace std;

int main()
{
	/* print a left-aligned regular triangle (10 lines);
	   determine the lines */
	for (int i = 1; i <= 10; i++)
	{
		// determine how many smiling faces a specified line has
		for (int j = 1; j <= i * 2 - 1; j++)
			cout << "\1"; // Bitmap Font needs to be used in cmd.exe to show smiling faces correctly

		cout << endl;
	} // end for

	return 0;
} // end main