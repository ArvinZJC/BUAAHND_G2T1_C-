//2017.12.15, L3_A.pdf, Assignment 2, parking charge calculator

#include <iostream>
#include <cmath>
using namespace std;

/* Calculate the total parking charge. */
void CalculateTotalCharge( int hourlyCharge, int dailyCharge_max )
{
	int hour, minute;
	double time, x, y, totalCharge;
	
	cout << "Enter hours and minutes parked each separated by a space: ";
	cin >> hour >> minute;
	
	//loop until proper integers are entered for "hour" and "minute"
	while( ( hour == 0 && minute == 0 ) || ( hour < 0) || (minute < 0 ) || ( minute > 60 ) )
	{
		cout << "Error! Please enter again each separated by a space: ";
		cin >> hour >> minute;
	} //end while
	
	//30 < minute ¡Ü 60 is regarded as 60 minutes (1 hour)
	if( minute > 30 )
		time = hour + 1;
	else if( minute == 0 )
		time = hour;
	//30 minutes or part therof (0 excluded) is regarded as 30 minutes (0.5 hour)
	else
		time = hour + 0.5;
	
	x = time / 24;
	/* calculate "time Mod 24" instead of "time % 24" since "time" may be a decimal
	   0 ¡Ü y ¡Ü 23.5 */
	y = time - floor(x) * 24;
	
	//the parking charge is calculated on 2 cases because the daily charge has a max value
	if( ( y >= 16.5 && y <= 23.5 ) || ( y == 0 ) )
		totalCharge = ceil(x) * dailyCharge_max;
	else
		totalCharge = floor(x) * dailyCharge_max + y * hourlyCharge;

	cout << "The parking charge: " << totalCharge << " RMB" << endl;
} //end function CalculateTotalCharge

int main()
{
	char selection = '0';

	while( ( selection != 'Q' ) || ( selection != 'q' ) )
	{
		cout << "  A: oversize vehicle\n"
			 << "  B: compact car\n"
			 << "  Q: quit" << endl;
		cout << "*******************************************************" << endl; //these asterisks are used for a better layout
		cout << "Enter your selection (A/B/Q, the lowercase letter also accepted): ";
		cin >> selection;
		cout << endl;

		switch( selection )
		{
		case 'A':
		case 'a':
			CalculateTotalCharge( 10, 160 ); //call the specified function to calculate the parking charge for an oversize vehicle
			system( "Pause" );
			system( "cls" ); //clear the screen
			break;

		case 'B':
		case 'b':
			CalculateTotalCharge( 5, 80 ); //call the specified function to calculate the parking charge for a compact car
			system( "Pause" );
			system( "cls" );
			break;

		case 'Q':
		case 'q':
			return 0;

		//execute if the user enters one character which is an unspecified one
		default:
			cout << "Error! There is no such selection." << endl;
			system( "Pause" );
			system( "cls" );
		} //end switch-case
	} //end while
} //end main