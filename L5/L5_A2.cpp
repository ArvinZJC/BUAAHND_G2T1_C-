// L5_A.pdf, Assignment 2, program that finds out the index of the person left in a game

#include <iostream>
using namespace std;

int people;

/* Find out the index of the remaining person. */
void RemainingPersonIndex()
{
	int number = 0, remainingPeople = people;
	bool *person = new bool[people + 1]; // use a pointer to create a dynamic array named person for storing each person's status

	/* loop to initialise each array element with "true";
	   person[0] is not used to make it more convenient to express each person's index */
	for (int count = 1; count < people + 1; count++)
		person[count] = true; // the status "false" represents the person exits

	// loop until there is one remaining person
	while (remainingPeople > 1)
	{
		// loop to find out those who exit
		for (int count = 1; count < people + 1; count++)
		{
			if (person[count])
			{
				number++;

				if (number == 3)
				{
					number = 0;
					person[count] = false;
					remainingPeople--;
				} // end if
			} // end if
		} // end for
	} // end while

	// loop to find out the index of the remaining person
	for (int count = 1; count < people + 1; count++)
	{
		if (person[count])
		{
			cout << "The index of the remaining person: " << count << endl;
			break;
		} // end if
	} // end for

	delete[] person; // delete the dynamic array to release memory
} // end function RemainingPersonIndex

int main()
{
	cout << "Enter an integer no less than 2 for the number of people in a circle: ";
	cin >> people;

	// loop until a proper integer is entered
	while (people < 2)
	{
		cout << "Error! Please enter again: ";
		cin >> people;
	} // end while

	RemainingPersonIndex(); // call the specified function to find out the index of the remaining person

	return 0;
} // end main