#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	Sequence a(5);
	ItemType num = 1;
	a.insert(num);
	num = 2;
	a.insert(num);
	num = 3;
	a.insert(num);
	num = 4;
	a.insert(num);
	num = 5;
	a.insert(num);
	num = 6;
	a.insert(num);

	a.dump();
	cout << endl;

	Sequence b(6);
	num = 10;
	b.insert(num);
	num = 20;
	b.insert(num);
	num = 30;
	b.insert(num);
	num = 40;
	b.insert(num);
	num = 50;
	b.insert(num);
	num = 60;
	b.insert(num);

	b.dump();
	cout << endl;

	a.swap(b);
	a.dump();
	cout << endl;
	b.dump();

	return 0;
}