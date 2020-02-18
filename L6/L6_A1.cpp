// L6_A.pdf, Assignment 1, simplified WeChat Red Packet preparing program

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

/* This class contains functions for preparing WeChat red packets. */
class WeChatRedPacket
{
	/* Determine if the user gives up. */
	int ProcessSelection(char selection)
	{
		switch (selection)
		{
		case 'Y':
		case 'y':
			return 1;
			break;

		case 'N':
		case 'n':
			return -1;
			break;
			
		// execute if the user enters one character which is an unspecified one
		default:
			cout << "Error! There is no such selection." << endl;
			return -1;
		} // end switch-case
	} // end function ProcessSelection

	/* Print each user's index and money received. */
	void OutputResult(int people, double user[])
	{
		cout << "The result:\n"
			 << "User  Money (Unit: RMB)" << endl;
		cout.setf(ios::fixed);

		// loop to print each user's index and money received with a clear layout
		for (int count = 0; count < people; count++)
		{
			user[count] /= 100; // reduce by 100 times to get the actual money received
			
			cout << setw(4) << count + 1 << setw(19) << setprecision(2) << user[count] << endl;
		} // end for
	} // end function OutputResult

public:
	/* Check the input. */
	int CheckInput(int people, double money)
	{
		char selection;
		
		// check if the input is legal
		if (people >= 1 && money >= people * 0.01)
			return 0;
		else if (people < 1)
		{
			cout << "\nError! Illegal input for the quantity of people.\n"
				 << "Do you want to enter again? (Y/N)  ";
			cin >> selection;

			return ProcessSelection(selection); // call the specified function to determine if the user gives up
		}
		else
		{
			cout << "\nError! Each person should receive at least 0.01 RMB.\n"
				 << "Do you want to enter again? (Y/N)  ";
			cin >> selection;

			return ProcessSelection(selection); // call the specified function to determine if the user gives up
		} // end nested if...else
	} // end function CheckInput

	/* Prepare red packets. */
	void PrepareRedPacket(int people, double money)
	{
		double remainingMoney = money * 100; // the value of the variable "money" is increased to 100 times so as to reduce the error of floating-point type
		double *user = new double[people]; // use a pointer to create a dynamic array named user for storing each user's money received

		for (int count = 0; count < people; count++)
		{
			user[count] = 1; // each person should receive at least 0.01 RMB
			remainingMoney -= 1;
		} // end for

		 // loop until there is no remaining money
		while (remainingMoney > 0)
		{
			user[rand() % people] += 1; // a random user receives another 0.01 RMB
			remainingMoney -= 1;
		} // end while

		OutputResult(people, user); // call the specified function to print each user's index and money received

		delete[] user; // delete the dynamic array to release memory
	} // end function PrepareRedPacket
}; // end class WeChatRedPacket

int main()
{
	WeChatRedPacket account; // create a WeChatRedPacket object and assign it to "account"
	int run = 1, people;
	double money;

	srand(time(NULL));

	// loop until the input is legal (run = 0) or the user gives up (run = -1)
	while (run == 1)
	{
		cout << "Enter the quantity of people snatching red packets: ";
		cin >> people;
		cout << "Enter the total amount of money in red packets (unit: RMB): ";
		cin >> money;

		run = account.CheckInput(people, money); // call the specified function in class WeChatRedPacket to check the input

		cout << endl;
	} // end while

	if (run == 0)
		account.PrepareRedPacket(people, money); // call the specified function in class WeChatRedPacket to prepare red packets

	return 0;
} // end main