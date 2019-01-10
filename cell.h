#ifndef CELL_H
#define CELL_H
#include <iostream>

class Cell
{
private:
	int m_x;
	int m_y;
	bool m_alive;
public:
	bool m_changestate;
	Cell();
	friend std::ostream& operator<<(std::ostream &out, const Cell &cell);
	void itterateGeneration(Cell(&array)[25][25]);
	void changeState();
	void passCoords(int x, int y);
};

#endif
