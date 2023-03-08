#include "Game.h"

namespace TikTakToe
{

	Game::Game(Players::PlayerBase* player1, Players::PlayerBase* player2, char defaultMapSymbol)
	{
		map = new Map(defaultMapSymbol);
		this->player1 = player1;
		this->player2 = player2;
		player1Turn = true;
		this->defaultMapSymbol = defaultMapSymbol;
	}
	Game::~Game()
	{
		delete map;
	}

	void Game::NextStep()
	{
		char symbol = player1Turn ? player1->GetSymbol() : player2->GetSymbol();
		int pos = player1Turn ? player1->TakeAction(map) : player2->TakeAction(map);

		if (pos < 0 || pos > 8)
			return;

		char cell = map->GetCell(pos / Map::SIZE, pos % Map::SIZE);
		if (cell == defaultMapSymbol)
		{
			map->SetCell(pos / Map::SIZE, pos % Map::SIZE, symbol);
			player1Turn = !player1Turn;
		}
	}
	bool Game::IsGameEnded(char& winner)
	{
		for (int i = 0; i < Map::SIZE; i++)
		{
			if (map->GetCell(0, i) == map->GetCell(1, i) && map->GetCell(1, i) == map->GetCell(2, i) && map->GetCell(0, i) != defaultMapSymbol)
			{
				winner = map->GetCell(0, i);
				return true;
			}
			if (map->GetCell(i, 0) == map->GetCell(i, 1) && map->GetCell(i, 1) == map->GetCell(i, 2) && map->GetCell(i, 2) != defaultMapSymbol)
			{
				winner = map->GetCell(i, 0);
				return true;
			}
		}

		if (map->GetCell(0, 0) == map->GetCell(1, 1) && map->GetCell(1, 1) == map->GetCell(2, 2) && map->GetCell(2, 2) != defaultMapSymbol)
		{
			winner = map->GetCell(1, 1);
			return true;
		}

		if (map->GetCell(2, 0) == map->GetCell(1, 1) && map->GetCell(1, 1) == map->GetCell(0, 2) && map->GetCell(0, 2) != defaultMapSymbol)
		{
			winner = map->GetCell(1, 1);
			return true;
		}

		for (int i = 0; i < Map::SIZE; i++)
			for (int j = 0; j < Map::SIZE; j++)
				if (map->GetCell(i, j) == map->GetWhiteSpace())
				{
					winner = defaultMapSymbol;
					return false;
				}

		winner = defaultMapSymbol;
		return true;
	}

	void Game::PrintMap()
	{
		system("cls");
		std::cout << *map << std::endl;
	}
}