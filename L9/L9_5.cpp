// L9.pdf, P53, program that gets the last 3 characters of a specified text file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileName = "test_L9_5.txt", content;
	ifstream fileRead(fileName);

	// execute if the file is successfully read
	if (fileRead.is_open())
	{
		fileRead.seekg(-3, ios::end); // set the position of the pointer to the first of the last 3 characters
		getline(fileRead, content);

		cout << "The last 3 characters of \"" << fileName << "\": " << content << endl;

		fileRead.close();
	}
	else
		cout << "The file is not successfully read." << endl;

	system("Pause");
	return 0;
} // end main