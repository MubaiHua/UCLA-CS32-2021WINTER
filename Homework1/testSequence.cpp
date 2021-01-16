#include "Sequence.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// To test a Sequence of unsigned long, leave the #define line commented out;
// to test a Sequence of string, remove the "//".

//#define TEST_WITH_STRING

#ifdef TEST_WITH_STRING
const ItemType VAL1[3] = { "injera", "lavash", "tortilla" };
const ItemType VAL2[4] = { "bigberg", "middleberg", "smallberg","superberg" };
#else // assume unsigned long
const ItemType VAL1[3] = {10,20,999 };
const ItemType VAL2[4] = {23,118,888,1998 };
#endif

void test()
{
    Sequence s;
    assert(s.size() == 0);
    s.insert(0, VAL1[0]);
    s.insert(1, VAL1[1]);
    assert(s.size() == 2);
    s.insert(VAL1[2]);
    assert(s.size() == 3);
    ItemType i;
    s.get(2, i);
    assert(i == VAL1[2]);
    s.erase(1);
    assert(s.size() == 2);
    s.get(1, i);
    assert(i == VAL1[2]);
    s.insert(1, VAL1[1]);
    s.insert(2, VAL1[1]);
    i = VAL1[1];
    assert(s.remove(i)==2);
    s.set(1, i);
    s.get(1, i);
    assert(i == VAL1[1]);
    s.insert(VAL1[2]);
    s.insert(VAL1[0]);
    i = VAL1[0];
    assert(s.find(i) == 0);
    s.erase(0);

    Sequence t;
    t.insert(VAL2[0]);
    t.insert(VAL2[1]);
    t.insert(VAL2[2]);
    t.insert(VAL2[3]);
    s.swap(t);
    assert(s.size() == 4);
    assert(t.size() == 3);

    //s.dump();
    //cout << endl;
    //t.dump();
    //cout << endl;
}

int main()
{
    test();
    cerr << "Passed all tests" << endl;
}
