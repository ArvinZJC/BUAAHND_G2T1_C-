//2017.12.15, L3_A.pdf, Assignment 2, parking charge calculator
#include <iostream>
#include <cmath>
using namespace std;

void calculateTotCRG( int hourlyCRG, int dailyCRG_max )
//tot and CRG are respectively the abbreviations of total and charge
{
	int HH, MM; //HH and MM are respectively the abbreviations of hour and minute
	double TM, x, y, totCRG; //TM is the abbreviation of time
	
	cout << "Enter hours and minutes parked each separated by a space: ";
	cin >> HH >> MM;
	
	while( ( HH == 0 && MM == 0 ) || ( HH < 0) || (MM < 0 ) || ( MM > 60 ) )
	//loop until proper integers are entered for "HH" and "MM"
	{
		cout << "Error! Please enter again each separated by a space: ";
		cin >> HH >> MM;
	} //end while
	
	if( MM > 30 ) //30 < MM ¡Ü 60 is regarded as 60 minutes (1 hour)
		TM = HH + 1;
	else if( MM == 0 )
		TM = HH;
	else //30 minutes or part therof (0 excluded) is regarded as 30 minutes (0.5 hour)
		TM = HH + 0.5;
	
	x = TM / 24;
	y = TM - floor(x) * 24;
	/* calculate "TM Mod 24" instead of "TM % 24" since "TM" may be a decimal;
	   0 ¡Ü y ¡Ü 23.5 */
	
	if( ( y >= 16.5 && y <= 23.5 ) || ( y == 0 ) )
	//the parking charge is calculated on 2 cases because the daily charge has a max value
		totCRG = ceil(x) * dailyCRG_max;
	else
		totCRG = floor(x) * dailyCRG_max + y * hourlyCRG;

	cout << "The parking charge: " << totCRG << " RMB" << endl;
} //end function calculateTotCRG

int main()
{
	char SEL = '0'; //SEL is the abbreviation of selection

	while( ( SEL != 'Q' ) || ( SEL != 'q' ) )
	{
		cout << "  A: oversize vehicle\n"
			 << "  B: compact car\n"
			 << "  Q: quit" << endl;
		cout << "*******************************************************" << endl;
		//these asterisks are used for a better layout
		cout << "Enter your selection (A/B/Q, the lowercase letter also accepted): ";
		cin >> SEL;
		cout << endl;

		switch( SEL )
		{
		case 'A':
		case 'a':
			calculateTotCRG( 10, 160 );
			//call the specified function to calculate the parking charge for an oversize vehicle
			system( "Pause" );
			system( "cls" ); //clear the screen
			break;

		case 'B':
		case 'b':
			calculateTotCRG( 5, 80 ); //call the specified function to calculate the parking charge for a compact car
			system( "Pause" );
			system( "cls" );
			break;

		case 'Q':
		case 'q':
			return 0;

		default: //execute if the user enters one character which is an unspecified one
			cout << "Error! There is no such selection." << endl;
			system( "Pause" );
			system( "cls" );
		} //end switch-case
	} //end while
} //end function main