//2017.12.19, program that lists procurement schemes of those 4 fruits
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int tot; //tot is the abbreviation of total
	double MONY; //MONY is the abbreviation of money

	cout << "Apple  Watermelon  Pear  Jujude\n"
		 << "-------------------------------" << endl; //these hyphens are used for a better layout

	for( int apple = 1; apple < 100; apple++ )
		for( int watermelon = 1; watermelon < 100; watermelon++ )
			for( int pear = 1; pear < 100; pear++ )
				for( int jujude = 1; jujude < 100; jujude++ )
				{
					tot = apple + watermelon + pear + jujude;
					MONY = apple * 0.2 + watermelon * 12 + ( double ) jujude / 7 + ( double ) pear / 3;
					
					if( ( tot == 100 ) && ( MONY == 100 ) )
						cout << setw( 5 ) << apple
						     << setw( 12 ) << watermelon
						     << setw( 6 ) << pear
							 << setw( 8 ) << jujude << endl;
				} //end for

	system( "Pause" );
	return 0;
} //end function main