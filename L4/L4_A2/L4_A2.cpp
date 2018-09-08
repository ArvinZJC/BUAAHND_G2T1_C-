//2017.12.19, L4_A.pdf, Assignment 2, arithmetic learning program for primary students

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int number1 = 50, number2 = 51, result, totalCounter = 0, correctCounter = 0; //declare global variables and initialise most of them

/* Generate 5 addition exercises. */
void Addition()
{
	//loop to generate 5 exercises
	for( int counter = 1; counter <= 5; counter++ )
	{		
		//loop to generate 2 proper numbers for an exercise
		while( number1 + number2 > 100 )
		{
			number1 = rand() % 101; //pick a random integer between 0 and 100
			number2 = rand() % 101; //pick a random integer between 0 and 100
		} //end while
		
		cout << "Excercise " << counter << ": " << number1 << " + " << number2 << " = ";
		cin >> result;

		//judge if the user's answer is correct
		if( result == number1 + number2 )
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCounter++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n" 
			     << setw( 13 ) << " " << "(Key: " << number1 + number2 << ")" << endl;

		totalCounter++;
		number1 = 50, number2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Addition

/* Generate 5 subtraction exercises. */
void Subtraction()
{
	//loop to generate 5 exercises
	for( int counter = 1; counter <= 5; counter++ )
	{		
		//loop to generate 2 proper numbers for an exercise
		while( number1 - number2 < 0 )
		{
			number1 = rand() % 101; //pick a random integer between 0 and 100
			number2 = rand() % 101; //pick a random integer between 0 and 100
		} //end while

		cout << "Excercise " << counter << ": " << number1 << " - " << number2 << " = ";
		cin >> result;

		//judge if the user's answer is correct
		if( result == number1 - number2 )
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCounter++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n"
				 << setw( 13 ) << " " << "(Key: " << number1 - number2 << ")" << endl;

		totalCounter++;
		number1 = 50, number2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Subtraction

/* Generate 5 multiplication exercises. */
void Multiplication()
{
	//loop to generate 5 exercises
	for( int counter = 1; counter <= 5; counter++ )
	{
		//loop to generate 2 proper numbers for an exercise
		while( number1 * number2 > 100 )
		{
			number1 = rand() % 101; //pick a random integer between 0 and 100
			number2 = rand() % 101; //pick a random integer between 0 and 100
		} //end while
		
		cout << "Excercise " << counter << ": " << number1 << " ¡Á " << number2 << " = ";
		cin >> result;

		//judge if the user's answer is correct
		if( result == number1 * number2 )
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCounter++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n"
				 << setw( 13 ) << " " << "(Key: " << number1 * number2 << ")" << endl;

		totalCounter++;
		number1 = 50, number2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Multiplication

/* Generate 5 division exercises. */
void Division()
{
	//loop to generate 5 exercises
	for( int counter = 1; counter <= 5; counter++ )
	{
		//loop to generate 2 proper numbers for an exercise
		while( number1 % number2 != 0 )
		{
			number1 = 1 + rand() % 100; //pick a random integer between 1 and 100
			number2 = 1 + rand() % 100; //pick a random integer between 1 and 100
		} //end while

		cout << "Excercise " << counter << ": " << number1 << " ¡Â " << number2 << " = ";
		cin >> result;

		//judge if the user's answer is correct
		if( result == number1 / number2 )
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCounter++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n"
				 << setw( 13 ) << " " << "(Key: " << number1 / number2 << ")" << endl;

		totalCounter++;
		number1 = 50, number2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Division

/* Output the report. */
void OutputReport()
{
	if( totalCounter == 0 )
		cout << "No accuracy data because no exercise is done." << endl;
	else
	{
		double accuracy = ( double )correctCounter * 100 / totalCounter; //calculate the accuracy after doing some exercises

		cout.setf(ios::fixed);
		cout << "Report:\n"
			 << "  You have finished " << totalCounter << " exercises.\n"
			 << "  " << correctCounter << " of them is/are correctly done.\n"
			 << "  Therefore, your accuracy is " << setprecision(2) << accuracy << "%." << endl;
	} //end if...else
} //end function OutputReport

int main()
{
	char selection = '0';

	srand( time( NULL ) );

	while( ( selection != 'Q' ) || ( selection != 'q' ) )
	{
		cout << "  A: addition\n"
			 << "  B: subtraction\n"
			 << "  C: multiplication\n"
			 << "  D: division\n"
			 << "  Q: quit\n"
			 << "*******************************************************\n"
		 	 //these asterisks are used for a better layout
		     << "Enter your selection (A/B/C/D/Q, the lowercase letter also accepted): ";
		cin >> selection;
		cout << endl;
		
		switch( selection )
		{
		case 'A':
		case 'a':
			Addition(); //call the specified function for 5 addition exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'B':
		case 'b':
			Subtraction(); //call the specified function for 5 subtraction exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'C':
		case 'c':
			Multiplication(); //call the specified function for 5 multiplication exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'D':
		case 'd':
			Division(); //call the specified function for 5 division exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'Q':
		case 'q':
			OutputReport(); //call the specified function to output the report
			system( "Pause" );
			return 0;

		//execute if the user enters one character which is an unspecified one
		default:
			cout << "Error! There is no such selection." << endl;
			system( "Pause" );
			system( "cls" );
		} //end switch-case
	} //end while
} //end main