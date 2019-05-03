// L3.pdf, P48, program that calculates the sum of integers between 1 and 100 except those that are divisible by 5

#include <iostream>
using namespace std;

int main()
{
	int sum = 0;

	for (int number = 1; number <= 100; number++)
	{
		if (number % 5 != 0)
			sum += number;
	} // end for

	cout << "The sum of integers between 1 and 100 except those that are divisible by 5: " << sum << endl;

	system("Pause");
	return 0;
} // end main