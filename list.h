#include "header.h"

class List{
	
	public:
		void clear();
		void makePermutes(int numOfHexes, int size);
		void add(vector<int> newPerm);
		void updateCount(int count);
		void updateSize(int size);
		void save();
		int getSize(){ return size;}; // size of the permutations within the list
		int getCount(){ return count;}; // count of # of permutations in list
		int getValue(int listindex, int permindex){ return list[listindex][permindex];};
		vector<int> getPermute(int index){ return list[index];};
		bool search(int index, int item);
	private:
		vector<vector<int> > list;
		int size;
		int count;

};