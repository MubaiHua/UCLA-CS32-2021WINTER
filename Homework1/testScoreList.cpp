#include "ScoreList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() 
{
	ScoreList list;
	assert(list.add(10));
	assert(list.add(90));
	assert(list.add(100));
	assert(list.add(0));
	assert(list.add(30));
	assert(!list.add(101));
	assert(!list.add(-1));
	assert(list.size() == 5);
	assert(list.minimum()==0);
	assert(list.maximum() == 100);

	cout << "Passed all tests" << endl;

	return 0;
}