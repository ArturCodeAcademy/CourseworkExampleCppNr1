#include "Map.h"
#include<iostream>

namespace TikTakToe
{
	Map::Map(char whiteSpace)
	{
		this->whiteSpace = whiteSpace;
		map = new char* [SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			map[i] = new char[SIZE];
			for (int j = 0; j < SIZE; j++)
				map[i][j] = whiteSpace;
		}

	}
	Map::Map(const Map* map) : Map(map->whiteSpace)
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				this->map[i][j] = map->map[i][j];
	}
	Map::~Map()
	{
		for (int i = 0; i < SIZE; i++)
			delete[] map[i];
		delete[] map;
	}

	char Map::GetCell(int row, int column) const
	{
		return map[row][column];
	}
	char Map::GetWhiteSpace() const
	{
		return whiteSpace;
	}
	void Map::SetCell(int row, int column, char value)
	{
		map[row][column] = value;
	}
	void Map::PrintPositions() const
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				std::cout << i * SIZE + j;
			std::cout << std::endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Map& m)
	{
		for (int i = 0; i < Map::SIZE; i++)
		{
			for (int j = 0; j < Map::SIZE; j++)
				os << m.map[i][j];
			os << std::endl;
		}
		return os;
	}
}