//2018.01.02, L9.pdf, P48, program that overrides characters from the beginning of a specified text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileNM = "test_L9_4.txt", content; //NM is the abbreviation of name

	fstream file( fileNM, ios::in | ios::out );

	file << "This i";

	file.seekg( 0, ios::beg ); //set the position of the pointer back to the beginning

	cout << "The content of \"" << fileNM << "\" after overriding:" << endl;
	
	while( getline( file, content ) ) //stop looping when no more characters can be read
		cout << content << endl;

	file.close(); //close the file currently associated with the stream to avoid resource leak

	system( "Pause" );
	return 0;
} //end function main