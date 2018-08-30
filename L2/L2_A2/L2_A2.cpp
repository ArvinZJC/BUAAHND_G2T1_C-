//2017.12.12, L2_A.pdf, Assignment 2, number guessing program
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main()
{
	int num, guess; //num is the abbreviation of number

	srand( time( NULL ) );
	guess = 23 + rand() % 75; //pick a random integer between 23 and 97
	
	for( int guessCNT = 1; guessCNT <= 3; guessCNT++ )
		/* loop 3 times;
		   CNT is the abbreviation of counter */
	{
		cout << "Enter a number between 23 and 97 you guess: ";
		cin >> num;

		if( num != guess )
		{
			for( int bellCNT = 1; bellCNT <= guessCNT; ++bellCNT ) //loop to ring the bell
			{
				cout << "\a";
				
				Sleep( 1000 );
			}
			
			if( num < guess )
				cout << "Sorry! Less than the random integer.\n" << endl;
			else
				cout << "Sorry! Greater than the random integer.\n" << endl;
		}
		else
		{
			cout << "Congratulations! You got it." << endl;

			break;
		} //end if...else
	} //end for

	cout << "The random integer is " << guess << "." << endl;

	system( "Pause" );
	return 0;
} //end fuction main