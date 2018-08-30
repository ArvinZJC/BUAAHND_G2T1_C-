//2017.12.27, L7_A.pdf, Assignment 1, grade analyser
#include <iostream>
#include <regex>
#include <iomanip>
using namespace std;

class analyseGRD //GRD is the abbreviation of grade
{
	void descendingSRT( int CNTofGRD, double GRD[] )
	{
		double tmp; //initialise an intermediate variable

		for( int i = 0; i < CNTofGRD - 1; i++ ) //use Selection Sort to sort from highest to lowest
		{
			for( int j = i + 1; j < CNTofGRD; j++ )
			{
				if( GRD[ i ] < GRD[ j ] ) //change positions if the previous element is less than the latter one
				{
					tmp = GRD[ i ];
					GRD[ i ] = GRD[ j ];
					GRD[ j ] = tmp;
				} //end if
			} //end for
		} //end for

		cout << "Grades from highest to lowest:" << endl;
		
		for( int CNT = 0; CNT < CNTofGRD; CNT++ ) //loop to print each grade from highest to lowest
			cout << GRD[ CNT ] << endl;
	} //end function descendingSRT

	void getAVG( int CNTofGRD, double GRD[] )
	//AVG, CNT and GRD are respectively the abbreviations of average, counter and grade
	{
		double sum = 0, AVG;

		for( int CNT = 0; CNT < CNTofGRD; CNT++ ) //add each array element's value to "sum"
			sum += GRD[ CNT ];

		AVG = sum / CNTofGRD;

		cout.setf( ios::fixed );
		cout << "The average grade (2 decimal places kept): " << setprecision( 2 ) << AVG << endl;
	} //end function getAVG

public:
	int CHKinput( string input ) //CHK is the abbreviation of check
	{
		regex pattern( "\\s*(100|(\\d{1,2}(\\.\\d{1,2})?))(\\s+(100|(\\d{1,2}(\\.\\d)?)))+\\s*" );
		/* allow entering at least 2 integers or numbers with at most 2 decimal places between 0 and 100;
		   allow entering 1 or more spaces between 2 numbers;
		   the input can start with spaces and can also end up with spaces */

		if( regex_match( input, pattern ) ) //check if the input is legal
			return 0;
		else
		{
			cout << "Error! Please enter again:" << endl;

			return 1;
		} //end if...else
	} //end function CHKinput

	void PROCinput( string input ) //PROC is the abbreviation of process
	{
		const char* data = input.data(); //convert the input to an array of type char with constant elements
		int CNTofData = 0, CNTofGRD = 0, LENofData = strlen( data );
		/* strlen() here returns a value of type size_t recording the length of "data" excluding '\0';
		   LEN is the abbreviation of length */
		double GRD[ 100 ]; //declare an array of type double with enough elements to store grades
		string eachGRD; //use for recording a grade

		while( CNTofData < LENofData ) //loop until all characters excluding '\0' are checked
		{
			while( ( data[ CNTofData ] >= '0' && data[ CNTofData ] <= '9' ) || ( data[ CNTofData ] == '.' ) )
				eachGRD += data[ CNTofData++ ];
			
			if( eachGRD != "" )
			{
				GRD[ CNTofGRD++ ] = stod( eachGRD ); //convert "eachGRD" to an element of the array of type double
				eachGRD = ""; //initialise "eachGRD" to NULL
			}
			else
				CNTofData++;
		} //end while
		
		cout << "The number of grades entered: " << CNTofGRD << endl;

		descendingSRT( CNTofGRD, GRD ); //call the specified function to sort grades in a descending order
		getAVG( CNTofGRD, GRD ); //call the specified function to calculate the average grade
	} //end function PROCinput
}; //end class analyseGRD

int main()
{
	analyseGRD test; //create an analyseGRD object and assign it to "test"

	int run = 1;
	string input;

	cout << "Enter at least 2 grades separated by spaces:" << endl;

	while( run ) //loop until the input is legal (run = 0)
	{
		getline( cin, input );
		run = test.CHKinput( input ); //call the specified function in class analyseGRD to check the input
	} //end while

	cout << endl;

	test.PROCinput( input ); //call the specified function in class analyseGRD to process the input

	system( "Pause" );
	return 0;
} //end function main