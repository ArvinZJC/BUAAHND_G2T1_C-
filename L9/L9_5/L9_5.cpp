//2018.01.02, L9.pdf, P53, program that gets the last 3 characters of a specified text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileNM = "test_L9_5.txt", content; //NM is the abbreviation of name

	ifstream fileRead( fileNM );

	fileRead.seekg( -3, ios::end ); //set the position of the pointer to the first of the last 3 characters

	getline( fileRead, content );
	cout << "The last 3 characters of \"" << fileNM << "\": " << content << endl;

	fileRead.close(); //close the file currently associated with the stream to avoid resource leak

	system( "Pause" );
	return 0;
} //end function main