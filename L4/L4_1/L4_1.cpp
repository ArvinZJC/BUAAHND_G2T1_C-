/* 2017.12.19, tree printing program;
   this program rewritten from L3_A1.cpp uses setw() to help to print spaces */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num; //num is the abbreviation of number

	cout << "Enter an integer between 3 and 10 to print a tree: ";
	cin >> num;

	while( ( num < 3 ) || ( num > 10 ) ) //loop until a proper integer is entered
	{
		cout << "Error! Please enter again: ";
		cin >> num;
	} //end while

	for( int i = 1; i <= num; i++ ) //loop to print the crown of the tree
	{
		cout << setw( num - i + 1 );

		for( int j = 1; j <= i * 2 - 1; j++ )
			cout << "*";

		cout << endl;
	} //end for

	for( int LEN = 1; LEN <= num; ++LEN )
		/* loop to print the trunk of the tree;
		LEN is the abbreviation of length */
		cout << setw( num ) << "*" << endl;

	system( "Pause" );
	return 0;
} //end function main