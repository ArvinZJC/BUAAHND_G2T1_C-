// L1_A.pdf, Assignment 2, calculations with 3 unknown numbers x, y and z

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, y, z;
	double formula;

	cout << "Enter 3 proper integers for x, y and z each seperated by a space:" << "\n"
		 << "(ATTENTION: x + z ≠ 0, 2y + 3z ≠ 0)" << endl;
	cin >> x >> y >> z;

	// loop until x, y and z entered satisfiy "x + z ≠ 0, 2y + 3z ≠ 0"
	while ((x + z == 0) || (y * 2 + z * 3 == 0))
	{
		cout << "Error! Please enter again: ";
		cin >> x >> y >> z;
	} // end while

	formula = sqrt(pow((x - y * z) / (x + z), 2)) / (y * 2 + z * 3) + sin(10) + cos(20); // calculate the value of the format "√((x - y * z) / (x + z) ^ 2) / (2y + 3z) + sin10 + cos20"

	cout << "\nThe value of the formula \"√((x - y * z) / (x + z) ^ 2 ) / (2y + 3z) + sin10 + cos20\": " << formula << endl;
	
	return 0;
} // end main