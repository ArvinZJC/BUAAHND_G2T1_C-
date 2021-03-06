// L7_A.pdf, Assignment 1, grade analyser

#include <iostream>
#include <regex>
#include <iomanip>
using namespace std;

/* This class contains functions for analysing grades. */
class AnalyseGrades
{
	/* Sort grades in a descending order. */
	void DescendingSort(int countForGrades, double grade[])
	{
		double temp; // initialise an intermediate variable

		// use selection sort to sort from highest to lowest
		for (int i = 0; i < countForGrades - 1; i++)
		{
			for (int j = i + 1; j < countForGrades; j++)
			{
				// change positions if the previous element is less than the latter one
				if (grade[i] < grade[j])
				{
					temp = grade[i];
					grade[i] = grade[j];
					grade[j] = temp;
				} // end if
			} // end for
		} // end for

		cout << "Grades from highest to lowest:" << endl;
		
		// loop to print each grade from highest to lowest
		for (int count = 0; count < countForGrades; count++)
			cout << grade[count] << endl;
	} // end function DescendingSort

	/* Calculate the average grade. */
	void getAverage(int countForGrades, double grade[])
	{
		double sum = 0, average;

		// add each array element's value to "sum"
		for (int count = 0; count < countForGrades; count++)
			sum += grade[count];

		average = sum / countForGrades;

		cout.setf(ios::fixed);
		cout << "The average grade (2 decimal places kept): " << setprecision(2) << average << endl;
	} // end function getAverage

public:
	/* Check the input. */
	int CheckInput(string input)
	{
		/* allow entering at least 2 integers or numbers with at most 2 decimal places between 0 and 100;
		   allow entering 1 or more spaces between 2 numbers;
		   the input can start with spaces and can also end up with spaces */
		regex pattern("\\s*(100|(\\d{1,2}(\\.\\d{1,2})?))(\\s+(100|(\\d{1,2}(\\.\\d)?)))+\\s*");

		// check if the input is legal
		if (regex_match(input, pattern))
			return 0;
		else
		{
			cout << "Error! Please enter again:" << endl;

			return 1;
		} // end if...else
	} // end function CheckInput

	/* Process the input. */
	void ProcessInput(string input)
	{
		const char* data = input.data(); // convert the input to an array of type char with constant elements
		int countForData = 0, countForGrades = 0, lengthOfData = strlen(data); //function strlen here returns a value of type size_t recording the length of "data" excluding '\0'
		double grade[100]; // declare an array of type double with enough elements to store grades
		string eachGrade; // use for recording a grade

		// loop until all characters excluding '\0' are checked
		while (countForData < lengthOfData)
		{
			while ((data[countForData] >= '0' && data[countForData] <= '9' ) || data[countForData] == '.')
				eachGrade += data[countForData++];
			
			if (eachGrade != "")
			{
				grade[countForGrades++] = stod(eachGrade); // convert "eachGrade" to an element of the array of type double
				eachGrade = ""; // initialise "eachGrade" to NULL
			}
			else
				countForData++;
		} // end while
		
		cout << "The number of grades entered: " << countForGrades << endl;

		DescendingSort(countForGrades, grade); // call the specified function to sort grades in a descending order
		getAverage(countForGrades, grade); // call the specified function to calculate the average grade
	} // end function ProcessInput
}; // end class AnalyseGrades

int main()
{
	AnalyseGrades test; // create an AnalyseGrades object and assign it to "test"
	int run = 1;
	string input;

	cout << "Enter at least 2 grades separated by spaces:" << endl;

	// loop until the input is legal (run = 0)
	while (run)
	{
		getline(cin, input);
		run = test.CheckInput(input); // call the specified function in class AnalyseGrades to check the input
	} // vend while

	cout << endl;

	test.ProcessInput(input); // call the specified function in class AnalyseGrades to process the input
	
	return 0;
} // end main