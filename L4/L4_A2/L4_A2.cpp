//2017.12.19, L4_A.pdf, Assignment 2, arithmetic learning program for primary students
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int num1 = 50, num2 = 51, RSLT, totCNT = 0, correctCNT = 0;
/* declare global variables and initialise most of them;
   num, RSLT, tot and CNT are respectively the abbreviations of number, result, total and counter */

void Add() //Add is the abbreviation of addition
{
	for( int CNT = 1; CNT <= 5; CNT++ )
	{		
		while( num1 + num2 > 100 ) //loop to generate 2 proper numbers for an exercise
		{
			num1 = rand() % 101; //pick a random integer between 0 and 100
			num2 = rand() % 101; //pick a random integer between 0 and 100
		} //end while
		
		cout << "Excercise " << CNT << ": " << num1 << " + " << num2 << " = ";
		cin >> RSLT;

		if( RSLT == num1 + num2 ) //judge if the user's answer is correct
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCNT++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n" 
			     << setw( 13 ) << " " << "(Key: " << num1 + num2 << ")" << endl;

		totCNT++;
		num1 = 50, num2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Add

void Sub() //Sub is the abbreviation of subtraction
{
	for( int CNT = 1; CNT <= 5; CNT++ ) //loop to generate 5 exercises
	{		
		while( num1 - num2 < 0 ) //loop to generate 2 proper numbers for an exercise
		{
			num1 = rand() % 101; //pick a random integer between 0 and 100
			num2 = rand() % 101; //pick a random integer between 0 and 100
		} //end while

		cout << "Excercise " << CNT << ": " << num1 << " - " << num2 << " = ";
		cin >> RSLT;

		if( RSLT == num1 - num2 ) //judge if the user's answer is correct
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCNT++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n"
				 << setw( 13 ) << " " << "(Key: " << num1 - num2 << ")" << endl;

		totCNT++;
		num1 = 50, num2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Sub

void Mul() //Mul is the abbreviation of multiplication
{
	for( int CNT = 1; CNT <= 5; CNT++ ) //loop to generate 5 exercises
	{
		while( num1 * num2 > 100 ) //loop to generate 2 proper numbers for an exercise
		{
			num1 = rand() % 101; //pick a random integer between 0 and 100
			num2 = rand() % 101; //pick a random integer between 0 and 100
		} //end while
		
		cout << "Excercise " << CNT << ": " << num1 << " ¡Á " << num2 << " = ";
		cin >> RSLT;

		if( RSLT == num1 * num2 ) //judge if the user's answer is correct
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCNT++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n"
				 << setw( 13 ) << " " << "(Key: " << num1 * num2 << ")" << endl;

		totCNT++;
		num1 = 50, num2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Mul

void Div() //Div is the abbreviation of division
{
	for( int CNT = 1; CNT <= 5; CNT++ ) //loop to generate 5 exercises
	{
		while( num1 % num2 != 0 ) //loop to generate 2 proper numbers for an exercise
		{
			num1 = 1 + rand() % 100; //pick a random integer between 1 and 100
			num2 = 1 + rand() % 100; //pick a random integer between 1 and 100
		} //end while

		cout << "Excercise " << CNT << ": " << num1 << " ¡Â " << num2 << " = ";
		cin >> RSLT;

		if( RSLT == num1 / num2 ) //judge if the user's answer is correct
		{
			cout << setw( 23 ) << "Brilliant!" << endl;

			correctCNT++;
		}
		else
			cout << setw( 29 ) << "Wrong! Come on!\n"
				 << setw( 13 ) << " " << "(Key: " << num1 / num2 << ")" << endl;

		totCNT++;
		num1 = 50, num2 = 51; //initialise to ensure a proper generation of the next exercise
	} //end for
} //end function Div

void outputReport()
{
	if( totCNT == 0 )
		cout << "No accuracy data because no exercise is done." << endl;
	else
	{
		double accuracy = ( double )correctCNT * 100 / totCNT;
		//calculate the accuracy after doing some exercises

		cout.setf(ios::fixed);
		cout << "Report:\n"
			 << "  You have finished " << totCNT << " exercises.\n"
			 << "  " << correctCNT << " of them is/are correctly done.\n"
			 << "  Therefore, your accuracy is " << setprecision(2) << accuracy << "%." << endl;
	} //end if...else
} //end function outputReport

int main()
{
	char SEL = '0'; //SEL is the abbreviation of selection

	srand( time( NULL ) );

	while( ( SEL != 'Q' ) || ( SEL != 'q' ) )
	{
		cout << "  A: addition\n"
			 << "  B: subtraction\n"
			 << "  C: multiplication\n"
			 << "  D: division\n"
			 << "  Q: quit\n"
			 << "*******************************************************\n"
		 	 //these asterisks are used for a better layout
		     << "Enter your selection (A/B/C/D/Q, the lowercase letter also accepted): ";
		cin >> SEL;
		cout << endl;
		
		switch( SEL )
		{
		case 'A':
		case 'a':
			Add(); //call the specified function for 5 addition exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'B':
		case 'b':
			Sub(); //call the specified function for 5 subtraction exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'C':
		case 'c':
			Mul(); //call the specified function for 5 multiplication exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'D':
		case 'd':
			Div(); //call the specified function for 5 division exercises
			system( "Pause" );
			system( "cls" );
			break;

		case 'Q':
		case 'q':
			outputReport();
			system( "Pause" );
			return 0;

		default: //execute if the user enters one character which is an unspecified one
			cout << "Error! There is no such selection." << endl;
			system( "Pause" );
			system( "cls" );
		} //end switch-case
	} //end while
} //end function main