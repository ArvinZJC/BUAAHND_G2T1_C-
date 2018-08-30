//2018.01.02, L9.pdf, P43, program that counts how many lines of the content there are in a specified text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int LN = 0; //LN is the abbreviation of line
	string fileNM = "test_L9_3.txt", content; //NM is the abbreviation of name
	
	ifstream fileRead( fileNM );

	while( getline( fileRead, content ) ) //stop looping when no more characters can be read
		LN++;

	cout << "The number of lines of the content in \"" << fileNM << "\": " << LN << endl;

	fileRead.close(); //close the file currently associated with the stream to avoid resource leak
	
	system( "Pause" );
	return 0;
} //end function main