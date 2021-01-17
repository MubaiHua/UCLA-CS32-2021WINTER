#include "Sequence.h"
#include <iostream>

using namespace std;

// Create an empty sequence (i.e., one with no items)
Sequence::Sequence()
{
	m_size = 0;
}

// Return true if the sequence is empty, otherwise false.
bool Sequence::empty() const
{
	if (m_size == 0)
		return true;
	return false;
}

// Return the number of items in the sequence.
int Sequence::size() const
{
	return m_size;
}

// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.
int Sequence::insert(int pos, const ItemType& value)
{
	if (pos<0 || pos>size() || size() >= DEFAULT_MAX_ITEMS)
		return -1;

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

int Sequence::insert(const ItemType& value)
{
	if (m_size >= DEFAULT_MAX_ITEMS)
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

// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
bool Sequence::erase(int pos)
{
	if (pos < 0 || pos >= size())
		return false;
	for (int i = pos; i < size() - 1; i++)
	{
		m_arr[i] = m_arr[i + 1];
	}
	m_size--;
	return true;
}

// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).
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

// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.
bool Sequence::get(int pos, ItemType& value) const
{
	if (pos < 0 || pos >= size())
	{
		return false;
	}
	value = m_arr[pos];
	return true;
}

// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
bool Sequence::set(int pos, ItemType& value)
{
	if (pos < 0 || pos >= size())
	{
		return false;
	}
	m_arr[pos] = value;
	return true;
}

// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
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

// Exchange the contents of this sequence with the other one.
void Sequence::swap(Sequence& other) 
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++) 
	{
		ItemType temp = other.m_arr[i];
		other.m_arr[i] = m_arr[i];
		m_arr[i] = temp;
	}
	
	int temp = other.m_size;
	other.m_size = m_size;
	m_size = temp;
}

void Sequence::dump() const 
{
	for (int i = 0; i < size(); i++) 
	{
		cerr << "Pos "<<i<<": "<<m_arr[i] << ", ";
	}
}
