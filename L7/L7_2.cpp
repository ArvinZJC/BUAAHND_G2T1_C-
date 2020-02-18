// program that categories the input

#include <iostream>
#include <regex>
using namespace std;

/* This class contains functions for categoring the input. */
class Dictionary
{
public:
	/* Determine if the input is a telephone number. */
	bool IsTelNumber(string input)
	{
		regex pattern("010-\\d{8}"); // telephone number: 010-(8 numbers);

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function IsTelNumber

	/* Determine if the input is a mobile number. */
	bool IsMobileNumber(string input)
	{
		regex pattern("010-\\d{11}"); // mobile number: 010-(11 numbers)

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function IsMobileNumber

	/* Determine if the input is an email address. */
	bool IsEmail(string input)
	{
		regex pattern("\\w+@\\w+(\\.(\\w+))+"); // email: (1 or more letters)@(1 or more letters)(1 or more ".(1 or more letters)")

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function IsEmail

	/* Determine if the input is only numbers. */
	bool isNumbers(string input)
	{
		regex pattern("[0-9]+"); // only numbers

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function isNumbers

	/* Determine if the input is only uppercase letters. */
	bool IsUppercaseLetters(string input)
	{
		regex pattern("[A-Z]+"); // only uppercase letters

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function IsUppercaseLetters

	/* Determine if the input is only lowercase letters. */
	bool IsLowercaseLetters(string input)
	{
		regex pattern("[a-z]+"); // only lowercase letters

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function IsLowercaseLetters

	/* Determine if the input is only letters. */
	bool IsLetters(string input)
	{
		regex pattern("[A-Za-z]+"); // only letters

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function IsLetters

	/* Determine if the input is only letters and/or numbers. */
	bool IsLettersAndOrNumbers(string input)
	{
		regex pattern("[A-Za-z0-9]+"); // only letters and/or numbers

		if (regex_match(input, pattern))
			return true;
		else
			return false;
	} // end function IsLettersAndOrNumbers
}; // end class Dictionary

int main()
{
	Dictionary user; // create a Dictionary object and assign it to "user"
	string input;
	
	cout << "A. telephone number\n"
		 << "B. mobile number\n"
		 << "C. email\n"
		 << "D. only numbers\n"
		 << "E. only uppercase letters\n"
		 << "F. only lowercase letters\n"
		 << "G. only uppercase and lowercase letters\n"
		 << "H. only letters and numbers\n"
		 << "I. none of above\n" 
		 << "*******************************************************\n" // these asterisks are used for a better layout
		 << "Enter a string: ";
	cin >> input;
	cout << "\nThe category of the input: ";

	// call the specified functions in class Dictionary to category the input
	if (!(user.IsTelNumber(input) || user.IsMobileNumber(input) || user.IsEmail(input) || user.IsLettersAndOrNumbers(input)))
		cout << "I" << endl;
	else if (user.IsTelNumber(input))
		cout << "A" << endl;
	else if (user.IsMobileNumber(input))
		cout << "B" << endl;
	else if (user.IsEmail(input))
		cout << "C" << endl;
	else
	{
		if (!(user.isNumbers(input) || user.IsLetters(input))) 
			cout << "H" << endl;
		else if (user.isNumbers(input))
			cout << "D" << endl;
		else if (user.IsUppercaseLetters(input))
			cout << "E" << endl;
		else if (user.IsLowercaseLetters(input))
			cout << "F" << endl;
		else
			cout << "G" << endl;
	} // end nested if...else

	return 0;
} // end main