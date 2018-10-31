#include "list.h"

void List::clear(){ // remove all permutations

	list.clear();

}

void List::add(vector<int> newPerm){
	list.push_back(newPerm);
}

void List::updateCount(int count){
	this->count = count;
}

void List::updateSize(int size){
	this->size = size;
}

void List::save(){

	ofstream ofs;
	stringstream ss;
	ss << size;
	string sizeStr(ss.str());

	string filename = sizeStr + " digits.txt";

	ofs.open(filename.c_str());

	if(!ofs){
		cout << "An error occurred." << endl;
	}

	else{

		cout << "      " << size << " digits: " << count << endl;
		ofs << size << " digit permutations: (" << count << ")" << endl;

		for(long int i = 0; i < count; ++i){

			vector<int> temp = list[i];

			for(long int j = 0; j < temp.size(); ++j){

				if(temp[j] > 9){
				ofs << static_cast<char>(temp[j] + 55);
				}

				else{
					ofs << temp[j];
				}
				
			}

			ofs << endl;
			temp.clear();

		}

	}

	ofs.close();
	return;



}


bool List::search(int index, int item){

	int counter = 0;
	vector<int> temp;

	temp = list[index];

	for(long int i = 0; i < temp.size(); ++i){

		if(temp[i] == item){
			++counter;
		}

	}

	if(counter == 0){
		return false;
	}
	else{
		return true;
	}

	temp.clear();


}