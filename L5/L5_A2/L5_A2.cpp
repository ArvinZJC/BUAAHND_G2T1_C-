//2017.12.22, L5_A.pdf, Assignment 2, program that finds out the index of the person left in a game
#include <iostream>
using namespace std;

int people;

void indexOfRmngPERS() //Rmng and PERS are respectively the abbreviations of remaining and person
{
	int num = 0, RMNGpeople = people;
	/* "num" is uesd to record the number 1, 2 or 3 counted;
	   num and RMNG are respectively the abbreviations of number and remaining */
	bool *PERS = new bool[ people + 1 ];
	//use a pointer to create a dynamic array named PERS for storing each person's status

	for( int CNT = 1; CNT < people + 1; CNT++ )
	/* loop to initialise each array element with "true";
	   PERS[ 0 ] is not used to make it more convenient to express each person's index;
	   CNT is the abbreviation of counter */
		PERS[ CNT ] = true; //the status "false" represents the person exits

	while( RMNGpeople > 1 ) //loop until there is one remaining person
	{
		for( int CNT = 1; CNT < people + 1; CNT++ ) //loop to find out those who exit
		{
			if( PERS[ CNT ] )
			{
				num++;

				if( num == 3 )
				{
					num = 0;
					PERS[ CNT ] = false;
					RMNGpeople--;
				} //end if
			} //end if
		} //end for
	} //end while

	for( int CNT = 1; CNT < people + 1; CNT++ ) //loop to find out the index of the remaining person
	{
		if( PERS[ CNT ] )
		{
			cout << "The index of the remaining person: " << CNT << endl;
			break;
		} //end if
	} //end for

	delete[] PERS; //delete the dynamic array to release memory
} //end function indexOfRmngPERS

int main()
{
	cout << "Enter an integer no less than 2 for the number of people in a circle: ";
	cin >> people;

	while( people < 2 ) //loop until a proper integer is entered
	{
		cout << "Error! Please enter again: ";
		cin >> people;
	} //end while

	indexOfRmngPERS(); //call the specified function to find out the index of the remaining person

	system( "Pause" );
	return 0;
} //end function main