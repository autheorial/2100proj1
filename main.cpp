#include "main.h"

int main(){

	List current;
	List next;
	vector<int> temp;
	int length = 1;
	int val;
	int compVal;
	int count = 0;

	// hello!
	cout  << endl
	   << "    +-----------------------------------------------------------------+   " << endl
	   << "    |                Computer Science and Engineering                 |   " << endl
	   << "    |               CSCE2100 - Computing Foundations I                |   " << endl
	   << "    |             Alice Zhu  az0144  alicezhu@my.unt.edu              |   " << endl
	   << "    +-----------------------------------------------------------------+   " << endl
	   << endl
	   << "                            N U M E R O L O G Y                           " << endl
	   << endl
	  << "   The following are the number of solutions for x digit numbers" <<
	endl << "   represented by either decimals or hexadecimals, which have  " <<
	endl << "   corresponding values that are evenly divisible by the number of" <<
	endl << "   digits the solution contains, in cascading format." << endl
	<< endl
	<< "   Solutions themselves can be found as exported files." << endl << endl
	<< "   Digits as decimal values: " << endl;

	/****************************************************************************/
	/******************************* DECIMALS ***********************************/
	/****************************************************************************/

	// initialize for 1 digit numbers
	for(int i = 1; i < 10; ++i){
		++count;
		temp.push_back(i);
		current.add(temp);
		current.updateCount(count);
		temp.pop_back();
	}

	current.updateSize(length);

	++length;

	do{ // loop for decimal values

		count = 0; // # of solutions
		int exists = 0;

		for(unsigned int h = 0; h < current.getCount(); ++h){ // num of elements in curr

			if(length == 10){

				for(int i = 0; i < 10; ++i){ // values 0 - 9 for 10 digits
					check(&current, &next, h, i, length, &count);
				}

			}

			else{

				for(int i = 1; i < 10; ++i){ // values 1 - 9
					check(&current, &next, h, i, length, &count);
				}

			}

		}

		current.save();
		current.clear();
		current = next;
		next.clear(); // decimal values cleared
		++length;

	}while(length < 11);

	current.save();
	current.clear(); // decimal values cleared

	/****************************************************************************/
	/***************************** HEXADECIMALS *********************************/
	/****************************************************************************/

	cout << endl << "   Digits as hexadecimals: " << endl;

	int numOfHexes = 16; // start w decimal values (0,9) + A
	int size = 2;
	List eleven; // w 10 (A)
	List twelve; // w 11 (B)
	List thirteen; // w 12 (C)
	List fourteen; // w 13 (D)
	List fifteen; // w 14 (E)
	List sixteen; // w 15 (F)
	long long hex;
	int remainder;
	int counter = 0;

	makePermutes(numOfHexes, size, &current);

	do{ // loop for hexadecimals

		++size;

		if(numOfHexes < 16){ // add next (A-F) value with loop until 15
			++numOfHexes;
		}

		nextPermute(&next, &current, size, numOfHexes); // initialize for new size potentials
		current = next;

		next.clear();

	}while(size < 11);

	sixteen = current;
	sixteen.updateSize(16);

	eleven = hexCheck (11, size, current);
		++size;
	twelve = hexCheck(11, size, current);
		hexAdd(size, &twelve);
		++size;
	thirteen = hexCheck(11, size, current);
		hexAdd(size, &thirteen);
		++size;
	fourteen = hexCheck(11, size, current);
		hexAdd(size, &fourteen);
		++size;
	fifteen = hexCheck(11, size, current);
		hexAdd(size, &fifteen);
		++size;

	hexAdd(size, &sixteen);

	eleven.save();
	twelve.save();
	thirteen.save();
	fourteen.save();
	fifteen.save();
	sixteen.save();
	current.clear();

	eleven.clear();
	twelve.clear();
	thirteen.clear();
	fourteen.clear();
	fifteen.clear();
	sixteen.clear();

	return 0;

	cout << endl;

}