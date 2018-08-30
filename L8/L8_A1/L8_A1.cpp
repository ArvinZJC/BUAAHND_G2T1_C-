//2017.12.30, L8_A.pdf, Assignment 1, program that process a sequence of integers according to the user's choice
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

class PROCseqOfInt //PROC and seq (SEQ) are respectively the abbreviations of process and sequence
{
	vector<int> SEQofInt;
	vector<int>::iterator num; //num is the abbreviation of number

	int PROCinputForISRT_SRCH() //ISRT and SRCH are respectively the abbreviations of insert and search
	{
		int run = 1;
		string input;

		while( run == 1 ) //loop until the input is legal (run = 0)
		{
			getline( cin, input );

			regex pattern( "\\s*-?\\d+\\s*" );
			/* allow entering an integer;
			   the input can start with spaces and can also end up with spaces */

			if( regex_match( input, pattern ) ) //check if the input is legal
				run = 0;
			else
				cout << "Error! Illegal input.\n"
				     << "Please enter again: ";
		} //end while

		if( input[ 0 ] == ' ' )
			input.erase( 0, input.find_first_not_of( " " ) ); //delete the probable space(s) at the front
		
		input.erase( input.find_last_not_of( " " ) + 1, input.size() ); //delete the probable space(s) at the back
		return stoi( input ); //convert "input" to an integer
	} //end function PROCinputForISRT_SRCH

	int PROCinputForDEL() //DEL is the abbreviation of delete
	{
		int run = 1;
		string input;

		while( run == 1 ) //loop until the input is legal (run = 0)
		{
			getline( cin, input );
			
			regex pattern( "\\s*[0-9]*[1-9]+\\s*" );
			/* allow entering a positive integer;
			   the input can start with spaces and can also end up with spaces */

			if( regex_match( input, pattern ) ) //check if the input is legal
				run = 0;
			else
				cout << "Error! Illegal input.\n"
				     << "Please enter again: ";
		} //end while

		if( input[ 0 ] == ' ' )
			input.erase( 0, input.find_first_not_of( " " ) ); //delete the probable space(s) at the front

		input.erase( input.find_last_not_of( " " ) + 1, input.size() - 1 ); //delete the probable space(s) at the back
		return stoi( input ); //convert "input" to an integer
	} //end function PROCinputForDEL

	int SRCH( int ENTRnum ) //ENTR is the abbreviation of enter
	{
		int LOC = 0;
		/* LOC is the abbreviation of location;
		   0 should be assigned to "LOC" as an initial value which represents that there is no such integer */

		for( int CNT = 0; CNT < ( int ) SEQofInt.size(); CNT++ )
		/* loop to search the integer entered;
		   CNT is the abbreviation of counter */
		{
			if( SEQofInt[ CNT ] == ENTRnum ) //if the integer exists, record its location
			{
				LOC = CNT + 1;
				break;
			} //end if
		} //end for

		return LOC;
	} //end function SRCH

public:
	char PROCinputForSEL() //SEL is the abbreviation of selection
	{
		int run = 1;
		string input;

		while( run == 1 ) //loop until the input is legal (run = 0)
		{
			getline( cin, input );
			
			regex pattern( "\\s*([A-D]|Q|[a-d]|q)\\s*" );
			/* allow entering A or B or C or D or Q (the lowercase letter also accepted);
			   the input can start with spaces and can also end up with spaces */

			if( regex_match( input, pattern ) ) //check if the input is legal
				run = 0;
			else
				cout << "Error! Illegal input.\n"
				     << "Please enter again: ";
		} //end while

		if( input[ 0 ] == ' ' )
			input.erase( 0, input.find_first_not_of( " " ) ); //delete the probable space(s) at the front

		input.erase( input.find_last_not_of( " " ) + 1, input.size() - 1 ); //delete the probable space(s) at the back
		return input[ 0 ]; //convert "input" to an character
	} //end function PROCinputForSEL

	void generate()
	{
		for( int CNT = 1; CNT <= 5; CNT++ ) //loop to add 5 random integers between 1 and 1,000 to the vector SEQofInt
			SEQofInt.push_back( 1 + rand() % 1000 );

		sort( SEQofInt.begin(), SEQofInt.end() ); //sort all integers from smallest to largest
	} //end function generate

	void PRNall() //PRN is the abbreviation of print
	{
		if( SEQofInt.empty() )
			cout << "Error! There is no number." << endl;
		else
		{
			cout << "From smallest to largest:" << endl;

			for( num = SEQofInt.begin(); num != SEQofInt.end(); num++ )
			//loop to print all integers from smallest to largest
				cout << *num << endl;
		}
	} //end fuction PRNall

