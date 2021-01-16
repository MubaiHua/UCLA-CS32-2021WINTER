#include "ScoreList.h"
#include <limits>

ScoreList::ScoreList()
{

}
// Create an empty score list.

bool ScoreList::add(unsigned long score)
{
	if (score < 0 || score>100 || size() >= DEFAULT_MAX_ITEMS)
		return false;
	m_sequence.insert(score);
	return true;
}
// If the score is valid (a value from 0 to 100) and the score list
// has room for it, add it to the score list and return true.
// Otherwise, leave the score list unchanged and return false.

bool ScoreList::remove(unsigned long score)
{
	int pos = m_sequence.find(score);
	if (pos == -1)
		return false;
	return m_sequence.erase(pos);
}
// Remove one instance of the specified score from the score list.
// Return true if a score was removed; otherwise false.

int ScoreList::size() const
{
	return m_sequence.size();
}
// Return the number of scores in the list.

unsigned long ScoreList::minimum() const
{
	if (size() <= 0)
		return NO_SCORE;
	unsigned long min;
	unsigned long temp;
	m_sequence.get(0, min);
	for (int i = 0; i < size(); i++)
	{
		m_sequence.get(i, temp);
		if (temp < min)
		{
			min = temp;
		}
	}
	return min;
}
// Return the lowest-valued score in the score list.  If the list is
// empty, return NO_SCORE.

unsigned long ScoreList::maximum() const 
{
	if (size() <= 0)
		return NO_SCORE;
	unsigned long max;
	unsigned long temp;
	m_sequence.get(0, max);
	for (int i = 0; i < size(); i++)
	{
		m_sequence.get(i, temp);
		if (temp > max)
		{
			max = temp;
		}
	}
	return max;
}
// Return the highest-valued score in the score list.  If the list is
// empty, return NO_SCORE.