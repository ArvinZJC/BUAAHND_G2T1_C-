//2017.12.15, L3_A.pdf, Assignment 1, tree printing program
#include <iostream>
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
		for( int space1 = num - i; space1 >= 1; space1-- )
			cout << " ";
		
		for( int j = 1; j <= i * 2 - 1; j++ )
			cout << "*";

		cout << endl;
	} //end for

	for( int LEN = 1; LEN <= num; ++LEN )
	/* loop to print the trunk of the tree;
	   LEN is the abbreviation of length */
	{
		for( int space2 = 1; space2 <= num - 1; ++space2 )
			cout << " ";

		cout << "*" << endl;
	} //end for

	system( "Pause" );
	return 0;
} //end function main