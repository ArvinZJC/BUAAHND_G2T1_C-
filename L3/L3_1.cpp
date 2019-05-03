// L3.pdf, P12, program that carries out a random calculation

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int number1, number2, category;
	
	srand(time(NULL));
	category = rand() % 4 + 1; // pick a random integer between 1 and 4 (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division)
	
	cout << "Enter 2 integers separated by a space: ";
	cin >> number1 >> number2;
	cout << endl;

	// the following nested if...else statements can be rewritten by a switch-case statement
	if (category == 4 && number2 == 0)
		cout << "When the denominator is 0, the division cannot be carried out." << endl;
	else if (category == 1)
		cout << number1 << " + " << number2 << " = " << number1 + number2 << endl;
	else if (category == 2)
		cout << number1 << " - " << number2 << " = " << number1 - number2 << endl;
	else if (category == 3)
		cout << number1 << " * " << number2 << " = " << number1 * number2 << endl;
	// execute if category = 4 and number2 �� 0
	else
		cout << number1 << " / " << number2 << " = " << (double)number1 / number2 << endl;

	system("Pause");
	return 0;
} // end main