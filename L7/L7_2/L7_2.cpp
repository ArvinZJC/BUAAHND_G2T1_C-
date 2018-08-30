//2017.12.28, program that catogories the input
#include <iostream>
#include <regex>
using namespace std;

class Dictionary
{
public:
	bool isTelNum( string input ) //tel and num are the abbreviations of telephone and number
	{
		regex pattern( "010-\\d{8}" );
		//telephone number: 010-(8 numbers);

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isTelNum

	bool isMobileNum( string input )
	{
		regex pattern( "010-\\d{11}" ); //mobile number: 010-(11 numbers)

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isMobileNum

	bool isEmail( string input )
	{
		regex pattern( "\\w+@\\w+(\\.(\\w+))+" );
		//email: (1 or more letters)@(1 or more letters)(1 or more ".(1 or more letters)")

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isEmail

	bool isNum( string input )
	{
		regex pattern( "[0-9]+" ); //only numbers

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isNum

	bool isUppercaseLTR( string input ) //LTR is the abbreviation of letter
	{
		regex pattern( "[A-Z]+" ); //only uppercase letters

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isUppercaseLTR

	bool isLowercaseLTR( string input )
	{
		regex pattern( "[a-z]+" ); //only lowercase letters

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isLowercaseLTR

	bool isLTR( string input )
	{
		regex pattern( "[A-Za-z]+" ); //only letters

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isLTR

	bool isLTR_Num( string input )
	{
		regex pattern( "[A-Za-z0-9]+" ); //only letters and/or numbers

		if( regex_match( input, pattern ) )
			return true;
		else
			return false;
	} //end function isLTR_Num
}; //end class Dictionary

int main()
{
	Dictionary test; //create a Dictionary object and assign it to "test"

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
		 << "*******************************************************\n"
		//these asterisks are used for a better layout
		 << "Enter a string: ";
	cin >> input;
	cout << "\nThe category of the input: ";

	//call the specified functions in class Dictionary to category the input
	if( ! ( test.isTelNum( input ) || test.isMobileNum( input ) || test.isEmail( input ) || test.isLTR_Num( input ) ) )
		cout << "I" << endl;
	else if( test.isTelNum( input ) )
		cout << "A" << endl;
	else if( test.isMobileNum( input ) )
		cout << "B" << endl;
	else if( test.isEmail( input ) )
		cout << "C" << endl;
	else
	{
		if( ! ( test.isNum( input ) || test.isLTR( input ) ) ) 
			cout << "H" << endl;
		else if( test.isNum( input ) )
			cout << "D" << endl;
		else if( test.isUppercaseLTR( input ) )
			cout << "E" << endl;
		else if( test.isLowercaseLTR( input ) )
			cout << "F" << endl;
		else
			cout << "G" << endl;
	} //end nested if...else

	system( "Pause" );
	return 0;
} //end function main