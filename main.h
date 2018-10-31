#include "list.h"

int numCombos(int digCount){

	int total = 1;
	
	for (int i = 0; i < digCount; ++i){

	total = total * (9 - i);

		}

	return total;

}

long long makeHex(vector<int> nums, int size, int end){

	long long hexNum = end;

	for(int i = 0; i < size - 1; ++i){
		hexNum += static_cast<long long>(nums[i]) * static_cast<long long>(pow(16.0, size - i - 1));
	}

	return (hexNum * 10) / 10;
}

void makePermutes(int numOfHexes, int size, List* current){ // start to make initial list w/ 2 digits

	vector<int> temp;
	long long hex;
	int remainder;
	int counter = 0;

	for(int i = 0; i < numOfHexes; ++i){

		temp.push_back(i);

		for(int j = 0; j < numOfHexes; ++j){

			if(j != i){

				temp.push_back(j);
				hex = makeHex(temp, size, j);
				if(hex % size == 0){
					current->add(temp);
					++counter;

				}
				temp.pop_back();

			}

		}

		temp.clear();

	}

	current->updateSize(size);
	current->updateCount(counter);

}

void nextPermute(List *next, List *current, int size, int numOfHexes){

	int currCount = current->getCount();
	vector<int> temp;
	vector<int> hexes;
	bool found = false;
	long long hex;
	int counter = 0;

	for(int i = 0; i < currCount; ++i){

		for(int j = 0; j < numOfHexes; ++j){

			found = current->search(i, j);

			if(found == false){

				temp = current->getPermute(i);
				temp.push_back(j);

				hex = makeHex(temp, size, j);
				if(hex != 0 && hex % size == 0 && hex > 0){

				hexes.push_back(hex);
					next->add(temp);
					++counter;

				}

				temp.pop_back();
			
				}


		}

		temp.clear();

	}

	current->clear();
	next->updateSize(size);
	next->updateCount(counter);


}

long long vectToVal(long long value, int val){
	return (value * 10) + val; // convert from vector to numerical value
}

void check(List* current, List* next, int h, int i, int length, int* count){

	if(current->search(h, i) == false){ // vector does not contain i

		long long value = 0;
		vector<int> temp = current->getPermute(h);

		for(int g = 0; g < length - 1; ++g){
			value = vectToVal(value, temp[g]); // convert from vector to numerical value
		}

		value = vectToVal(value, i); // accounts for +1 more digit to also add to value

		if(value % length == 0){ // vector with i added divided by length is evenly divisible
			temp.push_back(i); 
			next->add(temp);
			++(*count);

			next->updateCount(*count);
			next->updateSize(length);
			temp.clear();

		}

	}

}

List hexCheck(int size, int desiredSize, List current){

	List temp;
	int counter = 0;

	for(unsigned int i = 0; i < current.getCount(); ++i){

		int isA = 0;
		int isB = 0;
		int isC = 0;
		int isD = 0;
		int isE = 0;
		int isF = 0;

		for(int j = 0; j < size; ++j){

				if(current.getValue(i, j) == 15){
					++isF;
				}

				else if(current.getValue(i, j) == 14){
					++isE;
				}

				else if(current.getValue(i, j) == 13){
					++isD;
				}

				else if(current.getValue(i, j) == 12){
					++isC;
				}

				else if(current.getValue(i, j) == 11){
					++isB;
				}

				else if(current.getValue(i, j) == 10){
					++isA;
				}

			}

			//}
				if(isF == 0 && desiredSize == 15){ // f
					temp.add(current.getPermute(i));
					++counter;
				}

				else if(isE == 0 && isF == 0 && desiredSize == 14){ // e
					temp.add(current.getPermute(i));
					++counter;
				}

				else if(isD == 0 && isE == 0 && isF == 0 && desiredSize == 13){ // d
					temp.add(current.getPermute(i));
					++counter;
				}

				else if(isC == 0 && isD == 0 && isE == 0 && isF == 0 && desiredSize == 12){ // c
					temp.add(current.getPermute(i));
					++counter;
				}

				else if(isB == 0 && isC == 0 && isD == 0 && isE == 0 && isF == 0 && desiredSize == 11){ // b
					temp.add(current.getPermute(i));
					++counter;
				}

			}

	temp.updateCount(counter);
	temp.updateSize(desiredSize);

	return temp;

	temp.clear();

}

void hexAdd(int size, List* current){ // for ex, if for 13, would check if adding a twelfth place is divisible by twelve AND if adding a 13th place is divisible by 13

	List next;
	next.updateSize(size);

	for (int currSize = 12; currSize <= size; ++currSize){

		int counter = 0;

		for(unsigned int i = 0; i < current->getCount(); ++i){

			for(int h = 0; h < size; ++h){

				bool found = true;

				found = current->search(i, h);

				if(found == false){

					vector<int> temp = current->getPermute(i);
					temp.push_back(h);
					long long hex = makeHex(temp, currSize, h);

					if(hex != 0 && hex > 0 && hex % currSize == 0){
						next.add(temp);
						++counter;

					}

					temp.clear();

				}

			}

		}

		next.updateCount(counter);
		(*current) = next;
		next.clear();

	}


}