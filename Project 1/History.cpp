#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols) 
{
	m_rows = nRows;
	m_cols = nCols;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			m_grid[i][j] = 0;//Set the whole grid to 0		
		}
	}
}

bool History::record(int r, int c) 
{
	if (r > m_rows || c > m_cols || r < 1 || c < 1)
	{
		return false;
	}
	m_grid[r - 1][c - 1]++;
	return true;
}

void History::display() const 
{
	clearScreen(); //clear screen before display
	for (int i = 0; i < m_rows; i++) 
	{
		for (int j = 0; j < m_cols; j++) 
		{
			if (m_grid[i][j] == 0) 
			{
				cout << ".";

			}
			else if (m_grid[i][j] > 0 && m_grid[i][j] < 26) 
			{
				char letter = 'A' + m_grid[i][j] - 1;
				cout << letter;
			}
			else if(m_grid[i][j]>=64)
			{
				cout << 'Z';
			}
		}
		cout << endl;
	}
	cout << endl;
}