// L8_A.pdf, Assignment 1, program that processes a sequence of integers according to the user's choice

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

/* This class contains functions for processing a sequence of integers. */
class ProcessSequenceOfIntegers
{
	vector<int> sequenceOfIntegers;
	vector<int>::iterator number;

	/* Process the input for functions Insert and Search. */
	int ProcessInputForInsertAndSearch()
	{
		int run = 1;
		string input;
		
		// loop until the input is legal (run = 0)
		while (run == 1)
		{
			getline(cin, input);

			/* allow entering an integer;
			   the input can start with spaces and can also end up with spaces */
			regex pattern("\\s*-?\\d+\\s*");

			// check if the input is legal
			if (regex_match(input, pattern))
				run = 0;
			else
				cout << "Error! Illegal input.\n"
				     << "Please enter again: ";
		} // end while

		if (input[0] == ' ')
			input.erase(0, input.find_first_not_of(" ")); // delete the probable space(s) at the front
		
		input.erase(input.find_last_not_of(" ") + 1, input.size()); // delete the probable space(s) at the back
		return stoi(input); // convert "input" to an integer
	} // end function ProcessInputForInsertAndSearch

	/* Process the input for function Delete. */
	int ProcessInputForDelete()
	{
		int run = 1;
		string input;
		
		// loop until the input is legal (run = 0)
		while (run == 1)
		{
			getline(cin, input);
			
			/* allow entering a positive integer;
			   the input can start with spaces and can also end up with spaces */
			regex pattern("\\s*[0-9]*[1-9]+\\s*");
			
			// check if the input is legal
			if (regex_match(input, pattern))
				run = 0;
			else
				cout << "Error! Illegal input.\n"
				     << "Please enter again: ";
		} // end while

		if (input[0] == ' ')
			input.erase(0, input.find_first_not_of(" ")); // delete the probable space(s) at the front

		input.erase(input.find_last_not_of(" ") + 1, input.size() - 1); // delete the probable space(s) at the back
		return stoi(input); // convert "input" to an integer
	} // end function ProcessInputForDelete

	/* Locate the integer entered. */
	int LocateInteger(int numberEntered)
	{
		int location = 0; // 0 should be assigned to "location" as an initial value which represents that there is no such integer

		// loop to search the integer entered
		for (int count = 0; count < (int)sequenceOfIntegers.size(); count++)
		{
			// if the integer exists, record its location
			if (sequenceOfIntegers[count] == numberEntered)
			{
				location = count + 1;
				break;
			} // end if
		} // end for

		return location;
	} // end function LocateInteger

public:
	/* Get a specified character for the selection. */
	char ProcessSelectionEntered()
	{
		int run = 1;
		string input;
		
		// loop until the input is legal (run = 0)
		while (run == 1)
		{
			getline(cin, input);
			
			/* allow entering A or B or C or D or Q (the lowercase letter is also accepted);
			   the input can start with spaces and can also end up with spaces */
			regex pattern("\\s*([A-D]|Q|[a-d]|q)\\s*");
			
			// check if the input is legal
			if (regex_match(input, pattern))
				run = 0;
			else
				cout << "Error! Illegal input.\n"
				     << "Please enter again: ";
		} // end while

		if (input[0] == ' ')
			input.erase(0, input.find_first_not_of(" ")); // delete the probable space(s) at the front

		input.erase(input.find_last_not_of(" ") + 1, input.size() - 1); // delete the probable space(s) at the back
		return input[0]; // convert "input" to an character
	} // end function ProcessSelectionEntered

	/* Generate a sequence of integers. */
	void Generate()
	{
		// loop to add 5 random integers between 1 and 1,000 to the vector named sequenceOfIntegers
		for (int count = 1; count <= 5; count++)
			sequenceOfIntegers.push_back(1 + rand() % 1000);

		sort(sequenceOfIntegers.begin(), sequenceOfIntegers.end()); // sort all integers from smallest to largest
	} // end function Generate

	/* Print all integers from smallest to largest. */
	void PrintAllIntegers()
	{
		if (sequenceOfIntegers.empty())
			cout << "Error! There is no number." << endl;
		else
		{
			cout << "From smallest to largest:" << endl;

			// loop to print all integers from smallest to largest
			for (number = sequenceOfIntegers.begin(); number != sequenceOfIntegers.end(); number++)
				cout << *number << endl;
		} // end if...else
	} // end fuction PrintAllIntegers

