//2018.01.02, L9.pdf, P43, program that counts how many lines of the content there are in a specified text file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int line = 0;
	string fileName = "test_L9_3.txt", content;
	
	ifstream fileRead( fileName );

	//execute if the file is successfully read
	if( fileRead.is_open() )
	{
		//stop looping when no more characters can be read
		while( getline( fileRead, content ) )
			line++;

		cout << "The number of lines of the content in \"" << fileName << "\": " << line << endl;

		fileRead.close(); //close the file currently associated with the stream to avoid resource leak
	}
	else
		cout << "The file is not successfully read." << endl;
	
	system( "Pause" );
	return 0;
} //end main