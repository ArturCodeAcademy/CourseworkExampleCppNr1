#include "RandomPlayer.h"

namespace TikTakToe
{
	int Players::RandomPlayer::TakeAction(const Map* const map)
	{
		int row, column;
		do
		{
			row = rand() % Map::SIZE;
			column = rand() % Map::SIZE;
		} while (map->GetCell(row, column) != map->GetWhiteSpace());
		if (vaitAfterStep)
			system("pause");
		return row * Map::SIZE + column;
	}
}