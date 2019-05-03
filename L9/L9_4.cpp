// L9.pdf, P48, program that overrides characters from the beginning of a specified text file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileName = "test_L9_4.txt", content;
	fstream file(fileName, ios::in | ios::out);

	// execute if the file is successfully read
	if (file.is_open())
	{
		file << "This i";

		file.seekg(0, ios::beg); // set the position of the pointer back to the beginning

		cout << "The content of \"" << fileName << "\" after overriding:" << endl;

		// stop looping when no more characters can be read
		while (getline(file, content))
			cout << content << endl;

		file.close();
	}
	else
		cout << "The file is not successfully read." << endl;

	system("Pause");
	return 0;
} // end main