	/* Add an integer. */
	void Insert()
	{
		int numberEntered, run = 1;
		
		cout << "Enter an integer: ";

		// loop until a proper integer is entered
		while (run != 0)
		{
			numberEntered = ProcessInputForInsertAndSearch(); // call the specified function to get a proper integer to insert
			run = LocateInteger(numberEntered); // call the specified function to locate the integer entered
			
			if (run != 0)
				cout << "Error! There exists the same integer.\n"
					 << "Please enter again: ";
		} // end while

		sequenceOfIntegers.push_back(numberEntered);
		sort(sequenceOfIntegers.begin(), sequenceOfIntegers.end()); // sort all integers from smallest to largest

		cout << "\nThe integer " << numberEntered << " has been successfully inserted." << endl;
	} // end function Insert

	/* Delete an integer. */
	void Delete()
	{
		if ((int)sequenceOfIntegers.size() == 0)
			cout << "Error! There is no number to delete.\n"
			     << "You may select Option B in the menu for at least 1 integer before deleting one." << endl;
		else
		{
			cout << "There are " << sequenceOfIntegers.size() << " integers.\n"
				 << "(1 stands for the 1st, 2 for the 2nd...)\n"
				 << "Enter which integer to delete: ";

			int numberEntered = ProcessInputForDelete(); // call the specified function to get a proper integer to delete

			// loop until a proper integer is entered
			while (numberEntered > (int)sequenceOfIntegers.size())
			{
				cout << "Error! There are only " << sequenceOfIntegers.size() << " integers.\n"
					 << "Please enter again: ";

				numberEntered = ProcessInputForDelete(); // call the specified function to get a proper integer to delete
			} // end while

			number = sequenceOfIntegers.begin() + numberEntered - 1; // locate the index of the specified integer

			cout << "The specified integer " << *number << " has been succesfully deleted." << endl;

			sequenceOfIntegers.erase(number);
		} // end if...else
	} // end function Delete

	/* Search an integer. */
	void Search()
	{
		int numberEntered;

		cout << "Enter an integer: ";

		numberEntered = ProcessInputForInsertAndSearch(); // call the specified function to get a proper integer to search

		cout << endl;
		
		// call the specified function to locate the integer entered
		switch (LocateInteger(numberEntered))
		{
		case 0:
			cout << "There is no such integer." << endl;
			break;
			
		case 1:
			cout << "The specified integer " << numberEntered << " is the 1st one." << endl;
			break;

		case 2:
			cout << "The specified integer " << numberEntered << " is the 2nd one." << endl;
			break;

		case 3:
			cout << "The specified integer " << numberEntered << " is the 3rd one." << endl;
			break;

		default:
			cout << "The specified integer " << numberEntered << " is the " << LocateInteger(numberEntered) << "th one." << endl; // call the specified function to locate the integer entered
		} // end switch-case
	} // end function Search
}; // end class ProcessSequenceOfIntegers

int main()
{
	ProcessSequenceOfIntegers user; // create a ProcessSequenceOfIntegers object and assign it to "user"
	char selection = '0';
	string input;

	srand(time(NULL));

	user.Generate(); // call the specified function in class ProcessSequenceOfIntegers to generate a sequence of integers

	while (selection != 'Q' || selection != 'q')
	{
		cout << "For the current sequence of integers,\n"
			 << "  A: print all integers\n"
			 << "  B: insert an integer\n"
			 << "  C: delete an integer\n"
			 << "  D: search an integer\n"
			 << "  Q: quit\n"
		     << "*******************************************************\n" // these asterisks are used for a better layout
		     << "Enter your selection (A/B/C/D/Q, the lowercase letter is also accepted): ";

		selection = user.ProcessSelectionEntered(); // call the specified function in class ProcessSequenceOfIntegers to get a specified character

		cout << endl;

		switch (selection)
		{
		case 'A':
		case 'a':
			user.PrintAllIntegers(); // call the specified function in class ProcessSequenceOfIntegers to print all integers from smallest to largest
			system("Pause"); // display the result before clearing the screen
			system("cls"); // clear the screen
			break;

		case 'B':
		case 'b':
			user.Insert(); // call the specified function in class ProcessSequenceOfIntegers to add an integer
			system("Pause");
			system("cls");
			break;

		case 'C':
		case 'c':
			user.Delete(); // call the specified function in class ProcessSequenceOfIntegers to delete an integer
			system("Pause");
			system("cls");
			break;

		case 'D':
		case 'd':
			user.Search(); // call the specified function in class ProcessSequenceOfIntegers to search an integer
			system("Pause");
			system("cls");
			break;

		case 'Q':
		case 'q':
			return 0;
		} // end switch-case
	} // end while
} // end main