	void ISRT()
	{
		int ENTRnum, run = 1;
		
		cout << "Enter an integer: ";

		while( run != 0 ) //loop until a proper integer is entered
		{
			ENTRnum = PROCinputForISRT_SRCH(); //call the specified function to get a proper integer
			run = SRCH( ENTRnum ); //call the specified function to search the integer entered
			
			if( run != 0 )
				cout << "Error! There exists the same integer.\n"
					 << "Please enter again: ";
		} //end while

		SEQofInt.push_back( ENTRnum );
		sort( SEQofInt.begin(), SEQofInt.end() ); //sort all integers from smallest to largest

		cout << "\nThe integer " << ENTRnum << " has been successfully inserted." << endl;
	} //end function ISRT

	void DEL()
	{
		if( ( int ) SEQofInt.size() == 0 )
			cout << "Error! There is no number to delete.\n"
			     << "You may select Option B in the menu for at least 1 integer before deleting one." << endl;
		else
		{
			cout << "There are " << SEQofInt.size() << " integers.\n"
				 << "(1 stands for the 1st, 2 for the 2nd...)\n"
				 << "Enter which integer to delete: ";

			int ENTRnum = PROCinputForDEL(); //call the specified function to get a proper integer

			while( ENTRnum > ( int ) SEQofInt.size() ) //loop until a proper integer is entered
			{
				cout << "Error! There are only " << SEQofInt.size() << " integers.\n"
					 << "Please enter again: ";

				ENTRnum = PROCinputForDEL(); //call the specified function to process the input
			} //end while

			num = SEQofInt.begin() + ENTRnum - 1; //locate the index of the specified integer

			cout << "The specified integer " << *num << " has been succesfully deleted." << endl;

			SEQofInt.erase( num );
		} //end if...else
	} //end function DEL

	void SRCH()
	{
		int ENTRnum;

		cout << "Enter an integer: ";

		ENTRnum = PROCinputForISRT_SRCH(); //call the specified function to get a proper integer

		cout << endl;
		
		switch( SRCH( ENTRnum ) )
		{
		case 0:
			cout << "There is no such integer." << endl;
			break;
			
		case 1:
			cout << "The specified integer " << ENTRnum << " is the 1st one." << endl;
			break;

		case 2:
			cout << "The specified integer " << ENTRnum << " is the 2nd one." << endl;
			break;

		case 3:
			cout << "The specified integer " << ENTRnum << " is the 3rd one." << endl;
			break;

		default:
			cout << "The specified integer " << ENTRnum << " is the " << SRCH( ENTRnum ) << "th one." << endl;
		} //end switch-case
	} //end function SRCH
}; //end class PROCseqOfInt

int main()
{
	PROCseqOfInt test; //create a PROCseqOfInt object and assign it to "test"

	char SEL = '0';
	string input;

	srand( time( NULL ) );

	test.generate(); //call the specified function in class PROCseqOfInt to generate a sequence of integers

	while( ( SEL != 'Q' ) || ( SEL != 'q' ) )
	{
		cout << "For the current sequence of integers,\n"
			 << "  A: print all integers\n"
			 << "  B: insert an integer\n"
			 << "  C: delete an integer\n"
			 << "  D: search an integer\n"
			 << "  Q: quit\n"
		     << "*******************************************************\n"
		     //these asterisks are used for a better layout
		     << "Enter your selection (A/B/C/D/Q, the lowercase letter also accepted): ";

		SEL = test.PROCinputForSEL(); //call the specified function in class PROCseqOfInt to get a specified character

		cout << endl;

		switch( SEL )
		{
		case 'A':
		case 'a':
			test.PRNall();
			//call the specified function in class PROCseqOfInt to print all integers from smallest to largest
			system( "Pause" );
			system( "cls" );
			break;

		case 'B':
		case 'b':
			test.ISRT(); //call the specified function in class PROCseqOfInt to add an integer
			system( "Pause" );
			system( "cls" );
			break;

		case 'C':
		case 'c':
			test.DEL(); //call the specified function in class PROCseqOfInt to delete an integer
			system( "Pause" );
			system( "cls" );
			break;

		case 'D':
		case 'd':
			test.SRCH(); //call the specified function in class PROCseqOfInt to search an integer
			system( "Pause" );
			system( "cls" );
			break;

		case 'Q':
		case 'q':
			return 0;
		} //end switch-case
	} //end while
} //end function main