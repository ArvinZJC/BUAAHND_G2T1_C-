// L2_A.pdf, Assignment 1, bonus calculator for the employee Zhang San

#include <iostream>
using namespace std;

int main()
{
	double profit, bonus;

	cout << "Enter Zhang San's profit on sales of this month (unit: 10,000 RMB): ";
	cin >> profit;

	if (profit <= 5)
		cout << "No bonus!" << endl; // no bonus when profit ≤ 5
	else if (profit <= 15)
	{
		/* calculate the bonus when 5 < profit ≤ 15;
		   when profit = 15, bonus = 7,500 */
		bonus = (profit - 5) * 0.075 * 10000;

		cout << "Bonus (unit: RMB): " << bonus << endl;
	}
	else if (profit <= 40)
	{
		/* calculate the bonus when 15 < profit ≤ 40;
		   when profit = 40, bonus = 20,000 */
		bonus = 7500 + (profit - 15) * 0.05 * 10000;

		cout << "Bonus (unit: RMB): " << bonus << endl;
	}
	else if (profit <= 60)
	{
		/* calculate the bonus when 40 < profit ≤ 60;
		   when profit = 60, bonus = 26,000 */
		bonus = 20000 + (profit - 40) * 0.03 * 10000;

		cout << "Bonus (unit: RMB): " << bonus << endl;
	}
	else if (profit <= 100)
	{
		/* calculate the bonus when 60 < profit ≤ 100
		   when profit = 100, bonus = 32,000 */
		bonus = 26000 + (profit - 60) * 0.015 * 10000;

		cout << "Bonus (unit: RMB): " << bonus << endl;
	}
	else
	{
		bonus = 32000 + (profit - 100) * 0.01; // calculate the bonus when profit > 100

		cout << "Bonus (unit: RMB): " << bonus << endl;
	} // end nested if...else
	
	return 0;
} // end main