#pragma once

#include<iostream>

namespace TikTakToe
{
	class Map
	{
	public:
		static const int SIZE = 3;

	private:
		char** map;
		char whiteSpace;


	public:
		Map(char whiteSpace = '-');
		Map(const Map* map);
		~Map();

		char GetCell(int row, int column) const;
		char GetWhiteSpace() const;
		void SetCell(int row, int column, char value);
		void PrintPositions() const;

		friend std::ostream& operator<<(std::ostream& os, const Map& m);

	};
}