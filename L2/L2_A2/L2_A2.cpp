//2017.12.12, L2_A.pdf, Assignment 2, number guessing program

#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main()
{
	int number, guess;

	srand( time( NULL ) );
	guess = 23 + rand() % 75; //pick a random integer between 23 and 97
	
	//loop 3 times
	for( int counterForGuessing = 1; counterForGuessing <= 3; counterForGuessing++ )
	{
		cout << "Enter a number between 23 and 97 you guess: ";
		cin >> number;

		if( number != guess )
		{
			//loop to ring the bell
			for( int counterForRinging = 1; counterForRinging <= counterForGuessing; ++counterForRinging )
			{
				cout << "\a";
				
				Sleep( 1000 );
			}
			
			if( number < guess )
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
} //end main