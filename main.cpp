#include "pch.h"      //comment out if not using VS2017 with precomplied headers
#include <iostream>
#include <Windows.h>
#include "Cell.h"

int main()
{
	system("color A");
	Cell grid[25][25];
	for (int x{ 0 }; x < 25; ++x)
		for (int y{ 0 }; y < 25; ++y)
			grid[x][y].passCoords(x, y);

	std::cout << "How many cells would you like to enter?: ";
	int cellammount;
	std::cin >> cellammount;
	std::cout << "Please enter the x and y coordinates of each cell seperated by a space\n";
	std::cout << "the coordinates must be between 1 and 25\n";
	for (int inputcell{ 0 }; inputcell < cellammount; ++inputcell)
	{
		int input_x, input_y;
		std::cout << "Cell #" << inputcell + 1 << ": ";
		std::cin >> input_x >> input_y;
		grid[input_x-1][input_y-1].changeState();
		for (int y{ 24 }; y > -1; --y)
		{
			for (int x{ 0 }; x < 25; ++x)
				std::cout << grid[x][y];
			std::cout << "\n";
		}
		std::cout << "\n\n\n\n";

	}

	std::cout << "Input finished, begin simulation (y/n)?: ";
	char begin;
	std::cin >> begin;
	if (begin != 'y' && begin != 'Y')
		return 0;


	for (int y{ 24 }; y > -1; --y)
	{
		for (int x{ 0 }; x < 25; ++x)
			std::cout << grid[x][y];
		std::cout << "\n";
	}
	std::cout << "\n\n\n\n";

	int generation{ 0 };
	while (true)
	{

		for (int y{ 24 }; y > -1; --y)
			for (int x{ 0 }; x < 25; ++x)
			{
				grid[x][y].iterateGeneration(grid);
			}
		
		for (int y{ 24 }; y > -1; --y)
			for (int x{ 0 }; x < 25; ++x)
			{
				if (grid[x][y].m_changestate)
					grid[x][y].changeState();
			}
		++generation;
		
		Sleep(500);
		system("cls");
		for (int y{ 24 }; y > -1; --y)
		{
			for (int x{ 0 }; x < 25; ++x)
				std::cout << grid[x][y];
			std::cout << "\n";
		}

		std::cout << "Generation: " << generation;

	}
			
}
