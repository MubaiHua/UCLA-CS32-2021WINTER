#include "newSequence.h"
#include <iostream>

using namespace std;

Sequence::Sequence()
{
	m_size = 0;
	m_maxSize = DEFAULT_MAX_ITEMS;
	m_arr = new ItemType[m_maxSize];
}
// Create an empty sequence (i.e., one with no items)

Sequence::~Sequence()
{
	delete[]m_arr;
}
//Destructor for Object Sequence

Sequence::Sequence(int num)
{
	m_size = 0;
	m_maxSize = num;
	m_arr = new ItemType[m_maxSize];
}
//Non-default constructor that takes the parameter num

Sequence& Sequence::operator= (const Sequence& other)
{
	if (&other == this)
		return *this;
	delete[]m_arr;
	m_size = other.m_size;
	m_maxSize = other.m_maxSize;
	m_arr = new ItemType[m_maxSize];
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = other.m_arr[i];
	}
	return *this;
}
//Assignment operator

Sequence::Sequence(const Sequence& other)
{
	m_size = other.m_size;
	m_maxSize = other.m_maxSize;
	m_arr = new ItemType[m_maxSize];
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = other.m_arr[i];
	}
}
//Copy Constructor;

bool Sequence::empty() const
{
	if (m_size == 0)
		return true;
	return false;
}
// Return true if the sequence is empty, otherwise false.

int Sequence::size() const
{
	return m_size;
}
// Return the number of items in the sequence.

int Sequence::insert(int pos, const ItemType& value)
{
	if (pos<0 || pos>size() || size() >= m_maxSize)
		return -1;

	m_size++;
	for (int i = size() - 1; i > pos; i--)
	{
		m_arr[i] = m_arr[i - 1];
	}
	m_arr[pos] = value;
	return pos;
}
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.

int Sequence::insert(const ItemType& value)
{
	if (m_size >= m_maxSize)
		return -1;
	int pos = 0;
	while (pos<size() && value > m_arr[pos])
	{
		pos++;
	}
	m_size++;
	for (int i = size() - 1; i > pos; i--)
	{
		m_arr[i] = m_arr[i - 1];
	}
	m_arr[pos] = value;
	return pos;
}
// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item at position p and those that follow it end
// up at positions one higher than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).

bool Sequence::erase(int pos)
{
	if (pos < 0 || pos >= size())
		return false;
	for (int i = pos; i < size() - 1; i++)
	{
		m_arr[pos] = m_arr[pos + 1];
	}
	m_size--;
	return true;
}
// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.

int Sequence::remove(const ItemType& value)
{
	int count = 0;
	for (int i = 0; i < size(); i++)
	{
		if (m_arr[i] == value)
		{
			for (int j = i; j < size() - 1; j++)
			{
				m_arr[j] = m_arr[j + 1];
			}
			m_size--;
			count++;
			i--;
		}
	}
	return count;
}
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).

bool Sequence::get(int pos, ItemType& value) const
{
	if (pos < 0 || pos >= size())
	{
		return false;
	}
	value = m_arr[pos];
	return true;
}
// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.

bool Sequence::set(int pos, ItemType& value)
{
	if (pos < 0 || pos >= size())
	{
		return false;
	}
	m_arr[pos] = value;
	return true;
}
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.

int Sequence::find(const ItemType& value) const
{
	for (int i = 0; i < size(); i++)
	{
		if (value == m_arr[i])
		{
			return i;
		}
	}
	return -1;
}
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.

void Sequence::swap(Sequence& other)
{
	ItemType* temp = other.m_arr;
	other.m_arr = m_arr;
	m_arr = temp;

	int tempSize = m_size;
	m_size = other.m_size;
	other.m_size = tempSize;

	int tempMaxSize = m_maxSize;
	m_maxSize = other.m_maxSize;
	other.m_maxSize = tempMaxSize;
}
// Exchange the contents of this sequence with the other one.

void Sequence::dump() const
{
	for (int i = 0; i < size(); i++)
	{
		cerr << "Pos " << i << ": " << m_arr[i] << ", ";
	}
}
//Print the sequence