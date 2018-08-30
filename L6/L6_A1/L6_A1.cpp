//2017.12.26, L6_A.pdf, Assignment 1, simplified WeChat Red Packet preparing program
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class WeChatRedPacket
{
	int judgeSEL( char SEL ) //SEL is the abbreviation of select or selection
	{
		switch( SEL )
		{
		case 'Y':
		case 'y':
			return 1;
			break;

		case 'N':
		case 'n':
			return -1;
			break;
			
		default: //execute if the user enters one character which is an unspecified one
			cout << "Error! There is no such selection." << endl;
			return -1;
		} //end switch-case
	} //end function judgeSEL

	void outputRSLT( int people, double USR[] ) //RSLT and USR are respectively the abbreviations of result and user
	{
		cout << "The result:\n"
			 << "User  Money (Unit: RMB)" << endl;
		cout.setf( ios::fixed );

		for (int CNT = 0; CNT < people; CNT++)
		/* loop to print each user's index and money received with a clear layout;
		   CNT is the abbreviation of counter */
		{
			USR[ CNT ] /= 100; //reduce by 100 times to get the actual money received
			
			cout << setw( 4 ) << CNT + 1 << setw( 19 ) << setprecision( 2 ) << USR[ CNT ] << endl;
		} //end for
	} //end function outputRSLT

public:
	int CHKinput( int people, double MONY ) //CHK and MONY are respectively the abbreviations of check and money
	{
		char SEL;
		
		if( ( people >= 1 ) && ( MONY >= people * 0.01 ) ) //check if the input is legal
			return 0;
		else if( people < 1 )
		{
			cout << "\nError! Illegal input for the quantity of people.\n"
				 << "Do you want to enter again? (Y/N)  ";
			cin >> SEL;

			return judgeSEL( SEL ); //call the specified function to determine if the user gives up
		}
		else
		{
			cout << "\nError! Each person should receive at least 0.01 RMB.\n"
				 << "Do you want to enter again? (Y/N)  ";
			cin >> SEL;

			return judgeSEL( SEL ); //call the specified function to determine if the user gives up
		} //end nested if...else
	} //end function CHKinput

	void prepareRedPacket( int people, double MONY )
	{
		double RMNG_MONY = MONY * 100;
		/* the value of "MONY" is increased to 100 times so as to reduce the error of floating-point type;
		   RMNG is the abbreviation of remaining */
		double *USR = new double[ people ];
		//use a pointer to create a dynamic array named USR for storing each user's money received

		for( int CNT = 0; CNT < people; CNT++ )
		{
			USR[ CNT ] = 1; //each person should receive at least 0.01 RMB
			RMNG_MONY -= 1;
		} //end for

		while( RMNG_MONY > 0 ) //loop until there is no remaining money
		{
			USR[ rand() % people ] += 1; //a random user receives another 0.01 RMB
			RMNG_MONY -= 1;
		} //end while

		outputRSLT( people, USR ); //call the specified function to print each user's index and money received

		delete[] USR; //delete the dynamic array to release memory
	} //end function prepareRedPacket
}; //end class WeChatRedPacket

int main()
{
	WeChatRedPacket test; //create a WeChatRedPacket object and assign it to "test"

	int run = 1, people;
	double MONY;

	srand( time( NULL ) );

	while( run == 1 ) //loop until the input is legal (run = 0) or the user gives up (run = -1)
	{
		cout << "Enter the quantity of people snatching red packets: ";
		cin >> people;
		cout << "Enter the total amount of money in red packets (unit: RMB): ";
		cin >> MONY;

		run = test.CHKinput( people, MONY ); //call the specified function in class WeChatRedPacket to check the input

		cout << endl;
	} //end while

	if( run == 0 )
		test.prepareRedPacket( people, MONY ); //call the specified function in class WeChatRedPacket to prepare red packets

	system( "Pause" );
	return 0;
} //end function main