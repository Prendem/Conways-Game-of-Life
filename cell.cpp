#include "pch.h"      //comment out if not using VS2017 with precompiled headers
#include <iostream>
#include "Cell.h"

Cell::Cell() : m_x{ 0 }, m_y{ 0 }, m_alive{ false }, m_changestate{ false }{}

std::ostream& operator<<(std::ostream &out, const Cell &cell)
{
	if (cell.m_alive)
	{
		out << "0 ";
		return out;
	}
	out << ". ";
	return out;
}

void Cell::iterateGeneration(Cell(&array)[25][25])
{
	int livingneighbours{ 0 };
	if (m_x > 0 && array[m_x - 1][m_y].m_alive)
		++livingneighbours;
	if (m_x < 24 && array[m_x + 1][m_y].m_alive)
		++livingneighbours;
	if (m_y > 0 && array[m_x][m_y - 1].m_alive)
		++livingneighbours;
	if (m_y < 24 && array[m_x][m_y + 1].m_alive)
		++livingneighbours;
	if (m_x > 0 && m_y > 0 && array[m_x - 1][m_y - 1].m_alive)
		++livingneighbours;
	if (m_x < 24 && m_y < 24 && array[m_x + 1][m_y + 1].m_alive)
		++livingneighbours;
	if (m_x < 24 && m_y > 0 && array[m_x + 1][m_y - 1].m_alive)
		++livingneighbours;
	if (m_x > 0 && m_y < 24 && array[m_x - 1][m_y + 1].m_alive)
		++livingneighbours;


	if (!m_alive && livingneighbours == 3)
	{
		m_changestate = true;
		return;
	}
	if (m_alive && livingneighbours < 2)
	{
		m_changestate = true;
		return;
	}
	if (m_alive && livingneighbours > 3)
		m_changestate = true;
}

void Cell::changeState()
{
	if (m_alive)
		m_alive = false;
	else
		m_alive = true;
	m_changestate = false;
}

void Cell::passCoords(int x, int y)
{
	m_x = x;
	m_y = y;
}
