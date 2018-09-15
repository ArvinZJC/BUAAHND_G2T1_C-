//2018.09.05, 《21天学通C++（第7版）》, P110, program that calculates the area of the specified circle with pointers

#include <iostream>
using namespace std;

void CalculateCircleArea( const double* const pPi, //const pointer to const data (nothing can be changed)
						  const double* const pRadius, //const pointer to const data (nothing can be changed)
						  double* const pArea ) //change pointed value, but not address
{
	//check pointers before using
	if( pPi && pRadius && pArea )
		*pArea = (*pPi) * (*pRadius) * (*pRadius);
} //end function CalculateCircleArea

int main()
{
	const double pi = 3.1416;
	double radius = 0, area = 0;

	cout << "Enter radius of the circle: ";
	cin >> radius;

	CalculateCircleArea(&pi, &radius, &area); //call the specified function to calculate the area of the specified circle

	cout << "The area of the specified circle: " << area << endl;

	system( "Pause" );
	return 0;
} //end main